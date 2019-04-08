#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gc.h>
#include <assert.h>

int main(){
     int i;
     clock_t tempo[2];
     GC_INIT();
     //Medindo o tempo de execução da libGC
     tempo[0] = clock();
     for (i = 0; i<9999999; i++){
        int *p = (int *) GC_MALLOC(1000000*sizeof(int));
     }
     tempo[1] = clock();
     double Tempo = (tempo[1] - tempo[0]) *1000.0/ (double) CLOCKS_PER_SEC;
     printf("\nTempo gasto: %g us. \n", Tempo);
     //Medindo o tempo de execução do malloc
     tempo[0] = clock();
     for (i = 0; i<9999999; i++){
        int *p = (int *) malloc(1000*sizeof(int));
        free(p)
     }
     tempo[1] = clock();
     double Tempo = (tempo[1] - tempo[0]) *1000000.0/ (double) CLOCKS_PER_SEC;
     printf("\nTempo gasto: %g us. \n", Tempo);
     return 0;
}
