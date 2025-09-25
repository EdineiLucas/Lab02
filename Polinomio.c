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

void define_coeficiente(Polinomio pol, int grau, int coef){

    Polinomio pol_aux = pol->prox;

    while(pol_aux != pol){
        if(pol_aux->valor.grau < grau){
            pol_aux = pol_aux->prox;
        }
        else if(pol_aux->valor.grau == grau){
            pol_aux->valor.coef = coef;
            return;
        }
        else if(pol_aux->valor.grau > grau){
            Polinomio novo_pol = (No*)malloc(sizeof(No));
            novo_pol->valor.grau = grau;
            novo_pol->valor.coef = coef;
            novo_pol->antec = pol_aux->antec;
            novo_pol->prox = pol_aux;
            pol_aux->antec->prox = novo_pol;
            pol_aux->antec = novo_pol;
            return;
        }
    }
    Polinomio novo_pol = (No*)malloc(sizeof(No));
    novo_pol->valor.grau = grau;
    novo_pol->valor.coef = coef;
    novo_pol->antec = pol_aux->antec;
    novo_pol->prox = pol_aux;
    pol_aux->antec->prox = novo_pol;
    pol_aux->antec = novo_pol;
    return;
}

void zera(Polinomio pol){

    Polinomio pol_aux = pol->prox;
    
    if (pol_aux == pol){
        return;
    }
    while (pol_aux != pol)
    {
        Polinomio removido;
        removido = pol_aux;
        pol_aux = pol_aux->prox;
        free(removido);
    }
    pol_aux->prox = pol_aux;
    pol_aux->antec = pol_aux;
    return;
}

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

    return 0;
}