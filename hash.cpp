#include <iostream>
#include <string>

using namespace std;

class HashTable {
private:
    struct Node {
        string key;
        int value;
        Node* next;

        Node(const string& k, int v) : key(k), value(v), next(nullptr) {}
    };

    Node** table;
    int capacity;
    int size;

    int hash(const string& key) {
        int hashValue = 0;
        for (char ch : key) {
            hashValue += static_cast<int>(ch);
        }
        return hashValue % capacity;
    }

public:
    HashTable(int cap = 10) : capacity(cap), size(0) {
        table = new Node*[capacity];
        for (int i = 0; i < capacity; i++) {
            table[i] = nullptr;
        }
    }

    ~HashTable() {
        for (int i = 0; i < capacity; i++) {
            Node* current = table[i];
            while (current) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    void insert(const string& key, int value) {
        int index = hash(key);
        Node* newNode = new Node(key, value);

        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {                                //метод цепочек
            Node* current = table[index];
            while (current->next) {
                if (current->key == key) {
                    current->value = value;
                    delete newNode;
                    return;
                }
                current = current->next;
            }
            if (current->key == key) {
                current->value = value;
                delete newNode;
            } else {
                current->next = newNode;
            }
        }
        size++;
    }

    int get(const string& key) {
        int index = hash(key);
        Node* current = table[index];

        while (current) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }

        throw out_of_range("Ключ не найден");
    }

    void remove(const string& key) {
        int index = hash(key);
        Node* current = table[index];
        Node* prev = nullptr;

        while (current) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                size--;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    int getSize() {
        return size;
    }
};

int main() {
    HashTable hashTable;

    hashTable.insert("яблоки", 5);
    hashTable.insert("молоко", 10);
    hashTable.insert("огурцы", 7);

    cout << "значение для 'яблоки': " << hashTable.get("яблоки") << endl;
    cout << "значение для 'молоко': " << hashTable.get("молоко") << endl;
    cout << "значение для 'огурцы': " << hashTable.get("огурцы") << endl;

    hashTable.remove("молоко");

    cout << "Size after removing 'молоко': " << hashTable.getSize() << endl;

    try {
        cout << "значение для 'молоко' after removal: " << hashTable.get("молоко") << endl;
    } catch (const out_of_range& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}