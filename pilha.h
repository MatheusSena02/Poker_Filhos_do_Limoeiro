// esse processo do ifndef, define e endif é boa pratica, mas hoje em dia pode n ser necessário, n da 
// problema GERALMENTE.
// evita a inclusao + de uma vez da biblioteca

//if not defined
#ifndef PILHA_H
//se nao tiver essa area definida,
#define PILHA_H
//aq pra baixo é a biblioteca
#include <stdio.h>
#define MAX 52
//toca vez que encontrar o termo "MAX", troca pra 100;

//seta o tipo de "tp_item", se vc mudar aq, toda a pilha muda o tipo
typedef int 
    tp_item;

typedef struct {
    int topo;
    tp_item item[MAX];
} tp_pilha;

void pilha_inicializar(tp_pilha *p){
// Prepara a pilha para interação
    p->topo = -1;
}

int pilha_vazia(tp_pilha *p) {
// Se a pilha estiver vazia, retorna 1
    if (p->topo == -1) return 1;
    return 0;
}

int pilha_cheia(tp_pilha *p) {
// Se a pilha estiver cheia, retorna 1
    if (p->topo == (MAX-1)) return 1;
    return 0;
}

int pilha_push(tp_pilha *p, tp_item e) {
// Parametros -> (ponteiro do struct pilha, valor tpitem para colocar na pilha)
    if (pilha_cheia(p)) return 0;
    p->topo++;
    p->item[p->topo]=e;
    return 1;
}

int pilha_pop(tp_pilha *p, tp_item *e) {
// Parametros -> (ponteiro do struct pilha, endereço de memória de uma variável para guardar info do item retirado)
    if (pilha_vazia(p)) return 0;
    *e=p->item[p->topo];
    p->topo--;
    return 1;
}

int pilha_top(tp_pilha *p, tp_item *e) {
// retorna o item no topo da pilha
    if (pilha_vazia(p)) return 0;
    *e=p->item[p->topo];
    return 1;
}

int pilha_altura(tp_pilha *p) {
// retorna a altura da pilha
    return p->topo+1;
}

void pilha_imprimir(tp_pilha p) {
    tp_item e;
    printf("\n");
    while (!pilha_vazia(&p)) {
        pilha_pop(&p,&e);
        printf("%d ",e);
    }
}

int pilha_cmp(tp_pilha pilha1,tp_pilha pilha2) {
//Compara pilha1 e pilha2, retorna 1 se forem iguais e 0 se forem diferentes
    tp_item a,b;
    if (pilha_altura(&pilha1) == pilha_altura(&pilha2)) {
        while (!pilha_vazia(&pilha1)) {
            pilha_pop(&pilha1,&a);
            pilha_pop(&pilha2,&b);
            if (a != b) {
                return 0;
            }
        }
        return 1;
    }
    else return 0;
    
}

int pilha_pilhaPush(tp_pilha *pilha1,tp_pilha *pilha2) {
// se couber na pilha1, empilha a pilha 2 em pilha 1
// retorna 0 para erro -> se nao couber em pilha1, a pilha 2
    tp_item e;
    if((pilha_altura(pilha1)+pilha_altura(pilha2))>(MAX)) return 0;
    tp_pilha pilha3;
    pilha_inicializar(&pilha3);
    
    while(!pilha_vazia(pilha2)) {
        pilha_pop(pilha2,&e);
        pilha_push(&pilha3,e);
    }
    
    while(!pilha_vazia(&pilha3)) {
        pilha_pop(&pilha3,&e);
        pilha_push(pilha1,e);
    }
    
    return 1;
}



//isso fecha o ifndef
#endif
