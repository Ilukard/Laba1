#include <iostream>
#include <list>
#include <vector>

using namespace std;

class HashTable {
private:
    int capacity;
    vector<list<int>> table;

    // Простая хеш-функция
    int hashFunction(int key) {
        return key % capacity;
    }

public:
    HashTable(int cap) : capacity(cap) {
        table.resize(capacity);
    }

    // Функция для вставки элемента в хеш-таблицу
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // Функция для поиска элемента в хеш-таблице
    bool search(int key) {
        int index = hashFunction(key);
        for (int x : table[index]) {
            if (x == key) {
                return true;
            }
        }
        return false;
    }

    // Функция для удаления элемента из хеш-таблицы
    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    // Функция для вывода содержимого хеш-таблицы
    void printTable() {
        for (int i = 0; i < capacity; ++i) {
            cout << "Ячейка " << i << ": ";
            for (int x : table[i]) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(10);

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(5);
    ht.insert(25);

    cout << "Хэш-таблица:" << endl;
    ht.printTable();

    if (ht.search(15)) {
        cout << "15 найдено." << endl;
    } else {
        cout << "15 не найдено." << endl;
    }

    ht.remove(15);

    cout << "После удаления 15:" << endl;
    ht.printTable();

    return 0;
}