#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{

   if (argc != 2)
   {
      printf("Numero argomenti sbagliato\n");
      exit(1);
   }

   int fd, nread;
   char buff;

   fd = open(argv[1], O_RDONLY);
   while (nread = read(fd, &buff, sizeof(buff)) > 0)
   {
      write(1, &buff, nread);
   }
   close(fd);

   return 0;
}
