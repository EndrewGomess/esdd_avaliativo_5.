#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABELA 10

typedef struct Node {
    int chave;
    int valor;
    struct Node* proximo;
} Node;

typedef struct TabelaHash {
    Node* tabela[TAMANHO_TABELA];
} TabelaHash;

int funcaoHash(int chave) {
    return chave % TAMANHO_TABELA;
}

void inserir(TabelaHash* tabela, int chave, int valor) {
    int indice = funcaoHash(chave);
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->chave = chave;
    novoNo->valor = valor;
    novoNo->proximo = tabela->tabela[indice];
    tabela->tabela[indice] = novoNo;
}

int buscar(TabelaHash* tabela, int chave) {
    int indice = funcaoHash(chave);
    Node* atual = tabela->tabela[indice];

    while (atual != NULL) {
        if (atual->chave == chave) {
            return atual->valor; 
        }
        atual = atual->proximo;
    }

    return -1; 
}

int main() {
    TabelaHash tabela;
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela.tabela[i] = NULL;
    }

    inserir(&tabela, 10, 100);
    inserir(&tabela, 20, 200);

    int resultado_hash = buscar(&tabela, 10);

    if (resultado_hash != -1) {
        printf("Índices Hash: Elemento encontrado com valor %d\n", resultado_hash);
    } else {
        printf("Índices Hash: Elemento não encontrado\n");
    }

    return 0;
}
