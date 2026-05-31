#ifndef PILHA_H
#define PILHA_H

/**
* @brief Implemena uma pilha dinãmica utilizando lista encadeada.
*
* A estrutura segue o modelo LIFO (Last In, First Out)
* permitindo inserção e remoçã no topo da pilha
*/
class Pilha {
private:
    /**
     * @brief Estrutura de nó da pilha. 
     */
    struct No {
        /// Caractere armazenado
        char dado;

        /// Ponteiro para o próximo nó
        No* proximo;
    };

    /// Ponteiro para o topo da pilha
    No* topo;

public:
    /**
     * @brief Construtor da pilha
     */
    Pilha();

    /**
     * @brief Destrutor da pilha
     *
     * Libera toda memória alocada dinamicamente.
     */
    ~Pilha();

    /**
     * @brief Insere um elemento no topo da pilha
     *
     * @param valor Caractere que será empilhado
     */
    void push(char valor);

    /**
     * @brief Remove o elemento do topo da pilha
     */
    void pop();

    /**
     *@brief Retorna o elemento do topo.
     *
     *@return Caractere presente no topo da pilha
     */
    char top();

    /**
     * @brief Verifica se a pilha está vazia.
     *
     * @return true se estiver vazia
     * @return false caso contrário
     */
    bool isEmpty();

    /**
     * @brief Exibe todos os elementos da pilha
     */
    void exibir();
};

#endif