#include <iostream>
#include "arr.hpp"
#include "flist.hpp"
using namespace std;

class Hash{
    public:
    list<pair<string, int>>* data; //массив списков пар строк и интов
    int capacity, size; 

    Hash(int capacity_): capacity(capacity_), size(0), data(new list<pair<string, int>>[capacity_]) {}

    ~Hash() { delete[] data; }

    int get_hash_index(string key){
        int result = key.length();
        return result % capacity;
    }

    void add(string key, int val){
        int index = get_hash_index(key);
        pair <string, int> para(key, val);

        if (data[index].is_empty()){
            cout << "В ячейку положили первый элемент" << endl;
        } else {
            cout << "Коллизия" << endl;
        }

        data[index].push_back(para);
        size++;
    }

    int get(string key) {
        int index = get_hash_index(key);
        Node<pair<string, int>>* p = data[index].head;

        if (data[index].is_empty()) {
            cout << "Тут ничего нет" << endl;
            return 0;
        }

       while (p != nullptr) {
            if (p->val.first == key) {
                return p->val.second;
            }
            p = p->next;
        }

        cout << "Ключ не найден" << endl;
        return 0;
    }

    void remove(string key){
        int index = get_hash_index(key);
        Node<pair<string, int>>* p = data[index].head;
        Node<pair<string, int>>* prev = nullptr;

        if (data[index].is_empty()){
           cout << "Элемента нет" << endl;
           return;
        }

        while (p != nullptr) {
            if (p->val.first == key) {
                if (prev == nullptr) {
                    data[index].head = p->next;
                    
                } else {
                   prev->next = p->next;
                }
                delete p;
                size--;
                cout << "Элемент удален" << endl;
                return;
            }
            prev = p;
            p = p->next;
        }
        cout << "Элемента нет" << endl;

    }

    int get_size() {
        return size;
    }
    
};
