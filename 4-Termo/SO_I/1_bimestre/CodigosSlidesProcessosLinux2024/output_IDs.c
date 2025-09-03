#include <unistd.h>
#include <stdio.h>
int main (void) {
   printf("I am process %ld\n", (long)getpid());
   printf("My parent is %ld\n", (long)getpid());

   printf("Meu user ID eh       %5ld\n", (long)getuid());
   printf("My real group ID is      %5ld\n", (long)getgid());
   return 0;
}
