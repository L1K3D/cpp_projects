//Enzo Brito Alves de Oliveira - RA: 082220040
//Heitor Santos Ferreira - RA: 081230042
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Jogador {
    string nome;
    int pontuacao;
};

void selectionSort(vector<Jogador>& jogadores) {
    int n = jogadores.size();
    for (int i = 0; i < n - 1; ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (jogadores[j].pontuacao > jogadores[maxIndex].pontuacao) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            swap(jogadores[i], jogadores[maxIndex]);
        }
    }
}

int main() {
    // Exemplo de vetor de jogadores desordenados
    vector<Jogador> jogadores = {
        {"Jogador A", 100},
        {"Jogador B", 75},
        {"Jogador C", 120},
        {"Jogador D", 90},
        {"Jogador E", 110}
    };

    // Ordena os jogadores usando o selection sort em ordem decrescente de pontuação
    selectionSort(jogadores);

    // Imprime os jogadores ordenados por pontuação (ranking)
    cout << "Ranking de jogadores (ordem decrescente de pontuação):" << endl;
    for (size_t i = 0; i < jogadores.size(); ++i) {
        cout << "Posição " << i + 1 << ": " << jogadores[i].nome << " - Pontuação: " << jogadores[i].pontuacao << endl;
    }

    return 0;
}
