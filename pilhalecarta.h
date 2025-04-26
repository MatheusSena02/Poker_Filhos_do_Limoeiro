#ifndef PILHALECARTA_H
#define PILHALECARTA_H

#include <stdio.h>
#include <stdlib.h>

typedef tp_carta tp_pilhaLEcarta_item; 

typedef struct tp_no_aux {   
  tp_pilhaLEcarta_item info;   
  struct tp_no_aux *prox;   
} tp_pilhaLEcarta_no; 


typedef struct {   
  tp_pilhaLEcarta_no *topo;   
} tp_pilhaLEcarta;


tp_pilhaLEcarta *pilhaLEcarta_inicializar (){
   tp_pilhaLEcarta *pilha=(tp_pilhaLEcarta*) malloc(sizeof(tp_pilhaLEcarta));   
   pilha->topo = NULL;   
   return pilha;
}  

int pilhaLEcarta_verificar_vazia (tp_pilhaLEcarta *pilha){   
 if (pilha->topo == NULL) return 1;
 return 0;
}

tp_pilhaLEcarta_no *pilhaLEcarta_aloca() {
	tp_pilhaLEcarta_no* pt;
	pt=(tp_pilhaLEcarta_no*) malloc(sizeof(tp_pilhaLEcarta_no));
	return pt;
}

int pilhaLEcarta_push (tp_pilhaLEcarta *pilha, tp_pilhaLEcarta_item e){   
  tp_pilhaLEcarta_no *novo;   
  novo=pilhaLEcarta_aloca();
  if (!novo) return 0;
  novo->info = e;  
  if (pilhaLEcarta_verificar_vazia(pilha) ) { //Se for o primeiro elemento da lista
     novo->prox = NULL;   
     }  
  else {
     novo->prox = pilha->topo;   
     }  
  pilha->topo = novo; 
  return 1;   
}        


int pilhaLEcarta_pop (tp_pilhaLEcarta *pilha, tp_pilhaLEcarta_item *e){   
  tp_pilhaLEcarta_no *aux;
  if (pilhaLEcarta_verificar_vazia(pilha)) return 0;
  *e=pilha->topo->info;
  aux=pilha->topo;
  pilha->topo=pilha->topo->prox;
  free(aux);
  aux=NULL;
  return 1;   
}      

int pilhaLEcarta_topo (tp_pilhaLEcarta *pilha, tp_pilhaLEcarta_item *e){   
  if (pilhaLEcarta_verificar_vazia(pilha)) return 0;
  *e=pilha->topo->info;
  return 1;   
}        

tp_pilhaLEcarta *pilhaLEcarta_destruir(tp_pilhaLEcarta *pilha) {    
	 tp_pilhaLEcarta_no *atu=pilha->topo, *aux;
     tp_pilhaLEcarta_item e;
	 while (atu != NULL)
	       {
			aux = atu->prox;
            pilhaLEcarta_pop(pilha, &e);  
			atu= aux; 
            }
	pilha->topo = NULL;
	free(pilha);
	return NULL;
}


#endif
