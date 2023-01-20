#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
		printf ("bem vindo ao jogo de adivinhacao\n");
	int segundos = time(0);
	srand (segundos);
	int numerogrande = rand();
	int numerosecreto = numerogrande % 100;
	int chute;
	int tentativas = 1;
	double pontos = 1000;
	int acertou = 0;
	
	int nivel;
	printf ("qual o nivel de dificuldade?");
	printf ("(1) facil (2) medio (3) dificil\n\n");
	printf ("escolha");
	scanf ("%d", &nivel);
	
	int numerodetentativas;
	
	switch (nivel) {
		case 1:
			numerodetentativas = 20;
			break;
		case 2:
			numerodetentativas = 15;
			break;
		default: 
			numerodetentativas = 5;
			break;
	}
	
	
	
	for (int i=1; i<= numerodetentativas; i++){
		
		printf ("tentativa %d\n", tentativas);
		printf ("qual o seu chute?\n");
	scanf ("%d", &chute);
	printf ("seu chute foi %d\n", chute);
	if (chute<0) {
		printf ("você nao pode chutar numeros negativos!\n");
		continue;
	}
	
    acertou=(chute==numerosecreto);
	int maior = chute > numerosecreto;
	if (acertou){

	break;
	}
	
	else if (maior) {
		printf ("seu chute foi maior que o numero secreto\n");
			
		}
		else {
			printf ("seu chute foi menor que o numero secreto\n");
		}
		tentativas++;
		
		double pontosperdidos= abs(chute-numerosecreto)/(double)2;
		pontos = pontos-pontosperdidos;
	}
	printf ("fim de jogo!\n");
	if (acertou) {
		printf ("voce ganhou!\n");
		printf ("voce acertou em %d tentativas!\n", tentativas);
		printf ("total de pontos: %.1f\n", pontos);
	} else {
		printf ("voce perdeu! tente de novo!\n");
		
	}
	

}
	
