#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class flist{
    private:
    Node *head;

    public:
    flist(): head(nullptr){}

    ~flist(){
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    //функции
    void print(){ //O(n)
        Node* current = head;
        while (current != nullptr){
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
    
    void add_konec(int value){ //O(n)
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

    void add_nachalo(int value){ //O(1)
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    
    void del_nachalo(){ //O(1)
        Node* delNode = head;
        head = delNode->next;
        delete delNode;
    }

    void del_konec(){ //O(n)
        Node* delNode = head;
        while (delNode->next->next != nullptr) { // Находим предпоследний узел
            delNode = delNode->next;
        }
        Node* predposl = delNode;
        predposl->next = nullptr;
        delNode = delNode->next;
        delete delNode;
    }
    
};



int main(){
    flist list;
    list.add_konec(1);
    list.add_konec(2);
    list.print();
    list.add_nachalo(0);
    list.add_nachalo(-1);
    list.print();
    list.del_nachalo();
    list.del_konec();
    list.print();
    return 0;
}