#include <iostream>
#include <string>
#include "Pilha.h"  // Incluímos a pilha que você forneceu

using namespace std;

// Função para validar a expressão
bool validarExpressao(string expressao) {
    Pilha_Construtor();  // Inicializar a pilha

    for (char caractere : expressao) {
        // Se o caractere for '(' ou '[', vamos empilhá-lo
        if (caractere == '(' || caractere == '[') {
            Pilha_Empilhar(caractere);
        }
        // Se for um ')' ou ']', verificar o topo da pilha
        else if (caractere == ')' || caractere == ']') {
            TipoDado topo;
            // Se a pilha estiver vazia ou o topo não corresponder, a expressão é inválida
            if (Pilha_Vazia()) {
                return false;
            }
            Pilha_Topo(topo);  // Pega o elemento do topo sem removê-lo
            if ((caractere == ')' && topo != '(') || (caractere == ']' && topo != '[')) {
                return false;
            }
            Pilha_Desempilhar(topo);  // Remove o topo, já que ele é correspondente
        }
    }

    // Se a pilha não estiver vazia no final, ainda há aberturas não fechadas
    return Pilha_Vazia();
}

int main() {
    string expressao;
    cout << "Digite a expressao matematica: ";
    cin >> expressao;

    // Verifica se a expressão é válida
    if (validarExpressao(expressao)) {
        cout << "OK" << endl;
    } else {
        cout << "Errado" << endl;
    }

    return 0;
}
