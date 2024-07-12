//Enzo Brito Alves de Oliveira - RA: 082220040
//Heitor Santos Ferreira - RA: 081230042
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Contato {
    string nome;
    string dataNascimento;
};

void merge(vector<Contato>& vetor, int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    vector<Contato> L(n1);
    vector<Contato> R(n2);

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
        if (L[i].nome < R[j].nome || (L[i].nome == R[j].nome && L[i].dataNascimento <= R[j].dataNascimento)) {
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

void mergeSort(vector<Contato>& vetor, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);

        merge(vetor, inicio, meio, fim);
    }
}

int main() {

    vector<Contato> contatos = {
        {"João", "1990-05-15"},
        {"Maria", "1985-08-20"},
        {"Ana", "1992-03-10"},
        {"Pedro", "1987-12-05"},
        {"Carlos", "1985-08-20"}
    };

    mergeSort(contatos, 0, contatos.size() - 1);

    cout << "Contatos ordenados por nome e data de nascimento:" << endl;
    for (const auto& contato : contatos) {
        cout << "Nome: " << contato.nome << ", Data de Nascimento: " << contato.dataNascimento << endl;
    }

    return 0;
}
