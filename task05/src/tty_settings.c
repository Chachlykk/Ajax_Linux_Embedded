#include "tty_settings.h"
#include <ctype.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#define BUFFER_SIZE 256

static void print_data_bits(struct termios* tty) {
  printf("Data bits:");
  switch (tty->c_cflag & CSIZE) {
    case CS5:
      printf("5\n");
      break;
    case CS6:
      printf("6\n");
      break;
    case CS7:
      printf("7\n");
      break;
    case CS8:
      printf("8\n");
      break;
    default:
      printf("Unknown\n");
      break;
  }
}

static unsigned int baud_to_int(speed_t speed) {
  switch (speed) {
    case B9600:
      return 9600;
    case B19200:
      return 19200;
    case B38400:
      return 38400;
    case B115200:
      return 115200;
    default:
      return 0;
  }
}
void setup_tty(int fd, struct termios* tty) {
  tty->c_cc[VMIN] = 1;
  tty->c_cc[VTIME] = 0;

  if (tcsetattr(fd, TCSANOW, tty) == -1) {
    perror("tcsetattr");
  }
}

void print_info(struct termios* tty) {
  printf("Input speed: %u baud\n", baud_to_int(cfgetispeed(tty)));
  printf("Output speed: %u baud\n", baud_to_int(cfgetospeed(tty)));
  print_data_bits(tty);

  printf("Parity: ");
  if (!(tty->c_cflag & PARENB)) {
    printf("None\n");
  } else if (tty->c_cflag & PARODD) {
    printf("Odd\n");
  } else {
    printf("Even\n");
  }

  printf("Stop bits: %s\n", (tty->c_cflag & CSTOPB) ? "2" : "1");
}

static void change_register(char* buffer, size_t pos) {
  for (size_t i = 0; i < pos; i++) {
    unsigned char ch = (unsigned char)buffer[i];
    if (ch >= 'a' && ch <= 'z') {
      buffer[i] = (char)(ch - 'a' + 'A');
    } else if (ch >= 'A' && ch <= 'Z') {
      buffer[i] = (char)(ch - 'A' + 'a');
    }
  }
}

static void send_answer(int fd, char* buffer, size_t pos) {
  change_register(buffer, pos);
  size_t sent = 0;
  while (sent < pos) {
    ssize_t written = write(fd, buffer + sent, pos - sent);
    if (written < 0) {
      if (errno == EINTR)
        continue;
      perror("write");
      return;
    }
    sent += (size_t)written;
  }
}

void uart_comunication(int fd) {
  char buffer[BUFFER_SIZE];
  size_t pos = 0;
  char ch;
  uint8_t is_r = 0;  // start of end of line symbol
  while (1) {
    ssize_t n = read(fd, &ch, 1);
    if (n <= 0) {
      perror("read");
      continue;
    }

    if (pos < BUFFER_SIZE - 1) {
      buffer[pos++] = ch;
    } else {
      send_answer(fd, buffer, pos);
      pos = 0;
    }
    // check end of line
    if (is_r && ch == '\n') {
      send_answer(fd, buffer, pos);
      pos = 0;
    }
    if (ch == '\r') {
      is_r = 1;
    } else {
      is_r = 0;
    }
  }
}
