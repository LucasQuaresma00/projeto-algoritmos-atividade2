#include <iostream>
#include "Pilha.h"

/**
 * @brief Inicializa a pilha vazia.
 */
Pilha::Pilha() {
    topo = nullptr;
}

/**
 * @brief Libera toda memória da pilha.
 */
Pilha::~Pilha() {
    
    // Remove todos os elementos até a pilha ficar vazia
    while (!isEmpty()) {
        pop();
    }
}

/**
 * @brief Verifica se a pilha está vazia.
 */
bool Pilha::isEmpty() {
    return topo == nullptr;
}

/**
 * @brief Insere um elemento no topo da pilha.
 */
void Pilha::push(char valor) {
    // Cria novo nó dinamicamente
    No* novo = new No;

    // Armazena o caractere no nó
    novo->dado = valor;
    // Novo nó aponta para o topo antigo
    novo->proximo = topo;

    // Atualiza o topo da pilha
    topo = novo;
}

/**
 * @brief Remove o elemento do topo da pilha.
 */
void Pilha::pop() {
    // Verifica se a pilha está vazia
    if (isEmpty()) {
        std::cout << "Pilha vazia!\n";
        return;
    }

    // Guarda topo atual
    No* removido = topo;

    // Move topo para próximo nó
    topo = topo->proximo;

    // Libera memória do nó removido
    delete removido;
}


/**
 * @brief Retorna o elemento do topo.
 */
char Pilha::top() {
    // Retorna caractere nulo caso a pilha esteja vazia
    if (isEmpty()) {
        return '\0';
    }

    return topo->dado;
}

/**
 * @brief Exibe os elementos da pilha.
 */
void Pilha::exibir() {
    if (isEmpty()) {
        std::cout << "Pilha vazia.\n";
        return;
    }

    No* atual = topo;

    std::cout << "TOPO -> ";

    // Percorre todos os elementos da pilha
    while (atual != nullptr) {
        std::cout << "[" << atual->dado << "]";

        if (atual->proximo != nullptr) {
            std::cout << " -> ";
        }

        atual = atual->proximo;
    }

    std::cout << "\n";
}