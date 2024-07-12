//CEFSA - Centro Educacional da Fundação Salvador Arena
//FESA - Faculdade Engenheiro Salvador Arena
//Enzo Brito Alves de Oliveira - RA: 082220040
//Heitor Santos Ferreira - RA: 081230042
//Engenharia de Computação - 4° Semestre - EC4
//Estrurutas de dados
//Professor: Israel Florentino

#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <string>
#include <functional> // Para std::function

class Contato {
public:
    std::string nome;
    std::string telefone;
    std::string email;
    bool favorito;

    Contato(std::string nome, std::string telefone, std::string email)
        : nome(nome), telefone(telefone), email(email), favorito(false) {}

    void marcarComoFavorito() {
        favorito = true;
    }

    void desmarcarComoFavorito() {
        favorito = false;
    }
};

class Node {
public:
    Contato* contato;
    Node* left;
    Node* right;
    int height;

    Node(Contato* contato)
        : contato(contato), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    Node* root;

    int height(Node* N) {
        return (N == nullptr) ? 0 : N->height;
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    int getBalance(Node* N) {
        return (N == nullptr) ? 0 : height(N->left) - height(N->right);
    }

    Node* insert(Node* node, Contato* contato) {
        if (node == nullptr)
            return new Node(contato);

        if (contato->nome < node->contato->nome)
            node->left = insert(node->left, contato);
        else if (contato->nome > node->contato->nome)
            node->right = insert(node->right, contato);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && contato->nome < node->left->contato->nome)
            return rightRotate(node);

        if (balance < -1 && contato->nome > node->right->contato->nome)
            return leftRotate(node);

        if (balance > 1 && contato->nome > node->left->contato->nome) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && contato->nome < node->right->contato->nome) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node* root, std::string nome) {
        if (root == nullptr)
            return root;

        if (nome < root->contato->nome)
            root->left = deleteNode(root->left, nome);
        else if (nome > root->contato->nome)
            root->right = deleteNode(root->right, nome);
        else {
            if ((root->left == nullptr) || (root->right == nullptr)) {
                Node* temp = root->left ? root->left : root->right;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                }
                else
                    *root = *temp;
                delete temp;
            }
            else {
                Node* temp = minValueNode(root->right);
                root->contato->nome = temp->contato->nome;
                root->contato = temp->contato;
                root->right = deleteNode(root->right, temp->contato->nome);
            }
        }

        if (root == nullptr)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void preOrder(Node* root) {
        if (root != nullptr) {
            std::cout << root->contato->nome << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void inOrder(Node* root) {
        if (root != nullptr) {
            inOrder(root->left);
            std::cout << root->contato->nome << " ";
            inOrder(root->right);
        }
    }

    Node* search(Node* root, std::string nome) {
        if (root == nullptr || root->contato->nome == nome)
            return root;

        if (root->contato->nome < nome)
            return search(root->right, nome);

        return search(root->left, nome);
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(Contato* contato) {
        root = insert(root, contato);
    }

    void deleteNode(std::string nome) {
        root = deleteNode(root, nome);
    }

    void preOrder() {
        preOrder(root);
    }

    void inOrder() {
        inOrder(root);
    }

    Contato* search(std::string nome) {
        Node* node = search(root, nome);
        if (node != nullptr)
            return node->contato;
        return nullptr;
    }

    void listFavorites() {
        listFavorites(root);
    }

    Node* getRoot() {
        return root;
    }

private:
    void listFavorites(Node* node) {
        if (node != nullptr) {
            listFavorites(node->left);
            if (node->contato->favorito)
                std::cout << node->contato->nome << " ";
            listFavorites(node->right);
        }
    }
};

#endif