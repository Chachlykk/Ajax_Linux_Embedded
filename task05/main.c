#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <termios.h>
#include <unistd.h>
#include "tty_settings.h"

int main(int argc, char* argv[]) {
  char* tty_name = argv[1];

  struct termios tty;

  int fd = open(tty_name, O_WRONLY | O_NOCTTY);
  if (fd == -1) {
    perror("open");
    return 1;
  }

  if (tcgetattr(fd, &tty) == -1) {
    perror("tcgetattr");
    return 1;
  }
  print_info(&tty);

  uart_comunication(fd);

  close(fd);
  return 0;
}
