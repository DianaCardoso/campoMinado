//Se usar valores maiores que 10, o tabuleiro irá desalinhar, porém o jogo funcionará normalmente.
#define LINHA 5
#define COLUNA 8
#define BOMBA 'B'

void imprimematriz(char matriz[LINHA][COLUNA]);
void inicializatabela(char matriz[LINHA][COLUNA]);
void colocabomba(char matriz[LINHA][COLUNA], int dificuldade);
bool jogada(char tabela[LINHA][COLUNA], char gabarito[LINHA][COLUNA], int bomba, int* jogadasfeitas);
int bombasperto(char gabarito[LINHA][COLUNA], int linha, int coluna);
int bombas(int dificuldade);