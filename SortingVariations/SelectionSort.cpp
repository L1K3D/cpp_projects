//Enzo Brito Alves de Oliveira - RA: 082220040
//Heitor Santos Ferreira - RA: 081230042
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Produto {
    string nome;
    int nivelEstoque;
};

void selectionSort(vector<Produto>& produtos) {
    int n = produtos.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (produtos[j].nivelEstoque < produtos[minIndex].nivelEstoque) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(produtos[i], produtos[minIndex]);
        }
    }
}

int main() {

    vector<Produto> produtos = {
        {"Produto A", 10},
        {"Produto B", 5},
        {"Produto C", 15},
        {"Produto D", 3},
        {"Produto E", 8}
    };

    
    selectionSort(produtos);

    
    cout << "Produtos ordenados por nível de estoque:" << endl;
    for (const auto& produto : produtos) {
        cout << "Nome: " << produto.nome << ", Nível de Estoque: " << produto.nivelEstoque << endl;
    }

    return 0;
}
