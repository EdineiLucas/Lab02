#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void soma(Polinomio res, Polinomio a, Polinomio b){

    Polinomio aux_a = a->prox, aux_b = b->prox;

    while(aux_a != a && aux_b != b){
        if (aux_a->valor.grau == aux_b->valor.grau){
            if((aux_a->valor.coef) + (aux_b->valor.coef) == 0){
                aux_a = aux_a->prox;
                aux_b = aux_b->prox;
            }
            else{
                define_coeficiente(res, aux_a->valor.grau, (aux_a->valor.coef)+(aux_b->valor.coef));
                aux_a = aux_a->prox;
                aux_b = aux_b->prox;
            }
        }
        else if((aux_a->valor.grau) < (aux_b->valor.grau)){
            define_coeficiente(res, aux_a->valor.grau, aux_a->valor.coef);
            aux_a = aux_a->prox;
        }
        else{
            define_coeficiente(res, aux_b->valor.grau, aux_b->valor.coef);
            aux_b = aux_b->prox;
        }
    }
    return;
}

void subtrai(Polinomio res, Polinomio a, Polinomio b){

    Polinomio aux_a = a->prox, aux_b = b->prox;

    while (aux_a != a && aux_b != b)
    {
        if ((aux_a->valor.grau) == (aux_b->valor.grau)){
            if ((aux_a->valor.coef) - (aux_b->valor.coef) == 0){
                aux_a = aux_a->prox;
                aux_b = aux_b->prox;
            }
            else{
                define_coeficiente(res, aux_a->valor.grau, (aux_a->valor.coef) - (aux_b->valor.coef));
                aux_a = aux_a->prox;
                aux_b = aux_b->prox;
            }
        }
        else if ((aux_a->valor.grau) < (aux_b->valor.grau)){
            define_coeficiente(res, aux_a->valor.grau, aux_a->valor.coef);
            aux_a = aux_a->prox;
        }
        else{
            define_coeficiente(res, aux_b->valor.grau, (0)-(aux_b->valor.coef));
            aux_b = aux_b->prox;
        }
    }
    return;
}

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
void desaloca_polinomio(Polinomio *ap_pol){

    Polinomio * ap_aux = &(*ap_pol)->prox;

    while (ap_aux != ap_pol)
    {
        Polinomio remove;
        remove = (*ap_aux);
        ap_aux = &((*ap_aux)->prox);
        free (remove);
    }
    free (ap_aux);
    return;
}