#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T val;
    Node* next;
    Node(T _val) : val(_val), next(nullptr) {}
    Node() = default;
};

template <typename T>
struct list {
    Node<T>* head;
    Node<T>* tail;

    list() : head(nullptr), tail(nullptr) {}

    bool is_empty() {
        return head == nullptr;
    }

    void push_back(T _val) {
        Node<T>* p = new Node(_val);
        if (is_empty()) {
            head = p;
            tail = p;
            return;
        }
        tail->next = p;
        tail = p;
    }

    void add_first(T _val) {
        Node<T>* p = new Node(_val);
        if (is_empty()) {
            head = p;
            tail = p;
            return;
        }
        p->next = head;
        head = p;
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

    Node<T>* find(T _val) {
        Node<T>* p = head;
        while (p && p->val != _val) p = p->next;
        return (p && p->val == _val) ? p : nullptr;
    }

    void remove_first() {
        if (is_empty()) return;
        Node<T>* p = head;
        head = p->next;
        delete p;
    }

    void remove_last() {
        if (is_empty()) return;
        if (head == tail) {
            remove_first();
            return;
        }
        Node<T>* p = head;
        while (p->next != tail) p = p->next;
        p->next = nullptr;
        delete tail;
        tail = p;
    }

    void remove(T _val) {
        if (is_empty()) return;
        if (head->val == _val) {
            remove_first();
            return;
        }
        else if (tail->val == _val) {
            remove_last();
            return;
        }
        Node<T>* slow = head;
        Node<T>* fast = head->next;
        while (fast && fast->val != _val) {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast) {
            cout << "Значение не найдено" << endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }

    Node<T>* operator[] (const int index) {
        if (is_empty()) return nullptr;
        Node<T>* p = head;
        for (int i = 0; i < index; i++) {
            p = p->next;
            if (!p) return nullptr;
        }
        return p;
    }
};
