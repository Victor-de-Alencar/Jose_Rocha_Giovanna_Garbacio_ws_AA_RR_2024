#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para comparar dois inteiros (usada para ordenar)
int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Função para gerar um array de números aleatórios únicos e ordená-lo
void gerar_array(int tamanho, const char* nome_arquivo) {
    int *arr = (int*)malloc(tamanho * sizeof(int));
    if (arr == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    // Preenchendo o array com números aleatórios únicos
    for (int i = 0; i < tamanho; i++) {
        arr[i] = rand();
    }

    // Ordenando o array em ordem crescente
    qsort(arr, tamanho, sizeof(int), comparar);

    // Salvando o array no arquivo .txt
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        free(arr);
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d\n", arr[i]);
    }

    fclose(arquivo);
    free(arr);
}

int main() {
    srand(time(NULL)); // Inicializando o gerador de números aleatórios

    // Tamanhos dos arrays
    int tamanhos[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    for (int i = 0; i < num_tamanhos; i++) {
        char nome_arquivo[50];
        snprintf(nome_arquivo, sizeof(nome_arquivo), "array_teste_%d.txt", tamanhos[i]);
        gerar_array(tamanhos[i], nome_arquivo);
    }

    printf("Arquivos gerados com sucesso!\n");
    return 0;
}
