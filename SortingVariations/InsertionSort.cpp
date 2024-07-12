//Enzo Brito Alves de Oliveira - RA: 082220040
//Heitor Santos Ferreira - RA: 081230042
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Evento {
    string descricao;
    string dataHora;
};


void insertionSort(vector<Evento>& eventos) {
    int n = eventos.size();
    for (int i = 1; i < n; ++i) {
        Evento chave = eventos[i];
        int j = i - 1;

        while (j >= 0 && eventos[j].dataHora > chave.dataHora) {
            eventos[j + 1] = eventos[j];
            j = j - 1;
        }
        eventos[j + 1] = chave;
    }
}

int main() {
    
    vector<Evento> eventos = {
        {"Evento 1", "2024-03-19 08:00:00"},
        {"Evento 2", "2024-03-18 15:30:00"},
        {"Evento 3", "2024-03-20 10:45:00"},
        {"Evento 4", "2024-03-18 12:20:00"},
        {"Evento 5", "2024-03-19 11:15:00"}
    };

    // Ordena os eventos usando o insertion sort
    insertionSort(eventos);

    // Imprime os eventos ordenados
    cout << "Eventos ordenados por ordem cronológica:" << endl;
    for (const auto& evento : eventos) {
        cout << "Descrição: " << evento.descricao << ", Data e Hora: " << evento.dataHora << endl;
    }

    return 0;
}
