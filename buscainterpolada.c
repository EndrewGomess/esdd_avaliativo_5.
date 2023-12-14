#include <stdio.h>

int buscaInterpolada(int conjunto[], int tamanho, int alvo) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim && alvo >= conjunto[inicio] && alvo <= conjunto[fim]) {
        int posicao = inicio + ((double)(fim - inicio) / (conjunto[fim] - conjunto[inicio])) * (alvo - conjunto[inicio]);

        if (conjunto[posicao] == alvo) {
            return posicao;
        }

        if (conjunto[posicao] < alvo) {
            inicio = posicao + 1;
        } else {
            fim = posicao - 1;
        }
    }

    return -1; 
}

int main() {
    int conjunto_de_dados[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int alvo = 15;

    int resultado_interpolada = buscaInterpolada(conjunto_de_dados, 20, alvo);

    if (resultado_interpolada != -1) {
        printf("Busca interpolada: Elemento %d encontrado no índice %d\n", alvo, resultado_interpolada);
    } else {
        printf("Busca interpolada: Elemento %d não encontrado\n", alvo);
    }

    return 0;
}
