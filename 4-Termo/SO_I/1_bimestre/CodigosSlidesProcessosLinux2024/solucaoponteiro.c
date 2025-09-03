#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int *flag;

int main (void)
{
                int shmid, pid;

                /* cria um segmento de memória partilhada para um vetor flag de 3 posições */
                shmid = shmget (IPC_CREAT, 3*sizeof(int), IPC_CREAT | 0644);

                // O comando abaixo aloca um segmento/area para o vetor de 3 posições criado antes. Semelhante ao malloc
                flag = (int*) shmat (shmid, NULL, 0);

                flag[0] =  0;
                flag[1] =  0;
                flag[2] = 0; // 0 pai e 1 filho (faz o papel do turn)

                if  (fork() > 0) // pai
               {
               }
               else //filho
              {
               }
  shmdt(flag);
 shmctl(shmid, IPC_RMID, NULL);
}
