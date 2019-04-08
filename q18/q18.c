/**
Escreva uma função em c que escreva em um vetor a soma dos elementos correspondentes de outros dois vetores (os tamanhos dos vetores devem ser
fornecidos pelo usuário). Por exemplo, se o primeiro vetor contiver os elementos 1, 3, 0 e -2, e o segundo vetor contiver os elementos 3, 5, -3 e 1,
o vetor de soma terá valores resultantes iguais a 4, 8, -3 e -1. A função deve receber 4 argumentos: os nomes dos três vetores e o número de elementos presentes
 em cada vetor.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamanhoVetor1, tamanhoVetor2, maiorTamanho;
    int *vetor1, *vetor2, *vetorResultado;

    printf("Informe o tamanho do vetor 1: ");
    scanf("%i", &tamanhoVetor1);

    printf("\n");

    printf("Informe o tamanho do vetor 2: ");
    scanf("%i", &tamanhoVetor2);

    printf("\n");

    vetor1 = malloc(tamanhoVetor1*sizeof(int));
    vetor2 = malloc(tamanhoVetor2*sizeof(int));

    for(int i = 0; i < tamanhoVetor1; i++){
        vetor1[i] = rand()%10;
        printf("%d  ", vetor1[i]);
    }

    printf("\n");

    for(int i = 0; i < tamanhoVetor2; i++){
        vetor2[i] = rand()%10;
        printf("%d  ", vetor2[i]);
    }

    printf("\n");

    //Verifica qual dos dois vetores é o maior e aloca um espaço de mémoria pro vetor resultado do mesmo tamanho do maior vetor.
    if(tamanhoVetor1 > tamanhoVetor2){
        maiorTamanho = tamanhoVetor1;
        vetorResultado = malloc(tamanhoVetor1*sizeof(int));
        for(int i = 0; i < tamanhoVetor1; i++){
            vetorResultado[i] = 0;
        }
    }else{
        maiorTamanho = tamanhoVetor2;
        vetorResultado = malloc(tamanhoVetor2*sizeof(int));
        for(int i = 0; i < tamanhoVetor2; i++){
            vetorResultado[i] = 0;
        }
    }

    //Verifica qual o maior vetor e depois soma seus elementos
    //Se a posição do vetor resposta for maior do que a o tamanho do menor vetor, o resultado da soma será igual ao valor da posição do maior vetor.
    for(int i = 0; i < maiorTamanho; i++){
        if(tamanhoVetor1 < tamanhoVetor2){
            if(i < tamanhoVetor1){
                vetorResultado[i] = vetor1[i] + vetor2[i];
            }else{
                vetorResultado[i] = vetor2[i];
            }
        }else{
            if(i < tamanhoVetor2){
                vetorResultado[i] = vetor1[i] + vetor2[i];
            }else{
                vetorResultado[i] = vetor1[i];
            }
        }
    }

    printf("Resultado: \n");
    for(int i = 0; i < maiorTamanho; i++){
        printf("%d  ", vetorResultado[i]);
    }

    printf("\n");

    free(vetor1);
    free(vetor2);
    free(vetorResultado);
    return 0;
}
