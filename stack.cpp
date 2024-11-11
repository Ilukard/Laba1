#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class stack{
    private:
    Node *head;
    public:
    stack(): head(nullptr){}

    ~stack(){
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
        newNode->next = head;
        head = newNode;
    }

    int pop(){
        Node* delNode = head;
        head = delNode->next;
        return delNode->data;
        delete delNode;
    }
};

int main(){
    stack stc;
    stc.push(1);
    stc.push(2);
    stc.push(3);
    stc.print();
    cout << stc.pop() << endl;
    cout << stc.pop() << endl;
    stc.print();
    return 0;
}