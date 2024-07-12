//Enzo Brito Alves de Oliveira - RA: 082220040
//Heitor Santos Ferreira - RA: 081230042
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Produto {
    string nome;
    float preco;
};

void selectionSort(vector<Produto>& produtos) {
    int n = produtos.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (produtos[j].preco < produtos[minIndex].preco) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(produtos[i], produtos[minIndex]);
        }
    }
}

int main() {
    // Exemplo de vetor de produtos desordenados
    vector<Produto> produtos = {
        {"Produto A", 50.0},
        {"Produto B", 30.0},
        {"Produto C", 80.0},
        {"Produto D", 20.0},
        {"Produto E", 60.0}
    };

    // Ordena os produtos usando o selection sort
    selectionSort(produtos);

    // Imprime os produtos ordenados por preço
    cout << "Produtos ordenados por preço em ordem crescente:" << endl;
    for (const auto& produto : produtos) {
        cout << "Nome: " << produto.nome << ", Preço: " << produto.preco << endl;
    }

    return 0;
}
