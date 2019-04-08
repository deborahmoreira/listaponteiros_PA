#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// função para comparar os valores do array e reponsável por ordenar de forma crescente (a - b) ou descrecente (b - a).
//como os paramêtros são tipo void é necessário fazer o casting para adequar ao tipo que queremos.
int comparador(const void *a, const void *b) {
   return ( *(float*)a - *(float*)b );
}

int main()
{
    int n, i, j, tempo;
    time_t tinicial, tfinal;

    tinicial = time(NULL);/* marca o tempo inicial */

    //receber quantos valores haverá no array:
    printf("Insira a quantidade de valores: ");
    scanf("%i", &n);

    //alocação dinamica para o array:
    float *p, aux;
    p = (float*) malloc(n*sizeof(float));

    //recebe os valores do array:
    for(i = 0; i < n; i++){
        printf("Valor %i = ", i);
        scanf("%f", &p[i]);
        printf("\n");
    }

    //uso da função qsort() para ordenar o array de forma crescente:
    qsort(p, n, sizeof(float), comparador);

    //exibe os valores do array ordenado:
    for(i = 0; i < n; i++){
        printf("%.1f\n", p[i]);
    }
    tfinal = time(NULL); /* marca o tempo final */
    tempo = difftime(tfinal, tinicial); /* marca a diferença tfim-tinicio */
    printf("tempo q15: %i", tempo);

    return(0);
}
