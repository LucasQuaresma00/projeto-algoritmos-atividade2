#include <iostream>
#include <string>
#include "Pilha.h"

using namespace std;

/**
 * @brief Verifica se uma palavra é palíndromo.
 *
 * O algoritmo empilha todos os caracteres da palavra
 * e depois compara os elementos removidos da pilha
 * com a string original.
 *
 * @param texto Palavra que será analisada.
 * @return true se for palíndromo.
 * @return false caso contrário.
 *
 *
 */
bool verificarPalindromo(string texto) {

    Pilha pilha;

    // Empilha todos os caracteres
    for (char c : texto) {
        pilha.push(c);
    }

    // Exibe estado atual da pilha
    pilha.exibir();

    // Compara com desempilhamento
    for (char c : texto) {

        if (c != pilha.top()) {
            return false;
        }

        pilha.pop();
    }
    pilha.exibir();
    return true;
}

int main() {

    string palavra;

    cout << "=================================\n";
    cout << " VERIFICADOR DE PALINDROMO\n";
    cout << "=================================\n\n";

    cout << "Digite uma palavra: ";
    // ao contrario do c << "..." que  separa entre espaços
    // o getline pega le a linha inteira.
    getline(cin, palavra);

    cout << "\n";

    if (verificarPalindromo(palavra)) {
        cout << "Resultado: É PALINDROMO!\n";
    } else {
        cout << "Resultado: NÃO É PALINDROMO!\n";
    }

    return 0;
}

// exemplos: ovo, Anotaram a data da maratona
// O lobo ama o bolo