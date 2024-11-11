#include <iostream>

using namespace std;

// Структура узла двусвязного списка
struct Node {
    int data;
    Node *prev;
    Node *next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Функция для добавления элемента в конец списка
void append(Node **head, int data) { //O(1)
    Node *newNode = new Node(data);
    if (!*head) {
        *head = newNode;
        return;
    }

    Node *last = *head;
    while (last->next) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

// Функция для поиска элемента в списке
Node *find(Node *head, int key) { //O(n)
    Node *current = head;
    while (current) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Функция для удаления элемента из списка
void remove(Node **head, int key) { //O(n)
    Node *nodeToDelete = find(*head, key);
    if (!nodeToDelete) {
        return;
    }

    if (nodeToDelete == *head) {
        *head = nodeToDelete->next;
        if (*head) {
            (*head)->prev = nullptr;
        }
    } else {
        if (nodeToDelete->prev) {
            nodeToDelete->prev->next = nodeToDelete->next;
        }
        if (nodeToDelete->next) {
            nodeToDelete->next->prev = nodeToDelete->prev;
        }
    }

    delete nodeToDelete;
}

// Функция для вывода списка
void printList(Node *head) { //O(n)
    Node *current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node *head = nullptr;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 25);
    append(&head, 5);

    cout << "Двусвязный список: ";
    printList(head);

    remove(&head, 20);

    cout << "После удаления 20: ";
    printList(head);

    if (find(head, 25)) {
        cout << "25 найдено." << endl;
    } else {
        cout << "25 не найдено." << endl;
    }

    return 0;
}