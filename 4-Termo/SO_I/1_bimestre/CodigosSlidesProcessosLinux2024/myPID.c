#include <stdio.h>
#include <unistd.h>

int main(void) {
   pid_t childpid;
   pid_t mypid;

   mypid = getpid();
   childpid = fork();
   if (childpid == -1) {
	perror("Failed to fork");
	return 1;
   }
   if (childpid == 0)
        printf("Eu sou o filho %ld, ID = %ld\n",(long int)  getpid(), (long int) mypid);
   else
	printf("Eu sou o Pai %ld, ID = %ld\n", (long int) getpid(), (long int) mypid);
   return 0;
}
