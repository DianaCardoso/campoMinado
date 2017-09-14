/*campoMinado.cpp*/

//Pragma once serva para nao copiar duas vezes.
#pragma once
#include "campoMinado.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Funçao que imprime o tabuleiro do jogo.
void imprimematriz(char matriz[LINHA][COLUNA]){
	
	int i=0,j=0,a=0,b=0;

	//Imprime o cabeçalho da coluna 0,1,...,N.
	printf(" ");
	while(b<COLUNA){  
		printf(" %d",b);
		b++;
	}
	printf("\n\n"); 

	//Imprime o tabuleiro do jogo e os valores das linhas.
	for(i = 0; i < LINHA; i++){
		printf("%d",i);
		for(j = 0; j < COLUNA; j++){
			printf("%2c",matriz[i][j]);
		}
		printf("\n\n");
	}
}

//Funçao que atribui as matrizes o valor de X, inicialmente.
void inicializatabela(char matriz[LINHA][COLUNA]){

	int i = 0, j = 0;

	for(i=0;i<LINHA;i++){
		for(j=0;j<COLUNA;j++){
			matriz[i][j] ='X';
			}
	}
}

//Funçao que coloca bombas aleatoriamente.
void colocabomba(char matriz[LINHA][COLUNA], int dificuldade){

	int tmp = 0, i = 0, j = 0;

	while(tmp < dificuldade){
		i= (rand() % LINHA);
		j= (rand() % COLUNA);
		if(matriz[i][j]=='X'){
			matriz[i][j]= BOMBA;
			tmp++;
		}
	}
}

//Funçao das jogadas do usuario.
bool jogada(char tabela[LINHA][COLUNA], char gabarito[LINHA][COLUNA], int bomba, int* jogadasfeitas){

	int linha, coluna;

	fflush(stdin);
	printf("digite a linha (0 ~ %d):\n", LINHA-1);
	fflush(stdin);		
	scanf("%d",&linha);

	printf("digite a coluna (0 ~ %d):\n", COLUNA-1);
	scanf("%d",&coluna);
    fflush(stdin);

	if(gabarito[linha][coluna]!='X'){
			system("cls");
			printf("Poxa, voce perdeu! \n");
			return false;
		}
		//Verifica se a quantidade de jogadas que nao existem bombas é igual ao tamanho da matriz menos a quantidade de bomba.
		else{
			tabela[linha][coluna]= bombasperto(gabarito, linha, coluna) + 48;
			(*jogadasfeitas) ++;
			if(*jogadasfeitas == ((LINHA*COLUNA)-bomba)){
				system("cls");
				printf("Parabens, voce ganhou!\n");
           		return false;
			}
		} return true;
}

//Funçao que compara quantas bombas tem perto da jogada que o usuario escolheu.
int bombasperto(char gabarito[LINHA][COLUNA], int linha, int coluna){

	int bombasPerto = 0;

	if(gabarito[linha - 1][coluna - 1] >= 0 && gabarito[linha - 1][coluna - 1] == BOMBA) bombasPerto ++;
	if(gabarito[linha - 1][coluna] >= 0 && gabarito[linha - 1][coluna] == BOMBA) bombasPerto ++;
	if(gabarito[linha - 1][coluna + 1] >= 0 && gabarito[linha - 1][coluna + 1] == BOMBA) bombasPerto ++;
	if(gabarito[linha][coluna - 1] >= 0 && gabarito[linha][coluna - 1] == BOMBA) bombasPerto ++;
	if(gabarito[linha][coluna + 1] >= 0 && gabarito[linha][coluna + 1] == BOMBA) bombasPerto ++;
	if(gabarito[linha + 1][coluna - 1] >= 0 && gabarito[linha + 1][coluna - 1] == BOMBA) bombasPerto ++;
	if(gabarito[linha + 1][coluna] >= 0 && gabarito[linha + 1][coluna] == BOMBA) bombasPerto ++;
	if(gabarito[linha + 1][coluna + 1] >= 0 && gabarito[linha + 1][coluna +1] == BOMBA) bombasPerto ++;

	return bombasPerto;
}

//Funcao que defini a dificuldade escolhida pelo usuario. 
int bombas(int dificuldade){

	int bomba=0;

	if(dificuldade ==1)bomba = (LINHA*COLUNA)/10;
	if(dificuldade ==2)bomba = (LINHA*COLUNA)/5;
	if(dificuldade ==3)bomba = (LINHA*COLUNA)/(2);
	if(dificuldade ==4)bomba = (LINHA*COLUNA)-1;

	return bomba;
}