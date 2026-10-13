#include "tty_settings.h"
#include <stdio.h>
#include <termios.h>

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

void uart_comunication(int fd) {}
