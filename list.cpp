#include <iostream>

using namespace std;
//удаление по индексу
template <typename T>
struct Node {
    T val;
    Node* next;
    Node* prev;
    Node(T _val) : val(_val), next(nullptr) {}
};

template <typename T>
struct dlist {
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
            return;
        }
        head->prev = p;
        p->next = head;
        head = p;
        head->prev = nullptr;
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
            return;
        }
        tail->next = p;
        p->prev = tail;
        tail = p;
        tail->next = nullptr;
         
    }

    void del_konec(){
        Node<T>* del = new Node(0);
        if (is_empty()){
            return;
        } 
        del = tail;
        tail = del->prev;
        del->prev = nullptr;
        tail->next = nullptr;
        delete del;
     }

    void del_nachalo(){
        Node<T>* del = new Node(0);
        if (is_empty()){
            return;
        } 
        del = head;
        head = del->next;
        del->next = nullptr;
        head->prev = nullptr;
        delete del;
    }

    Node<T>* find(T value) {
        Node<T>* p = head;
        while (p && p->val != value) p = p->next;
        return (p && p->val == value) ? p : nullptr;
    }

    void del_val(T value){
        Node<T>* del = head;
        Node<T>* back = new Node(0);
        Node<T>* forvard = new Node(0);
        while (del->val != value) del = del->next;
        if (del == head){
            head = del->next;
            del->next = nullptr;
            head->prev = nullptr;
            delete del;
        } else if (del == tail){
            tail = del->prev;
            del->prev = nullptr;
            tail->next = nullptr;
            delete del;
        } else {
            forvard = del->next;
            back = del->prev;
            back->next = forvard;
            forvard->prev = back;
            delete del;
        }
    }
};


int main() {
    dlist <int> list;
    list.add_nachalo(5);
    list.add_nachalo(6);
    list.add_nachalo(11);
    list.print(); 
    list.del_val(11);
    list.print(); 
    return 0;
}