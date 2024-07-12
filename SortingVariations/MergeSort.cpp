//Enzo Brito Alves de Oliveira - RA: 082220040
//Heitor Santos Ferreira - RA: 081230042
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void merge(vector<string>& vetor, int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    vector<string> L(n1);
    vector<string> R(n2);

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
        if (L[i] <= R[j]) {
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

void mergeSort(vector<string>& vetor, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);

        merge(vetor, inicio, meio, fim);
    }
}

int main() {
    
    vector<string> fotos = {
        "foto3.jpg",
        "foto1.jpg",
        "foto5.jpg",
        "foto2.jpg",
        "foto4.jpg"
    };

    
    mergeSort(fotos, 0, fotos.size() - 1);

    
    cout << "Fotos ordenadas por nome de arquivo:" << endl;
    for (const auto& foto : fotos) {
        cout << foto << endl;
    }

    return 0;
}
