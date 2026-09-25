#include <stdio.h>
#include <sys/utsname.h>
#include <time.h>

#define OUTPUT_FILE 1

enum mistakes { WRITE_FILE = 1 };

/**
 * Prints system information to the specified output stream
 * Parameters:
 * 	File *output: output stream for the information
 */
void print_info(FILE* output);

int main(int argc, char* argv[]) {
  // If no filename is specified, print information to the standart output
  if (argc == 1) {
    print_info(stdout);
    return 0;
  }

  // Try to open the specified file to check whether it already exists
  FILE* file = fopen(argv[OUTPUT_FILE], "r");
  if (file != NULL) {
    fclose(file);
    printf("File exists, the output will be written to the end of %s\n",
           argv[OUTPUT_FILE]);
  }

  // Open the file in append mode. If it doesn`t exist, create it.
  file = fopen(argv[OUTPUT_FILE], "a");
  if (file == NULL) {
    printf("Can`t open/create the file. Exiting...\n");
    return WRITE_FILE;
  }

  // Write system information to the specified file
  print_info(file);
  fclose(file);

  return 0;
}

void print_info(FILE* output) {
  struct utsname sys_info;
  time_t current_time;

  uname(&sys_info);
  time(&current_time);

  // Print the collected information to the specified output
  fprintf(output, "Hostname: %s\n", sys_info.nodename);
  fprintf(output, "Operating system: %s\n", sys_info.sysname);
  fprintf(output, "Hardware platform: %s\n", sys_info.machine);
  fprintf(output, "Current time: %s\n", ctime(&current_time));
}
