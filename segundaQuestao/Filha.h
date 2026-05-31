#ifndef FILA_H
#define FILA_H

#include "Pessoa.h"

/**
 * @brief Implementa uma fila dinâmica utilizando lista encadeada.
 *
 * A estrutura segue o modelo FIFO (First In, First Out),
 * permitindo inserção no final e remoção na frente da fila.
 */
class Fila {
private:

    /**
     * @brief Estrutura de nó da fila.
     */
    struct No {
        Pessoa pessoa;
        No* proximo;
    };

    No* frente;
    No* tras;

public:
     /**
     * @brief Construtor da fila.
     */
    Fila();

     /**
     * @brief Destrutor da fila.
     */
    ~Fila();

     /**
     * @brief Insere uma pessoa no final da fila.
     *
     * @param p Pessoa que será inserida.
     */
    void enqueue(Pessoa p);

    /**
     * @brief Remove a pessoa da frente da fila.
     */
    Pessoa dequeue();

    /**
     * @brief Verifica se a fila está vazia.
     *
     * @return true se estiver vazia.
     * @return false caso contrário.
     */
    bool isEmpty();

     /**
     * @brief Retorna a pessoa presente na frente da fila.
     *
     * @return Pessoa localizada na frente da fila.
     */
    Pessoa front();

    /**
     * @brief Exibe os elementos da fila.
     */
    void exibir();
};

#endif