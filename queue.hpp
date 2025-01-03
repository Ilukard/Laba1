#include <iostream>
using namespace std;

template <typename T>
struct Node{
    T data;
    Node* next;
    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class queue{
    private:
    Node<T> *head;
    public:
    queue(): head(nullptr){}

    ~queue(){
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    void print(){ //O(n)
        Node<T>* current = head;
        while (current != nullptr){
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    void push(int value){ //O(1)
        Node<T>* newNode = new Node(value);
        if (head == nullptr) { // Если список пуст, новый узел становится головой
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr) { // Находим последний узел
                current = current->next;
            }
            current->next = newNode; // Присоединяем новый узел
        }
    }

    int pop(){ //O(1)
        Node<T>* delNode = head;
        head = delNode->next;
        T result = delNode->data;
        delete delNode;
        return result;
    }
};
