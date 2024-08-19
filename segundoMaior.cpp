#include <iostream>
#include <algorithm> // Para std::max

// Definição da estrutura do nó da árvore AVL
class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int value) : key(value), left(nullptr), right(nullptr), height(1) {}
};

// Função para obter a altura de um nó
int height(Node* node) {
    return node ? node->height : 0;
}

// Função para atualizar a altura de um nó
void updateHeight(Node* node) {
    if (node) {
        node->height = 1 + std::max(height(node->left), height(node->right));
    }
}

// Função para obter o fator de balanceamento de um nó
int getBalance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Função para realizar uma rotação à direita
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Realizar a rotação
    x->right = y;
    y->left = T2;

    // Atualizar as alturas
    updateHeight(y);
    updateHeight(x);

    return x;
}

// Função para realizar uma rotação à esquerda
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Realizar a rotação
    y->left = x;
    x->right = T2;

    // Atualizar as alturas
    updateHeight(x);
    updateHeight(y);

    return y;
}

// Função para inserir um valor na árvore AVL
Node* insert(Node* node, int key) {
    // Passo 1 - Inserir o nó na árvore BST
    if (!node) return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Chaves duplicadas não são permitidas

    // Passo 2 - Atualizar a altura do nó ancestral
    updateHeight(node);

    // Passo 3 - Obter o fator de balanceamento para verificar se o nó está desbalanceado
    int balance = getBalance(node);

    // Se o nó estiver desbalanceado, há 4 casos a considerar

    // Caso Left Left
    if (balance > 1 && key < node->left->key)
        return rotateRight(node);

    // Caso Right Right
    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);

    // Caso Left Right
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Caso Right Left
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    // Retornar o nó (inalterado)
    return node;
}

// Função para realizar a travessia em pré-ordem da árvore
void preOrder(Node* root) {
    if (root) {
        std::cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Função auxiliar para deletar a árvore
void destroyTree(Node* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}






Node* maiorDescendente(Node* node) {
    if (!node || (!node->right && !node->left)) {
        return nullptr;
    }

    if (node->right) {
        Node* right = node->right;

        if (!right->right) {
            return right->left ? right->left : node;
        }
        return maiorDescendente(right);
    }
    return nullptr;
}




// Função principal para teste
int main() {
    Node* root = nullptr;

    // Inserir valores na árvore AVL
    root = insert(root, 50);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    //root = insert(root, 75);

    // Mostrar a travessia em pré-ordem
    std::cout << "ACHEI O SEGUNDO MAIOR:\n";
    std::cout<< maiorDescendente(root)->key;
    std::cout << std::endl;

    // Destruir a árvore
    destroyTree(root);

    return 0;
}
