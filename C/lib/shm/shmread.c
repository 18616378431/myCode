#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>

#include "shmdata.h"

int main()
{
    int running = 1;
    void *shm = NULL;
    struct share_used_st *shared;
    int shmid;
    shmid = shmget((key_t)1234,sizeof(struct share_used_st),0666 | IPC_CREAT);

    if(shmid == -1)
    {
        fprintf(stderr,"shmget failed!\n");
        exit(EXIT_FAILURE);
    }

    shm = shmat(shmid,0,0);

    if(shm == (void *)-1)
    {
        fprintf(stderr,"shmat failed!\n");
        exit(EXIT_FAILURE);
    }

    printf("\nMemory attached at %X\n",(int)shm);

    shared = (struct share_used_st *)shm;
    shared->written = 0;

    while(running)
    {
        if(shared->written == 1)
        {
            printf("you wrote:%s",shared->text);
            
            sleep(rand() % 3);
            
            shared->written = 0;

            if(strncmp(shared->text,"end",3) == 0)
            {
                running = 0;
            }
        }
        else
        {
            sleep(1);
        }
    }

    if(shmdt(shm) == -1)
    {
        fprintf(stderr,"shmdt failed!\n");
        exit(EXIT_FAILURE);
    }

    if(shmctl(shmid,IPC_RMID,0) == -1)
    {
        fprintf(stderr,"shmctl(IPC_RMID) failed!\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}