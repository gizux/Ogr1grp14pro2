// Program: Kaynak Dosyasi
// Tarih: 29.12.13
// Grup elemanlari: Volkan DEMIR, Gizem ULUTAS, Oguzcan DUMAN, Kubra ALI, Ahmet BOZANLAR


#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

#define SHMSZ     8

int main()
{
    int shmid;
    key_t key;
    char *shm, *s;

    /*
     * We need to get the segment named
     * "5678", created by the server.
     */
    key = 5678;

    /*
     * Locate the segment.
     */
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    int pid = fork();
    if(!pid)
    { // sampler
        //execlp("sampler", "sampler", shmid, NULL);
    }
    else
    {
        // Collector
        
        /*
         * Now we attach the segment to our data space.
         */
        if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
            perror("shmat");
            exit(1);
        }
        printf("%s\n", shm);
        /*
         * Now read what the server put in the memory.
         */
        for (s = shm; *s != NULL; s++)
            printf("%d -",*s);
        putchar('\n');

        /*
         * Finally, change the first character of the 
         * segment to '*', indicating we have read 
         * the segment.
         */
        *shm = '*';

        exit(0);
    }
}