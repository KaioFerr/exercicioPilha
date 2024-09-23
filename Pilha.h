#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef char TipoDado; //Define o tipo de dado que será armazenado na Pilha
const int MAXTAM = 100;  //define o número máximo de elementos que a pilha pode armazenar


//Um construtor é um método que deve ser executado obrigatoriamente antes da pilha ser utilizada
void Pilha_Construtor();

//Função para indicar se a Pilha está ou não vazia (se exite ou não algum elemento armazenado)
bool Pilha_Vazia();

//Função para indicar se a Pilha está ou não cheia (se todas as posições do vetor foram ou não preenchidas)
bool Pilha_Cheia();

//Função para retornar o número de elementos armazenados na Pilha
int Pilha_Tamanho();


//Método para adicionar elementos do topo da Pilha
//Se o elemento for Empilhado (armazenado na Pilha), o método retorna verdadeiro
//caso contrário, retorna falso
//Esse método também é conhecido como Push
bool Pilha_Empilhar(TipoDado Elemento);


//Método para remover elementos da Pilha
//Se o elemento for Desempilhado (removido da Pilha), o método retorna verdadeiro
//caso contrário, retorna falso
//O Elemento no topo da Pilha é removido e retornado por referência pelo parâmetro da função
//Esse método também é conhecido como Pop
bool Pilha_Desempilhar(TipoDado &Elemento);


//Método para retornar o elemento no topo da Pilha sem Desempilha-lo
//O método retorna verdadeiro se a Pilha contém algum elemento e
//falso caso a Pilha esteja vazia
//O elemento é retornado por referência pelo parâmetro da função
bool Pilha_Topo(TipoDado &Elemento);

#endif // PILHA_H_INCLUDED
