#include <stdio.h>
#include <stdlib.h>

// Função para realizar a busca binária
int busca_binaria(int arr[], int tamanho, int elemento) {
    int esquerda = 0, direita = tamanho - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        // Verifica se o elemento está no meio
        if (arr[meio] == elemento)
            return meio;

        // Se o elemento for maior, ignore a metade esquerda
        if (arr[meio] < elemento)
            esquerda = meio + 1;
        // Se o elemento for menor, ignore a metade direita
        else
            direita = meio - 1;
    }

    // Retorna -1 se o elemento não estiver presente no array
    return -1;
}

// Função para carregar um array de um arquivo .txt
int* carregar_array(const char* nome_arquivo, int* tamanho) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    // Contando o número de elementos no arquivo
    int valor;
    *tamanho = 0;
    while (fscanf(arquivo, "%d", &valor) != EOF) {
        (*tamanho)++;
    }

    // Retornando ao início do arquivo para ler os valores
    rewind(arquivo);

    // Alocando memória para o array
    int *arr = (int*)malloc((*tamanho) * sizeof(int));
    if (arr == NULL) {
        printf("Erro ao alocar memória.\n");
        fclose(arquivo);
        return NULL;
    }

    // Lendo os valores do arquivo e armazenando no array
    for (int i = 0; i < *tamanho; i++) {
        fscanf(arquivo, "%d", &arr[i]);
    }

    fclose(arquivo);
    return arr;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <nome_do_arquivo.txt>\n", argv[0]);
        return 1;
    }

    const char* nome_arquivo = argv[1];
    int tamanho;
    int *arr = carregar_array(nome_arquivo, &tamanho);

    if (arr == NULL) {
        return 1;
    }

    // O elemento a ser buscado é o último do array
    int elemento = arr[tamanho - 1];

    int resultado = busca_binaria(arr, tamanho, elemento);
    if (resultado != -1)
        printf("Elemento %d encontrado no índice %d\n", elemento, resultado);
    else
        printf("Elemento %d não encontrado\n", elemento);

    free(arr); // Liberando a memória alocada
    return 0;
}
