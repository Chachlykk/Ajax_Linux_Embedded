#ifndef TTY_SETTINGS_H
#define TTY_SETTINGS_H

#include <stdio.h>
#include <termios.h>

void print_info(struct termios* tty);

void uart_comunication(int fd, FILE* log_file);

void setup_tty(int fd, struct termios* tty);

#endif  // TTY_SETTINGS_H
