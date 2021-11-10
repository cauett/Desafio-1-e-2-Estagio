#include <stdio.h>
#include <stdlib.h>

void organizarLetras(char *vetLetras, int *vetNums, int lines) 
{
    int i, j, aux;
    FILE *leituraArq, *ordenarLetras;
    
    leituraArq = fopen(/*insira local/nome do arquivo */, "r"); //arq. de entrada

    if (leituraArq == NULL) {
        printf("Arquivo nao encontrado!");
    }

    for (i = 0; i < lines; i++) {
        fscanf(leituraArq, "%c\t%d\n", (vetLetras + i), (vetNums + i)); //lê o arq.
    }

    ordenarLetras = fopen(/*insira local/nome do arquivo */, "w"); //arq. letras

    for (i = 0; i < lines; i++) {
        for (j = i + 1; j < lines; j++) {    
            if (vetLetras[i] > vetLetras[j]) {
                aux = vetLetras[i];
                vetLetras[i] = vetLetras[j];
                vetLetras[j] = aux;
            }
        }

        fprintf(ordenarLetras, "%c\t%d\n", *(vetLetras + i), *(vetNums + i));
    }
    
    fclose(leituraArq);
    fclose(ordenarLetras);
}

void organizarNumeros(int *vetNums, char *vetLetras, int lines)
{
    int i, j, aux;
    FILE *leituraArq, *ordenarNums;
    
    leituraArq = fopen(/*insira local/nome do arquivo */, "r"); //arq. de entrada

    if (leituraArq == NULL) {
        printf("Arquivo nao encontrado!");
    }

    for (i = 0; i < lines; i++) {
        fscanf(leituraArq, "%c\t%d\n", (vetLetras + i), (vetNums + i)); //lê o arq.
    }

    ordenarNums = fopen(/*insira local/nome do arquivo */, "w"); //arq. números

    for (i = 0; i < lines; i++) {
        for (j = i + 1; j < lines; j++) {    
            if (vetNums[i] > vetNums[j]) {
                aux = vetNums[i];
                vetNums[i] = vetNums[j];
                vetNums[j] = aux;
            }
        }

        fprintf(ordenarNums, "%c\t%d\n", *(vetLetras + i), *(vetNums + i));
    }

    fclose(leituraArq);
    fclose(ordenarNums);
}

int main() 
{   
    int lines;

    printf("Quantas linhas tem o arquivo? ");
    scanf("%d", &lines);

    char *vetLetras;
    int *vetNums;

    vetLetras = malloc(sizeof(char[lines][100]));
    vetNums = malloc(sizeof(int[lines]));

    organizarNumeros(vetNums, vetLetras, lines);
    printf("Arquivo organizado!\n");
    
    organizarLetras(vetNums, vetLetras, lines);
    printf("Arquivo organizado!\n");

    free(vetLetras);
    free(vetNums);

    return 0;
}