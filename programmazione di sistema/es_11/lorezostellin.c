#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }
  int p1p2[2];
    int pid;

    pipe(p1p2);

    pid = fork();
    if (pid == 0)
    {
      
    }