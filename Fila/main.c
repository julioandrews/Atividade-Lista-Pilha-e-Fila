#include <stdio.h>
#include <malloc.h>
#define ERRO -1
#define true 1
#define false 0
typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
  // outros campos...
} REGISTRO;

typedef struct aux {
  REGISTRO reg;
  struct aux* prox;
} ELEMENTO, *PONT;;

typedef struct {
  PONT inicio;
  PONT cabeca;
  PONT fim;
} FILA;

void inicializarFila(FILA* f){
  f->inicio = NULL;
  f->fim = NULL;
}

int tamanho(FILA* f) {
  PONT end = f->inicio;
  int tam = 0;
  while (end != NULL){
    tam++;
    end = end->prox;
  }
  return tam;
}

int tamanhoEmBytes(FILA* f) {
  return (tamanho(f)*sizeof(ELEMENTO)) + sizeof(FILA);
}

void destruirFila(FILA* f) {
  PONT end = f->inicio;
  while (end != NULL){
    PONT apagar = end;
    end = end->prox;
    free(apagar);
  }
  f->inicio = NULL;
  f->fim = NULL;
}

PONT retornarPrimeiro(FILA* f, TIPOCHAVE *ch){
  if (f->inicio != NULL) *ch = f->inicio->reg.chave;
  return f->inicio;
}

PONT retornarUltimo(FILA* f, TIPOCHAVE* ch){
  if (f->inicio == NULL) return NULL;
  *ch = f->fim->reg.chave;
  return f->fim;
}

// Funções modificadas
bool inserirNaFila(FILA* f, REGISTRO reg) {
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    novo->reg = reg;                        
    novo->prox = NULL;                           
    PONT atual = f->cabeca;                                 
    while (atual->prox != NULL) atual = atual->prox;  // Percorre a fila a partir do nó-cabeça   
    atual->prox = novo;                               // Conecta o novo nó ao final da fila
    return true;
}

bool excluirDaFila(FILA* f, REGISTRO* reg) {
    if (f->cabeca->prox == NULL) return false;   
    PONT apagar = f->cabeca->prox;               // Primeiro nó válido (depois do nó-cabeça)
    *reg = apagar->reg;                          
    f->cabeca->prox = apagar->prox;              // Avança o ponteiro do nó-cabeça
    free(apagar);                                
    return true;
}
// Fim




void exibirFila(FILA* f){
  PONT end = f->inicio;
  printf("Fila: \" ");
  while (end != NULL){
    printf("%d ", end->reg.chave);
    end = end->prox;
  }
  printf("\"\n");
}

PONT buscaSeq(FILA* f,TIPOCHAVE ch){
  PONT pos = f->inicio;
  while (pos != NULL){
    if (pos->reg.chave == ch) return pos;
    pos = pos->prox;
  }
  return NULL;
}

PONT buscaSeqSent1(FILA* f,TIPOCHAVE ch){
  if (!f->inicio) return NULL;
  PONT sentinela = malloc(sizeof(ELEMENTO));
  sentinela->reg.chave = ch;
  f->fim->prox = sentinela;
  PONT pos = f->inicio;
  while (pos->reg.chave != ch) pos = pos->prox;
  free(sentinela);
  f->fim->prox = NULL;
  if (pos!=sentinela) return pos;
  return NULL;
}

PONT buscaSeqSent2(FILA* f,TIPOCHAVE ch){
  if (!f->inicio) return NULL;
  ELEMENTO sentinela;
  sentinela.reg.chave = ch;
  f->fim->prox = &sentinela;
  PONT pos = f->inicio;
  while (pos->reg.chave != ch) pos = pos->prox;
  f->fim->prox = NULL;
  if (pos!=&sentinela) return pos;
  return NULL;
}