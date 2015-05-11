#include  <stdio.h>
#include  <stdlib.h>
#include  <sys/types.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>

void  Sampler(int);

void  main(int  argc, char *argv[])
{
     int    ShmID;
     int    *ShmPTR;
     pid_t  pid;
     int    status;
     int key = 55667;

     ShmID = shmget(key, 4*sizeof(int), IPC_CREAT | 0666);
     if (ShmID < 0) {
          printf("*** shmget error (server) ***\n");
          exit(1);
     }

     ShmPTR = (int *) shmat(ShmID, NULL, 0);
     if ((int) ShmPTR == -1) {
          printf("*** shmat error (server) ***\n");
          exit(1);
     }

     pid = fork();
     while(1)
     {
     if (pid < 0) {
          printf("*** fork error (server) ***\n");
          exit(1);
     }
     else if (pid == 0) {
       char buffer[5];
       snprintf(buffer, 5, "%d", key);

       //Sampler(ShmID);
       execlp("/home/gizux/Belgeler/ogr1grp14pro2/Sampler1","/home/gizux/Belgeler/ogr1grp14pro2/Sampler1", buffer, NULL);
       perror("execlp error");
       //exit(0);
       
     }

     wait(&status);
     //sClientProcess();
     int* SharedMem;
     SharedMem = (int *) shmat(ShmID, NULL, 0);
     if ((int) SharedMem == -1) {
          printf("*** shmat error (server) ***\n");
     }
  
     printf("   Collector found %d %d in shared memory\n",
                SharedMem[0], SharedMem[1]);
     
     //shmdt((void *) ShmPTR);
     //shmctl(ShmID, IPC_RMID, NULL);
     sleep(1);
     }
     //while(1);
     //exit(1);
     
}
int r = 0;

void  Sampler(int ShmID)
{
     //int    ShmID;
     int    *ShmPTR;
     
     ShmID = shmget(55667, 4*sizeof(int), IPC_CREAT | 0666);
     if (ShmID < 0) {
          printf("*** shmget error (server) ***\n");
          exit(1);
     }

     ShmPTR = (int *) shmat(ShmID, NULL, 0);
     if ((int) ShmPTR == -1) {
          printf("*** shmat error (server) ***\n");
          exit(1);
     }
     
     int random;
     
     random = rand()%100+1;
     
     
     ShmPTR[0] = r;
     ShmPTR[1] = random;
     
     r++;
     random = 0;
     printf("Sampler has filled %d %d in shared memory...\n",
            ShmPTR[0], ShmPTR[1]);
     
     sleep(1);
     
}