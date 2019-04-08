#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparar(int a, int b){
   return (a - b);
}

void novoqsort (int *base, int n, size_t size, int (*funcao)(int a, int b)){
    int aux;
    int *array;
    array = (int*) malloc(n * size);

    for(int i = 0; i < n; i++){
        array[i] = base[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
             if(funcao(array[i], array[j]) >= 1){
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }

    for(int i = 0; i < n; i++){
        base[i] = array[i];
    }
    free(array);
}
int main(){
    int n, *p, tempo;
    time_t tinicial, tfinal;

    tinicial = time(NULL);

    printf("Insira a quantidade de valores: ");
    scanf("%i", &n);

    p = (int*) malloc(n*sizeof(int));

    printf("Vetor antes:\n");
    for(int i = 0; i < n; i++){
        p[i] = rand()%10;
        printf("%d  ", p[i]);
    }
    printf("\n");

    int (*funcao)(int a, int b);

    funcao = comparar;

    novoqsort(p, n, sizeof(int), funcao);

    printf("Vetor depois:\n");
    for(int i = 0; i < n; i++){
        printf("%d  ", p[i]);
    }
    printf("\n");

    tfinal = time(NULL);
    tempo = difftime(tfinal, tinicial);
    printf("tempo q16: %i", tempo);
return 0;
}
