#include <iostream>
using namespace std;

template <typename T>
struct Node{
    T data;
    Node* next;
    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class stack{
    private:
    Node<T> *head;
    public:
    stack(): head(nullptr){}

    ~stack(){
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

    void push(T value){ //O(1)
        Node<T>* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    T pop(){ //O(1)
        Node<T>* delNode = head; 
        head = delNode->next;
        T result = delNode->data;
        delete delNode;
        return result;
    }
};
