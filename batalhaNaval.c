#include <stdio.h>
#include <stdlib.h>

#define linha 10 // tamanho do tabuleiro, linhas
#define coluna 10 // tamanho do tabuleiro, colunas
#define tam_habilidade 5 // tamanho das matrizes de habilidades

void iniciartabuleiro(int tabuleiro[linha][coluna])
{ //Essa função iniciar o tabuleiro na tela com água (0)
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            tabuleiro[i][j] = 0;
        }
        
    }
    
}
// função para exibir o tabuleiro na tela
void exibirtabuleiro(int tabuleiro[linha][coluna])
{
    //mostra as letras das colunas 
    printf("   "); // Aqui é para alinhar com os números das linhas
    for (int j = 0; j < coluna; j ++){
        printf("%3c ", 'A' + j); // aqui imprime as letras
    }
    printf("\n");

    //mostra os números das linhas e o conteúdo do tabuleiro
    for (int i = 0; i < linha; i++)
    { printf("%2d ", i); //imprime os números das linhas
        for (int j = 0; j < coluna; j++)
        {
            if (tabuleiro[i][j] == 0) printf("%3d", 0 ); //água
            else if (tabuleiro[i][j] == 3)printf("%3d", 3); //navio
            else if (tabuleiro[i][j] == 5) printf("%3d", 5); //área de habilidade
        }
        printf("\n");
    }
    
}
//Função para criar a matriz em forma de cone
void criarcone (int cone[tam_habilidade][tam_habilidade])
{
    for (int i = 0; i < tam_habilidade; i++)
    {
        for (int j = 0; j < tam_habilidade; j++)
        {
            if (j >= tam_habilidade/2 - i && j <= tam_habilidade/3 + i)
            {
            cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
            
        }
        
    }
    
}
//função para criar a matriz em forma de cruz
void criarcruz (int cruz [tam_habilidade][tam_habilidade])
{
    for (int i = 0; i < tam_habilidade; i++)
    {
        for (int j = 0; j < tam_habilidade; j++)
        {
            if (i == tam_habilidade/2 || j == tam_habilidade/2)
            {
            cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
            
        }
        
    }
    
}
//função para criar a matriz em forma de octaendro
void criaroctaendro (int octaendro [tam_habilidade][tam_habilidade]) {
    for (int i = 0; i < tam_habilidade; i++) {
        for (int j = 0; j < tam_habilidade; j++)
        {
            if (abs(i - tam_habilidade/2) + abs(j - tam_habilidade/2) <= tam_habilidade/2)
            {
                octaendro[i][j] = 1;
            } else {
                octaendro[i][j] = 0;
            }
            
        }
        
    }

}
// função para aplicar habilidade no tabuleiro
void aplicarhabilidade(int tabuleiro [linha][coluna], int habilidade [tam_habilidade][tam_habilidade], int origemlinha, int origemcoluna) {
    int offset = tam_habilidade / 2;
    for (int i = 0; i < tam_habilidade; i++) {
        for (int j = 0; j < tam_habilidade; j++) {
            int l = origemlinha + (i - offset);
            int c = origemcoluna + (j - offset);

            // Verifica se a posição está dentro dos limites do tabuleiro
            if (l >= 0 && l < linha && c >= 0 && c < coluna){
                if (habilidade[i][j] == 1 && tabuleiro[l][c] != 3){
                    tabuleiro[l][c] = 5; // Marca a área afetada pela habilidade   
                }
            }
        }
    }
}





int main() {
    int tabuleiro[linha][coluna];
    iniciartabuleiro(tabuleiro);
    
    tabuleiro[2][2] = 3; //colocando um navio no tabuleiro
    tabuleiro[5][5] = 3; //colocando um navio no tabuleiro

    int cone[tam_habilidade][tam_habilidade], cruz[tam_habilidade][tam_habilidade], octaendro[tam_habilidade][tam_habilidade];
    criarcone(cone);
    criarcruz(cruz); //criando as matrizes de habilidades
    criaroctaendro(octaendro);
    
    
    //Aplicar as habilidades em pontos diferentes do tabuleiro
    aplicarhabilidade (tabuleiro, cone, 1, 1);
    aplicarhabilidade (tabuleiro, octaendro, 3, 3);
    aplicarhabilidade (tabuleiro, cruz, 6, 6);

    //exibir o meu resultado
    exibirtabuleiro(tabuleiro);

    return 0;
}
