#include <iostream>
#include "Fila.h"

using namespace std;

/**
 * @brief Programa principal do sistema da danceteria.
 *
 * O sistema controla filas de homens e mulheres
 * utilizando filas dinâmicas.
 *
 * Quando uma nova pessoa chega:
 * - o sistema verifica se existe alguém esperando
 *   na fila oposta;
 * - caso exista, um casal é formado;
 * - caso contrário, a pessoa entra na fila.
 */
int main() {

    Fila homens;
    Fila mulheres;

    int opcao;

    do {

        cout << "\n=============================\n";
        cout << " SISTEMA DA DANCETERIA\n";
        cout << "=============================\n";

        cout << "1 - Adicionar pessoa\n";
        cout << "2 - Mostrar filas\n";
        cout << "0 - Sair\n";

        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == 1) {

            Pessoa p;

            cout << "Nome: ";
            //cin >> p.nome;
            // Dessa forma podemos ler nomes compostos
            cin.ignore();
            getline(cin, p.nome);

            cout << "Genero (M/F): ";
            cin >> p.genero;

            p.genero = toupper(p.genero);

            // Homem
            if (p.genero == 'M') {

                if (!mulheres.isEmpty()) {

                    Pessoa par = mulheres.dequeue();

                    cout << "\n Casal formado:\n";
                    cout << p.nome << " + " << par.nome << "\n";

                } else {

                    homens.enqueue(p);

                    cout << p.nome << " entrou na fila masculina.\n";
                }
            }

            // Mulher
            else if (p.genero == 'F') {

                if (!homens.isEmpty()) {

                    Pessoa par = homens.dequeue();

                    cout << "\n Casal formado:\n";
                    cout << par.nome << " + " << p.nome << "\n";

                } else {

                    mulheres.enqueue(p);

                    cout << p.nome << " entrou na fila feminina.\n";
                }
            }

            else {
                cout << "Genero invalido.\n";
            }
        }

        else if (opcao == 2) {

            cout << "\nFila masculina:\n";
            homens.exibir();

            cout << "\nFila feminina:\n";
            mulheres.exibir();
        }

    } while (opcao != 0);

    return 0;
}