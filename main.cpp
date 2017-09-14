/* 
Versao 2: Diana Cardoso
Bacharelado em Ciência da Computaçao
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "campoMinado.h"


void aleatorio(void){
	srand(time(NULL));
	rand();
}

int main(){

	char tabela[LINHA][COLUNA];
	char gabarito[LINHA][COLUNA];
	char mostragabarito;
	char novojogo;
	int dificuldade; 
	bool continua;
	int jogadasfeitas;
	int bomba;

	//While que funciona toda vez que o usuario reiniciar o jogo.
	while(1){
		
		mostragabarito = 0;
		//while(mostragabarito != 's' && mostragabarito != 'S' && mostragabarito != 'n' && mostragabarito != 'N'){
			printf("Voce deseja mostrar o gabarito? (s/N)\n");
			fflush(stdin);
			scanf("%c", &mostragabarito);
		//}
		if((mostragabarito == ' ')){
			mostragabarito = 'n';
		}


		dificuldade = 0;
		while(dificuldade <= 0 || dificuldade > 4){
			printf("Escolha a dificuldade: \n1 - Facil\n2 - Medio\n3 - Dificil\n4 - Apocalipse\n");
			fflush(stdin);
			scanf("%d", &dificuldade);
		}

		bomba = bombas(dificuldade);

		inicializatabela(tabela);
		inicializatabela(gabarito);
		continua = true;

		jogadasfeitas = 0;

		aleatorio();
		colocabomba(gabarito, bomba);

		//While que funciona como atualizaçao das funçoes após cada jogada do usuario.
		while(continua){

			system("cls");
			imprimematriz(tabela);
			printf("\n\n");
			if(mostragabarito == 's' || mostragabarito == 'S'){
				imprimematriz(gabarito);
			}
			continua = jogada(tabela, gabarito, bomba, &jogadasfeitas);

			
		}
		printf("Voce deseja jogar novamente? (S/n)\n");
		fflush(stdin);
		scanf("%c", &novojogo);

		if(novojogo == 'n'){
			break;
		} 



	}
	
}

