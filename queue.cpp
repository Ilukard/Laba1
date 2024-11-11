#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class queue{
    private:
    Node *head;
    public:
    queue(): head(nullptr){}

    ~queue(){
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    void print(){
        Node* current = head;
        while (current != nullptr){
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    void push(int value){
        Node* newNode = new Node(value);
        if (head == nullptr) { // Если список пуст, новый узел становится головой
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) { // Находим последний узел
                current = current->next;
            }
            current->next = newNode; // Присоединяем новый узел
        }
    }

    int pop(){
        Node* delNode = head;
        head = delNode->next;
        return delNode->data;
        delete delNode;
    }
};

int main(){
    queue och;
    och.push(1);
    och.push(2);
    och.push(3);
    och.print();
    cout << och.pop() << endl;
    cout << och.pop() << endl;
    och.print();
    return 0;
}