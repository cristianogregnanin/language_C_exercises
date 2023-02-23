#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
  if (argc != 2)
  {
    printf("Il numero di argomenti non è corretto \n");
    return -1;
  }
  char p[100],r[100];
  int p1p0[2];
  pid_t pid;
  int num;
  do
  {
    pipe(p1p0);
    printf("inserisci la stringa:\n");
    scanf("%s",s);
    pid=fork();
    if(pid==0)
    {
      close(p1p0[0]);
      close(1);
      dup (p1p0[1]);
      close(p1p0[1]);
      execl("/usr/bin/grep", "grep-c", s,argv[1],NULL);
    }
    close(p1p0[1]);
    read(p1p0[0],r,sizeof(s);
         num=atoi(s);
         printf("%d\n",num);
  }while(strcmp(s,"fine")!=0)
  return 0;
}
