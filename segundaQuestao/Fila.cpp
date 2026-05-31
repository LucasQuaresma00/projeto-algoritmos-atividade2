#include <iostream>
#include "Fila.h"

/**
 * @brief Inicializa a fila vazia.
 */
Fila::Fila() {
    frente = nullptr;
    tras = nullptr;
}

/**
 * @brief Libera toda memória da fila.
 */
Fila::~Fila() {
    // Remove todos os elementos da fila
    while (!isEmpty()) {
        dequeue();
    }
}

/**
 * @brief Verifica se a fila está vazia.
 */
bool Fila::isEmpty() {
    return frente == nullptr;
}

/**
 * @brief Insere uma pessoa no final da fila.
 */
void Fila::enqueue(Pessoa p) {

    No* novo = new No;

    novo->pessoa = p;
    novo->proximo = nullptr;

    if (isEmpty()) {
        frente = novo;
        tras = novo;
    } else {
        tras->proximo = novo;
        tras = novo;
    }
}

/**
 * @brief Remove e retorna a pessoa da frente da fila.
 */
Pessoa Fila::dequeue() {

    Pessoa vazio;

    if (isEmpty()) {
        return vazio;
    }

    No* removido = frente;

    Pessoa p = removido->pessoa;

    frente = frente->proximo;

    if (frente == nullptr) {
        tras = nullptr;
    }

    delete removido;

    return p;
}

/**
 * @brief Retorna a pessoa da frente da fila.
 */
Pessoa Fila::front() {

    Pessoa vazio;

    if (isEmpty()) {
        return vazio;
    }

    return frente->pessoa;
}

/**
 * @brief Exibe os elementos da fila.
 */
void Fila::exibir() {

    if (isEmpty()) {
        std::cout << "Fila vazia.\n";
        return;
    }

    No* atual = frente;

    while (atual != nullptr) {

        std::cout << atual->pessoa.nome;

        if (atual->proximo != nullptr) {
            std::cout << " -> ";
        }

        atual = atual->proximo;
    }

    std::cout << "\n";
}