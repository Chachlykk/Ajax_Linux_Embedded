#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <termios.h>
#include <unistd.h>
#include "logger.h"
#include "tty_settings.h"

volatile sig_atomic_t stop = 0;

void handle_signal(int sig) {
  (void)sig;
  stop = 1;
}

int main(int argc, char* argv[]) {
  struct sigaction sa = {0};
  sa.sa_handler = handle_signal;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;

  sigaction(SIGINT, &sa, NULL);
  sigaction(SIGTERM, &sa, NULL);

  FILE* log_file = create_log();

  char* tty_name = argv[1];

  struct termios tty;
  int fd = open(tty_name, O_RDWR | O_NOCTTY);
  if (fd == -1) {
    perror("open");
    return 1;
  }

  if (tcgetattr(fd, &tty) == -1) {
    perror("tcgetattr");
    return 1;
  }
  setup_tty(fd, &tty);

  print_info(&tty);

  uart_comunication(fd, log_file);

  // printf("END\n");
  close(fd);
  fclose(log_file);
  return 0;
}
