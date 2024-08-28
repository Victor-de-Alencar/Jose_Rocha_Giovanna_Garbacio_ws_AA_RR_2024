#include <stdio.h>
#include <stdlib.h>

// Função de busca por interpolação
int busca_interpolacao(int arr[], int tamanho, int elemento, int *contador) {
    int esquerda = 0, direita = tamanho - 1;

    while (esquerda <= direita && elemento >= arr[esquerda] && elemento <= arr[direita]) {
        // Se todos os elementos são iguais, retorna o índice ou -1
        if (esquerda == direita) {
            if (arr[esquerda] == elemento) 
                return esquerda;
            return -1;
        }

        // Posição de interpolação
        int pos = esquerda + ((double)(direita - esquerda) / (arr[direita] - arr[esquerda])) * (elemento - arr[esquerda]);
        (*contador)++;  // Incrementa o contador a cada cálculo de 'pos'

        // Se o elemento foi encontrado
        if (arr[pos] == elemento)
            return pos;

        // Se o elemento é maior, está na parte direita
        if (arr[pos] < elemento)
            esquerda = pos + 1;
        // Se o elemento é menor, está na parte esquerda
        else
            direita = pos - 1;
    }
    return -1; // Elemento não encontrado
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

    // O elemento a ser buscado é o penúltimo do array
    int elemento = arr[tamanho - 2];
    int contador = 0;

    int resultado = busca_interpolacao(arr, tamanho, elemento, &contador);
    if (resultado != -1)
        printf("Elemento %d encontrado no índice %d\n", elemento, resultado);
    else
        printf("Elemento %d não encontrado\n", elemento);

    printf("A variável 'pos' foi calculada %d vezes\n", contador);

    free(arr); // Liberando a memória alocada
    return 0;
}
