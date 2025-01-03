#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T val;
    Node* next;
    Node* prev;
    Node(T _val) : val(_val), next(nullptr) {}
    Node() = default;
};

template <typename T>
class dlist {
    public:
    Node<T>* head;
    Node<T>* tail;

    dlist() : head(nullptr), tail(nullptr) {}

    bool is_empty() {
        return head == nullptr;
    }

    void add_nachalo(T value){
        Node<T>* p = new Node(value);
        if (is_empty()){
            head = p;
            tail = p;
            cout << "Список создан" << endl;
            return;
        }
        head->prev = p;
        p->next = head;
        head = p;
        head->prev = nullptr;
        cout << "Значение добавлено" << endl;
    }

    void print() {
        if (is_empty()) return;
        Node<T>* p = head;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

    void add_konec(T value){
        Node<T>* p = new Node(value);
        if (is_empty()){
            head = p;
            tail = p;
            cout << "Список создан" << endl;
            return;
        }
        tail->next = p;
        p->prev = tail;
        tail = p;
        tail->next = nullptr;
        cout << "Значение добавлено" << endl;
    }

    void del_konec(){
        Node<T>* del = new Node<T>;
        if (is_empty()){
            cerr << "Список пуст" << endl;
            return;
        } 
        del = tail;
        tail = del->prev;
        del->prev = nullptr;
        tail->next = nullptr;
        delete del;
        cout << "Удалено" << endl;
     }

    void del_nachalo(){
        Node<T>* del = new Node<T>;
        if (is_empty()){
            cerr << "Список пуст" << endl;
            return;
        } 
        del = head;
        head = del->next;
        del->next = nullptr;
        head->prev = nullptr;
        delete del;
        cout << "Удалено" << endl;
    }

    Node<T>* find(T value) {
        Node<T>* p = head;
        while (p && p->val != value) p = p->next;
        return (p && p->val == value) ? p : nullptr;
    }

    void del_val(T value){
        if (is_empty()){
            cerr << "Список пуст" << endl;
            return;
        } 
        Node<T>* del = head;
        Node<T>* back = new Node<T>;
        Node<T>* forvard = new Node<T>;
        while (del->val != value) {
            del = del->next;
            if (del == nullptr){
                cerr << "Значение не найдено" << endl;
                return;
            }
        }
        if (del == head){
            head = del->next;
            del->next = nullptr;
            head->prev = nullptr;
            delete del;
            cout << "Удалено" << endl;
        } else if (del == tail){
            tail = del->prev;
            del->prev = nullptr;
            tail->next = nullptr;
            delete del;
            cout << "Удалено" << endl;
        } else {
            forvard = del->next;
            back = del->prev;
            back->next = forvard;
            forvard->prev = back;
            delete del;
            cout << "Удалено" << endl;
        }
    }
};
