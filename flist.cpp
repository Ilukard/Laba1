#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T val;
    Node* next;

    Node(T _val) : val(_val), next(nullptr) {}
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
            cout << "This element does not exist" << endl;
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

int main()
{
    list <string> l;
    cout << l.is_empty() << endl;
    l.push_back("3");
    l.push_back("123");
    l.push_back("8");
    l.print();
    cout << l.is_empty() << endl;
    l.remove("123");
    l.print();
    l.push_back("1234");
    l.remove_first();
    l.print();
    l.remove_last();
    l.print();
    cout << l[0]->val << endl;
    return 0;
}