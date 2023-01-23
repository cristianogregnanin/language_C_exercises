#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int calcola_lunghezza_stringa_files(int argc, char *argv[])
{
    int dim = 0;
    for (int i = 1; i < argc - 2; i++)
    {
        dim = dim + strlen(argv[i]) + 1;
    }
    return dim;
}

void componi_stringa_files(int argc, char *argv[], char str[])
{
    str[0] = '\0';
    for (int i = 1; i < argc - 2; i++)
    {
        strcat(str, argv[i]);
        strcat(str, " ");
    }
    strcat(str, "\n");
}

int main(int argc, char *argv[])
{

    if (argc < 4)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

    int dim = calcola_lunghezza_stringa_files(argc, argv);
    int fd, ct = 0;
    char carattere, output[80], stringa_files[dim];

    componi_stringa_files(argc, argv, stringa_files);

    for (int i = 1; i < argc - 2; i++)
    {
        fd = open(argv[i], O_RDONLY);

        while (read(fd, &carattere, sizeof(carattere)) > 0)
        {
            if (carattere == argv[argc - 2][0])
            {
                ct++;
            }
        }

        close(fd);
    }

    sprintf(output, "Il carattere %s compare %d volte nei files: %s\n", argv[argc - 2], ct, stringa_files);

    fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, output, strlen(output));
    close(fd);

    write(1, output, strlen(output));

    return 0;
}
