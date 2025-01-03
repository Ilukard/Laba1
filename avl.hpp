//надо написать еще принт

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Структура узла АВЛ-дерева
struct node {
    int info;
    node* left;
    node* right;
    int balance;

    node(int info) : info(info), left(nullptr), right(nullptr), balance(0) {}
    ~node() {
        delete left;
        delete right;
    }
};


// Структура АВЛ-дерева
class AVL {
private:
    node* root;

    // Вычисление высоты дерева
    int Height(node* current) const {
        return current == nullptr ? 0 : max(Height(current->left), Height(current->right)) + 1;
    }

    // Вычисление баланса узла
    void SetBalance(node* current) {
        if (current != nullptr) {
            current->balance = Height(current->left) - Height(current->right);
         }
    }
   
    // Правый поворот
  void TurnRight(node*& current) {
           node* leftSubtree = current->left;
            node* leftSubtreeRightSubtree = leftSubtree->right;
            leftSubtree->right = current;
            current->left = leftSubtreeRightSubtree;
            current = leftSubtree;
          SetBalance(current->right);
           SetBalance(current);
    }

    // Левый поворот
    void TurnLeft(node*& current) {
        node* rightSubtree = current->right;
        node* rightSubtreeLeftSubtree = rightSubtree->left;
        rightSubtree->left = current;
        current->right = rightSubtreeLeftSubtree;
        current = rightSubtree;
         SetBalance(current->left);
        SetBalance(current);
    }
   
    void insert(node*& current, int d){
        if (current == nullptr) {
          current = new node(d);
            return;
        }

        if (d > current->info) {
            insert(current->right, d);
        } else if (d < current->info) {
            insert(current->left, d);
        }else{
          return;
        }
         SetBalance(current);
         
         if(current->balance > 1){
          if(current->right->balance < 0)
            TurnRight(current->right);
           TurnLeft(current);
        }
          else if(current->balance < -1){
          if(current->left->balance > 0)
           TurnLeft(current->left);
            TurnRight(current);
        }
    }
     
   node* find(node* current, int d) {
        if (current == nullptr || current->info == d)
          return current;
        if (d < current->info)
         return find(current->left, d);
        else
         return find(current->right, d);
    }
    
   node* findMin(node* current) {
        while (current->left != nullptr) {
           current = current->left;
        }
         return current;
    }

   void remove(node*& current, int d){
        if (current == nullptr)
           return;

       if (d < current->info) {
          remove(current->left, d);
       }
      else if (d > current->info) {
        remove(current->right, d);
       }
       else {
              if (current->left == nullptr || current->right == nullptr) {
              node* temp = current->left != nullptr ? current->left : current->right;
              delete current;
              current = temp;
              } else {
                 node* temp = findMin(current->right);
                 current->info = temp->info;
                remove(current->right, temp->info);
                }
          }
        if(current == nullptr)
          return;
       SetBalance(current);
     if(current->balance > 1){
         if(current->right->balance < 0)
            TurnRight(current->right);
         TurnLeft(current);
        }
       else if(current->balance < -1){
           if(current->left->balance > 0)
            TurnLeft(current->left);
            TurnRight(current);
       }
  }
   


public:
    AVL() : root(nullptr) {}
    ~AVL() { delete root; }

    void insert(int d) {
        insert(root, d);
    }

    void remove(int d) {
        remove(root, d);
    }
     
    bool find(int d){
     return find(root, d) != nullptr;
    }

    void printTree(){

    }
    
};


int main() {
    AVL tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(25);
    tree.insert(5);
    tree.insert(8);
    tree.insert(3);

    cout << "AVL Дерево: " << endl;
    tree.printTree();
    cout << endl;

    tree.remove(20);
    cout << "AVL Дерево (после удаления 20): " << endl;
    tree.printTree();
    cout << endl;

    if (tree.find(25)) {
        cout << "Найдено" << endl;
    } else {
        cout << "Не найдено" << endl;
    }

    return 0;
}