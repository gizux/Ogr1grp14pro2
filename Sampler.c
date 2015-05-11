#include  <stdio.h>
#include  <stdlib.h>
#include  <sys/types.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>


void  main(int  argc, char *argv[])
{
     int    ShmID;
     int    *ShmPTR;
     
     ShmID = shmget(atoi(argv[1]), 4*sizeof(int), IPC_CREAT | 0666);
     if (ShmID < 0) {
          printf("*** shmget hatası (server) ***\n");
          exit(1);
     }
     printf("Sampler paylaşımlı belleğe erişti...\n");
  
     ShmPTR = (int *) shmat(ShmID, NULL, 0);
     if ((int) ShmPTR == -1) {
          printf("*** shmat error (server) ***\n");
          exit(1);
     }
     printf("Sampler paylaşımlı belleğe bağlandı (attach)...\n");
     
     int random;
     
     random = rand()%100;
     int r = 0;
     
     ShmPTR[0] = r;
     ShmPTR[1] = random;
     printf("Sampler paylaşılan belleği %d ve %d değerleriyle doldurdu...\n",
            ShmPTR[0], ShmPTR[1]);
     
     r++;
     
}
