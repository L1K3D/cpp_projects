//CEFSA - Centro Educacional da Fundação Salvador Arena
//FESA - Faculdade Engenheiro Salvador Arena
//Enzo Brito Alves de Oliveira - RA: 082220040
//Heitor Santos Ferreira - RA: 081230042
//Engenharia de Computação - 4° Semestre - EC4
//Estrurutas de dados
//Professor: Israel Florentino

#include <iostream>
#include <fstream>
#include <sstream>
#include "AVLTree.h"

void mostrarMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Adicionar um novo contato\n";
    std::cout << "2. Remover um contato existente\n";
    std::cout << "3. Buscar por um contato específico\n";
    std::cout << "4. Listar todos os contatos em ordem alfabética\n";
    std::cout << "5. Listar os favoritos\n";
    std::cout << "6. Marcar como favorito\n";
    std::cout << "7. Desmarcar como favorito\n";
    std::cout << "8. Exportar contatos para CSV\n";
    std::cout << "9. Importar contatos de CSV\n";
    std::cout << "0. Sair\n";
}

void exportarCSV(AVLTree& arvore, const std::string& arquivo) {
    std::ofstream file(arquivo);
    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo para exportação.\n";
        return;
    }

    file << "Nome,Telefone,Email,Favorito\n";

    std::function<void(Node*)> exportar = [&](Node* node) {
        if (node != nullptr) {
            exportar(node->left);
            file << node->contato->nome << ","
                << node->contato->telefone << ","
                << node->contato->email << ","
                << (node->contato->favorito ? "Sim" : "Não") << "\n";
            exportar(node->right);
        }
        };
    exportar(arvore.getRoot());
    file.close();
    std::cout << "Contatos exportados com sucesso.\n";
}

void importarCSV(AVLTree& arvore, const std::string& arquivo) {
    std::ifstream file(arquivo);
    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo para importação.\n";
        return;
    }

    std::string linha;
    std::getline(file, linha); // Ignora o cabeçalho

    while (std::getline(file, linha)) {
        std::stringstream ss(linha);
        std::string nome, telefone, email, favorito;
        std::getline(ss, nome, ',');
        std::getline(ss, telefone, ',');
        std::getline(ss, email, ',');
        std::getline(ss, favorito, ',');

        Contato* contato = new Contato(nome, telefone, email);
        if (favorito == "Sim")
            contato->marcarComoFavorito();

        arvore.insert(contato);
    }

    file.close();
    std::cout << "Contatos importados com sucesso.\n";
}

int main() {
    AVLTree arvore;
    int opcao;
    do {
        mostrarMenu();
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        std::cin.ignore();

        switch (opcao) {
        case 1: {
            std::string nome, telefone, email;
            std::cout << "Nome: ";
            std::getline(std::cin, nome);
            std::cout << "Telefone: ";
            std::getline(std::cin, telefone);
            std::cout << "Email: ";
            std::getline(std::cin, email);
            Contato* contato = new Contato(nome, telefone, email);
            arvore.insert(contato);
            std::cout << "Contato adicionado.\n";
            break;
        }
        case 2: {
            std::string nome;
            std::cout << "Nome do contato a remover: ";
            std::getline(std::cin, nome);
            arvore.deleteNode(nome);
            std::cout << "Contato removido.\n";
            break;
        }
        case 3: {
            std::string nome;
            std::cout << "Nome do contato a buscar: ";
            std::getline(std::cin, nome);
            Contato* contato = arvore.search(nome);
            if (contato != nullptr) {
                std::cout << "Nome: " << contato->nome << "\n";
                std::cout << "Telefone: " << contato->telefone << "\n";
                std::cout << "Email: " << contato->email << "\n";
                std::cout << "Favorito: " << (contato->favorito ? "Sim" : "Não") << "\n";
            }
            else {
                std::cout << "Contato não encontrado.\n";
            }
            break;
        }
        case 4: {
            std::cout << "Contatos em ordem alfabética:\n";
            arvore.inOrder();
            std::cout << "\n";
            break;
        }
        case 5: {
            std::cout << "Contatos favoritos:\n";
            arvore.listFavorites();
            std::cout << "\n";
            break;
        }
        case 6: {
            std::string nome;
            std::cout << "Nome do contato a marcar como favorito: ";
            std::getline(std::cin, nome);
            Contato* contato = arvore.search(nome);
            if (contato != nullptr) {
                contato->marcarComoFavorito();
                std::cout << "Contato marcado como favorito.\n";
            }
            else {
                std::cout << "Contato não encontrado.\n";
            }
            break;
        }
        case 7: {
            std::string nome;
            std::cout << "Nome do contato a desmarcar como favorito: ";
            std::getline(std::cin, nome);
            Contato* contato = arvore.search(nome);
            if (contato != nullptr) {
                contato->desmarcarComoFavorito();
                std::cout << "Contato desmarcado como favorito.\n";
            }
            else {
                std::cout << "Contato não encontrado.\n";
            }
            break;
        }
        case 8: {
            std::string arquivo;
            std::cout << "Nome do arquivo para exportar (com extensão .csv): ";
            std::getline(std::cin, arquivo);
            exportarCSV(arvore, arquivo);
            break;
        }
        case 9: {
            std::string arquivo;
            std::cout << "Nome do arquivo para importar (com extensão .csv): ";
            std::getline(std::cin, arquivo);
            importarCSV(arvore, arquivo);
            break;
        }
        case 0:
            std::cout << "Saindo...\n";
            break;
        default:
            std::cout << "Opção inválida.\n";
            break;
        }
    } while (opcao != 0);

    return 0;
}