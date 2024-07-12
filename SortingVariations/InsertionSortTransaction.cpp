//Enzo Brito Alves de Oliveira - RA: 082220040
//Heitor Santos Ferreira - RA: 081230042
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Transacao {
    string descricao;
    float valor;
};

void insertionSort(vector<Transacao>& transacoes) {
    int n = transacoes.size();
    for (int i = 1; i < n; ++i) {
        Transacao chave = transacoes[i];
        int j = i - 1;

        while (j >= 0 && transacoes[j].valor > chave.valor) {
            transacoes[j + 1] = transacoes[j];
            j = j - 1;
        }
        transacoes[j + 1] = chave;
    }
}

int main() {
    
    vector<Transacao> transacoes = {
        {"Compra de produto A", 100.50},
        {"Pagamento de conta de luz", 50.75},
        {"Compra de produto B", 75.25},
        {"Pagamento de fatura de cartão de crédito", 200.00},
        {"Depósito em conta", 300.00}
    };

    
    insertionSort(transacoes);

    
    cout << "Transações ordenadas por valor monetário:" << endl;
    for (const auto& transacao : transacoes) {
        cout << "Descrição: " << transacao.descricao << ", Valor: " << transacao.valor << endl;
    }

    return 0;
}
