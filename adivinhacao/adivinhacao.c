#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	//imprime cabecalho do jogo
	printf("************************************\n");
	printf("* Bem vindo ao jogo de adivinhação *\n");
	printf("************************************\n");

	//gera uma semente para que o numero rand seja sempre diferente
	int segundos = time(0);
	srand(segundos);

	//gera numeros aleatorios muito grande
	int numerogrande = rand();

	//gerar um numero entre 0 e 99
	int numerosecreto = numerogrande % 100;
	int chute;
	int tentativas = 1;
	double pontos = 1000;
	int acertou = 0;

	int nivel;
	printf("Qual o nível de dificuldade?\n");
	printf("(1)Fácil (2)Médio (3)Difivil\n\n");
	printf("Escolha: ");
	scanf("%d", &nivel);

	int numerodetentativas;

	switch(nivel){
		case 1:
			numerodetentativas = 20;
			break;

		case 2:
			numerodetentativas = 15;
			break;
			
		default:
			numerodetentativas = 6;
			break;
	}

	for (int i = 1; i <= numerodetentativas; i++){

		printf("Tentativa %d de %d\n", i, numerodetentativas);

		printf("Qual é o seu chute? ");
		scanf("%d", &chute);

		if (chute < 0){
			printf("Você não pode chutar um número negativo!\n");
			i--;
			continue;
		}

		acertou = (chute == numerosecreto);
		int maior = chute > numerosecreto;
		
		if (acertou){
			break;
		}
		else if (maior){
			printf("\nSeu chute foi MAIOR que o número secreto\n\n");
		}
		else{
			printf("\nSeu chute foi MENOR que o número secreto\n\n");
		}

		double pontosperdidos = abs(chute - numerosecreto) / 2.0;
		pontos = pontos - pontosperdidos;
	}

	printf("Fim de jogo\n");

	if (acertou){
		printf("Você ganhou!\n");
		printf("Você acertou em %d tentativas!\n", tentativas);
		printf("Total de pontos: %.1f\n", pontos);	
	}else{
		printf("Você perdeu! Tente de novo!\n");
	}		
}