//Enzo Brito Alves de Oliveira - RA: 082220040
//Heitor Santos Ferreira - RA: 081230042
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Tarefa {
    string descricao;
    int prioridade;
};

void merge(vector<Tarefa>& vetor, int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    vector<Tarefa> L(n1);
    vector<Tarefa> R(n2);

    for (int i = 0; i < n1; ++i) {
        L[i] = vetor[inicio + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = vetor[meio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = inicio;
    while (i < n1 && j < n2) {
        if (L[i].prioridade <= R[j].prioridade) {
            vetor[k] = L[i];
            ++i;
        } else {
            vetor[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        vetor[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        vetor[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<Tarefa>& vetor, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);

        merge(vetor, inicio, meio, fim);
    }
}

int main() {
    
    vector<Tarefa> tarefas = {
        {"Tarefa A", 2},
        {"Tarefa B", 1},
        {"Tarefa C", 3},
        {"Tarefa D", 1},
        {"Tarefa E", 2}
    };

    
    mergeSort(tarefas, 0, tarefas.size() - 1);

    
    cout << "Tarefas ordenadas por prioridade:" << endl;
    for (const auto& tarefa : tarefas) {
        cout << "Descrição: " << tarefa.descricao << ", Prioridade: " << tarefa.prioridade << endl;
    }

    return 0;
}
