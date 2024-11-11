#include <iostream>
#include <algorithm>

using namespace std;

// Структура узла АВЛ-дерева
struct Node {
    int key;
    int height;
    Node *left;
    Node *right;

    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

// Функция для получения высоты узла
int height(Node *node) {
    return node ? node->height : 0;
}

// Функция для обновления высоты узла
void updateHeight(Node *node) {
    if (node) {
        node->height = max(height(node->left), height(node->right)) + 1;
    }
}

// Функция для расчета баланса узла
int balanceFactor(Node *node) {
    return node ? height(node->right) - height(node->left) : 0;
}

// Функция для малого левого поворота
Node *rotateLeft(Node *y) {
    Node *x = y->right;
    Node *T2 = x->left;

    x->left = y;
    y->right = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Функция для малого правого поворота
Node *rotateRight(Node *x) {
    Node *y = x->left;
    Node *T2 = y->right;

    y->right = x;
    x->left = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Функция для балансировки узла
Node *balance(Node *node) {
    updateHeight(node);
    int bf = balanceFactor(node);

    if (bf > 1) {
        if (balanceFactor(node->right) < 0) {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }
    if (bf < -1) {
        if (balanceFactor(node->left) > 0) {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }

    return node;
}

// Функция для вставки элемента в АВЛ-дерево
Node *insert(Node *node, int key) { //O(log n)
    if (!node) {
        return new Node(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node; // Ключ уже существует
    }

    return balance(node);
}

// Функция для поиска элемента в АВЛ-дереве
Node *find(Node *node, int key) { //O(log n)
    if (!node || node->key == key) {
        return node;
    }

    if (key < node->key) {
        return find(node->left, key);
    } else {
        return find(node->right, key);
    }
}

// Функция для поиска минимального узла в поддереве
Node *findMin(Node *node) {
    while (node->left) {
        node = node->left;
    }
    return node;
}

// Функция для удаления элемента из АВЛ-дерева
Node *remove(Node *node, int key) { //O(log n)
    if (!node) {
        return nullptr;
    }

    if (key < node->key) {
        node->left = remove(node->left, key);
    } else if (key > node->key) {
        node->right = remove(node->right, key);
    } else {
        if (!node->left || !node->right) {
            Node *temp = node->left ? node->left : node->right;
            if (!temp) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }
            delete temp;
        } else {
            Node *temp = findMin(node->right);
            node->key = temp->key;
            node->right = remove(node->right, temp->key);
        }
    }

    if (!node) {
        return nullptr;
    }

    return balance(node);
}

// Вспомогательная функция для рекурсивного вывода дерева с отступами
void printTreeHelper(Node *node, string indent, bool last) { //O(log n)
    if (node) {
        cout << indent;
        if (last) {
            cout << "\\----";
            indent += "     ";
        } else {
            cout << "|----";
            indent += "|    ";
        }

        cout << node->key << endl;

        printTreeHelper(node->left, indent, false);
        printTreeHelper(node->right, indent, true);
    }
}

// Функция для вывода дерева в древовидном формате
void printTree(Node *node) {
    printTreeHelper(node, "", true);
}

int main() {
    Node *root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 25);
    root = insert(root, 5);

    cout << "AVL Дерево: " << endl;
    printTree(root);
    cout << endl;

    root = remove(root, 20);

    cout << "После удаления 20: " << endl;
    printTree(root);
    cout << endl;

    if (find(root, 25)) {
        cout << "25 найдено." << endl;
    } else {
        cout << "25 не найдено." << endl;
    }

    return 0;
}