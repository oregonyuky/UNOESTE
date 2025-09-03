#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#include <stdlib.h>

int main(void) {
   int c2, c1;

	c2 = 0;
    c1 = fork(); 	 /* fork number 1 */
    printf("\nFork 1 - I am process %ld, my C2 is %d and my C1 is %d\n", (long)getpid(), c2, c1);
    if (c1 == 0)
	{
           c2 = fork(); /* fork number 2 */
           printf("\nFork 2 - I am process %ld, my C2 is %d and my C1 is %d\n", (long)getpid(), c2, c1);

	}
    fork();		 /* fork number 3 */
    printf("\nFork 3 - I am process %ld, my C2 is %d and my C1 is %d\n", (long)getpid(), c2, c1);
    if (c2 > 0)
    {
       fork(); 	 /* fork number 4 */
       printf("\nFork 4 - I am process %ld, my C2 is %d and my C1 is %d\n", (long)getpid(), c2, c1);
    }
    exit(0);
}

