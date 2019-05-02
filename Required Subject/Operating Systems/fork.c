#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

char HH[16];

int main()
{
        int fd1[2], fd2[2];
        char name[16];
        int i, sum = 0;
        FILE *f;
        pid_t p;
        //memset(HH, 0, sizeof(HH));
        printf("[%d] This is first process\n", getpid());

        if(pipe(fd1) == -1) {
                printf("Create pipe fail \n");
                return -1;
        }
        if(pipe(fd2) == -1) {
                printf("Create pipe fail \n");
                return -1;
        }

        p = fork();
        if(p < 0) {
                printf("Create fork error\n");
                return -1;
        }
if(p != 0) {
                char aa[16];

                close(fd1[1]);
                memset(aa, 0, sizeof(aa));
                memset(name, 0, sizeof(aa));
                sleep(1);
                read(fd1[0], aa, sizeof(aa));
                sprintf(name, "%s.txt", aa); 
                printf("Parent %s \n", aa);

                for(i = 0; i < strlen(name); i++) {
                        if(name[i] >= '0' && name[i] <= '9')
                                sum += name[i] - '0';

                }
                f = fopen(name, "w");
                fprintf(f, "%d", sum);
                close(fd1[0]);
                fclose(f);

                exit(0);
        }
        else{
                close(fd1[0]);
                strcpy(HH, "a10715005");
                write(fd1[1], HH, (strlen(HH)+1));
                close(fd1[1]);

        }
}
