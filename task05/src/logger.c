#include "logger.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

#define FILENAME_BUFFER 64

static void get_timestamp(char* buffer, size_t size) {
  struct timespec ts;
  struct tm tm_info;

  clock_gettime(CLOCK_REALTIME, &ts);
  localtime_r(&ts.tv_sec, &tm_info);

  strftime(buffer, size, "%Y-%m-%d %H:%M:%S", &tm_info);

  size_t len = strlen(buffer);
  snprintf(buffer + len, size - len, ".%03ld", ts.tv_nsec / 1000000);
}
void log_message(FILE* log, const char* message, size_t len) {
  char timestamp[32];
  get_timestamp(timestamp, sizeof(timestamp));

  fprintf(log, "%s Received: ", timestamp);

  while (len > 0 && (message[len - 1] == '\r' || message[len - 1] == '\n')) {
    len--;
  }

  fwrite(message, 1, len, log);
  fputc('\n', log);
  fflush(log);
}

FILE* create_log() {
  time_t now = time(NULL);
  struct tm tm_info;
  char filename[FILENAME_BUFFER];

  localtime_r(&now, &tm_info);
  if (mkdir("logs", 0755) == -1 && errno != EEXIST) {
    perror("mkdir");
  }

  strftime(filename, FILENAME_BUFFER, "logs/uart_%Y%m%d_%H%M%S.log", &tm_info);

  FILE* log = fopen(filename, "a");

  if (log == NULL) {
    perror("fopen");
    return NULL;
  }
  return log;
}
