#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

void log_message(FILE* log, const char* message, size_t len);

FILE* create_log();

#endif  // LOGGER_H
