#include <stdio.h>
#include <stdlib.h>
#include "polinomio.h"

void inicializa_polinomio(Polinomio * ap_pol){
    Polinomio cabeca = (No*) malloc(sizeof(No));
    cabeca->valor.grau = -1;
    cabeca->valor.coef = -1;
    cabeca->prox = cabeca;
    cabeca->antec = cabeca;
    *ap_pol = cabeca;
}

/* Define que o coeficiente de grau grau do polinomio pol eh igual a coef. Deve manter os 
 * coeficientes ordenados por grau. */
void define_coeficiente(Polinomio pol, int grau, int coef){
    
}

/* Zera o polinomio, tornando-o um polinomio inicializado, mas igual a zero. Desaloca a memória liberada. */
void zera(Polinomio pol);

/* Computa a soma dos polinomios a e b colocando o resultado em res. 
 * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void soma(Polinomio res, Polinomio a, Polinomio b);

/* Computa a subtracao dos polinomios a e b colocando o resultado em res. 
 * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void subtrai(Polinomio res, Polinomio a, Polinomio b);


/* Imprime o polinomio pol no formato do exemplo abaixo
 * [(0,2),(3,-2),(10,5)]
 * onde este polinomio tem 3 coeficientes, o de grau 0 com valor 2, o de grau 3 com valor -2 e o de
 * grau 10 com valor 5. 
 */
void imprime(Polinomio pol){

    Polinomio cabeca = pol;
    pol = pol->prox;
    if (pol == cabeca){
        printf("[]");
        return;
    }
    printf("[");
    while(pol != cabeca){
        if (pol->prox == cabeca){
            printf("(%d,%d)", pol->valor.grau, pol->valor.coef);
        }
        else{
            printf("(%d,%d),", pol->valor.grau, pol->valor.coef);
        }
        pol = pol->prox;
    }
    printf("]");
}

/* Desaloca toda a memória alocada da lista.
 */
void desaloca_polinomio(Polinomio *ap_pol);

int main (){

    Polinomio p;

    inicializa_polinomio(&p);
    imprime(p);

    return 0;
}