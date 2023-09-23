#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    int p[2], pid;
    char data[] = "d", buffer[2];

    pipe(p);
    pid = fork();

    if(pid == 0) {
        if(read(p[0], &buffer, 1) > 0) 
            printf("%d: received ping\n", getpid());

        write(p[1], &data, 1);
        exit(0);

    } else {
        write(p[1], &data, 1);

        wait(0);
        if(read(p[0], &buffer, 1) > 0)
            printf("%d: received pong\n", getpid());

        close(p[0]);
        close(p[1]);
    }
    exit(0);
}
