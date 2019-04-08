//leia n valores do tipo float e os apresente em ordem crescente. Utilize alocação dinâmica de memória para realizar a tarefa.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i, j;

    printf("Insira a quantidade de valores: ");
    scanf("%i", &n);

    float *p, aux;
    p = (float*) malloc(n*sizeof(float));

    for(i = 0; i < n; i++){
        printf("Valor %i = ", i);
        scanf("%f", &p[i]);
        printf("\n");
    }

    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++){
            if(p[i] > p[j]){
                aux = p[i];
                p[i] = p[j];
                p[j] = aux;
            }
        }
    }

    for(i = 0; i < n; i++){
        printf("%.1f\n", p[i]);
    }

    return(0);
}
