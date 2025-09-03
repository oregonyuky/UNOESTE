/* rodar o programa em background */
/* O programa é lançado em background.   Primeiro, rode normalmente o programa. 
 * Verifique que o pai sai do wait e é concluído assim que um dos filhos termina.    
 * Na segunda vez, rode o programa matando o primeiro filho logo depois que o Filho2 for dormir.    
 * Verifique que agora o pai sai do Wait(), terminando antes do Filho2. 
 * Verifique que Filho2 foi adotado pelo init. 
 * */ 
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() 
{
int pid ;
	printf("Eu sou o processo pai, PID =  %d, e eu vou criar um filho.\n",getpid()) ;
	printf("Agora estou entrando em um loop infinito. Tchau!\n") ;
	pid = fork() ;
	if(pid == -1) /* erro */
	{
		perror("E impossivel criar um filho") ;
		exit(-1) ;
	}
	else if(pid == 0) /* filho */
	{
		printf("Eu sou o filho, PID = %d. Estou vivo mas vou dormir um pouco. Enquanto isso, use o comando ps -l para conferir o meu PID, o meu estado (S=sleep), o PID do meu pai e o estado do meu pai (R=running). Daqui a pouco eu acordo.\n",getpid()) ;
		sleep(60) ;
		printf("Acordei! Vou terminar agora. Confira novamente essas informaÃ§Ãµes. NÃ£Ã£Ã£ooooooo!!! Virei um zumbi!!!\n") ;
		exit(0) ;
	}
	else /* pai */
	{
		for(;;) ; /* pai bloqueado em loop infinito */
	}
}

