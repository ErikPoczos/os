#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(2, "Invalid argument. Exiting...");
    exit(1);
  }

  int sleepDuration = atoi(argv[1]);

  sleep(sleepDuration);

  exit(0);
}
