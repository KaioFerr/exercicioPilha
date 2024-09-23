//Bibliotecas necessárias
#include "Pilha.h"


//definição de variáveis utilizadas para controlar e armazenar os dados na pilha
TipoDado Pilha[MAXTAM];  //esta implementação utiliza memória estática, ou seja, será utilizado
                        //um vetor para armazenar os dados na pilha
                        //Nesse exemplo será criada uma pilha de inteiros, mas poderia ser
                        //qualquer outro tipo de dado

int Topo;    //Variável utilizada para manter o controle do estado atual da pilha


//Um construtor é um método que deve ser executado obrigatoriamente antes da pilha ser utilizada
void Pilha_Construtor()
{

   Topo = -1;  //estado inicial da pilha.
               //Topo deve se referir ao índice -1 do vetor Pilha
               //para indicar que nenhum elemento foi empilhado
}

//Função para indicar se a Pilha está ou não vazia (se exite ou não algum elemento armazenado)
bool Pilha_Vazia()
{

   return Topo == -1;    //Pela forma como os elementos são Empilhados e Desempilhados (métodos a seguir)
                         //tem-se que a Pilha está vazia se o valor de Topo for -1
                         //O indice zero indicará que há um elemento armazenado nesta posição

                         //Se os valor de Topo for igual a -1, a função retorna verdadeiro
                         //caso contrário, será retornado falso (operador de comparação ==)
}


//Função para indicar se a Pilha está ou não cheia (se todas as posições do vetor foram ou não preenchidas)
bool Pilha_Cheia()
{
    if(Topo >= MAXTAM-1)  //Pela forma como os elementos são Empilhados e Desempilhados (métodos a seguir)
                          //tem-se que se o Topo for igual ao último índice do vetor (MAXTAM-1) então a Pilha está cheia
                          //Lembrar que o vetor começa no índice zero e vai até MAXTAM-1
                          //e o valor de Topo indica onde o último elemento inserido foi empilhado
      return true;
    else
      return false;
}


//Função para retornar o número de elementos armazenados na Pilha
int Pilha_Tamanho()
{

    return Topo+1;   //Observe que pela lógica do método Empilhar a seguir, o Topo + 1
                     //sempre se refere a quantidade de elementos na Pilha
}


//Método para adicionar elementos do topo da Pilha
//Se o elemento for Empilhado (armazenado na Pilha), o método retorna verdadeiro
//caso contrário, retorna falso
//Esse método também é conhecido como Push
bool Pilha_Empilhar(TipoDado Elemento)
{

     if(!Pilha_Cheia())  //Se a Pilha não estiver cheia, podemos adicionar algum elemento
     {

        Topo++;  //Topo é incrementado para indicar onde o elemento deve ser inserido no vetor
        Pilha[Topo] = Elemento; //O elemento atual é inserido (cópia) na posição indicada por Topo
        return true;  //Retona verdadeiro, indicando que o elemento foi empilhado (inserido na Pilha)
     }
     else //caso a Pilha esteja cheia
      return false;  //Retona falso, indicando que nenhum elemento foi empilhado (a Pilha está cheia)
}


//Método para remover elementos da Pilha
//Se o elemento for Desempilhado (removido da Pilha), o método retorna verdadeiro
//caso contrário, retorna falso
//O Elemento no topo da Pilha é removido e retornado por referência pelo parâmetro da função
//Esse método também é conhecido como Pop
bool Pilha_Desempilhar(TipoDado &Elemento)
{
     if(!Pilha_Vazia())   //primeiro deve-se conferir se a Pilha não está vazia
     {
        Elemento = Pilha[Topo]; //Copia para a variável Elemento o valor
                                //armazenado no topo da Pilha
                                //Esse valor é indicado pela variável Topo


        Topo--;  //Será decrementada a variável Topo para indicar o
                 //o novo elemento no Topo da Pilha


                 //Repare que o método Desempilhar não remove de fato o
                 //elemento da Pilha.

        return true;   //Retona verdadeiro, indicando que o elemento foi removido
     }
     else  //caso a Pilha esteja vazia
       return false;  //Retona falso, indicando que nenhum elemento foi removido (Não há Elemento para ser removido, a Pilha está vazia)
}


//Método para retornar o elemento no topo da Pilha sem Desempilha-lo
//O método retorna verdadeiro se a Pilha contém algum elemento e
//falso caso a Pilha esteja vazia
//O elemento é retornado por referência pelo parâmetro da função
bool Pilha_Topo(TipoDado &Elemento)
{
     if(!Pilha_Vazia())  //primeiro deve-se conferir se a Pilha não está vazia
     {
        Elemento = Pilha[Topo];  //assim como no método Desempilhar, o elemento no topo da pilha
                                 //está no índice indicado pela variável Topo
                                 //Repare que aqui não é feito Topo--, o que iria "remover" o elemento da Pilha
        return true;
     }
     else //caso a Pilha esteja vazia
          return false;  //retorna falso, indicando que não foi possível retornar o elemento
}
