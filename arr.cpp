#include <iostream>
using namespace std;

struct array{
   int vmest; 
   int dlina;
   int *data;
   
   //Конструктор
   array(int init_vmest): dlina(0), vmest(init_vmest){
       data = new int[init_vmest];
   }
   //Деструктор
   ~array() {
        delete[] data;
    }
    //Итераторы на начало и конец
    int* begin() {
        return data;
    }
    int* end() {
        return data + dlina;
    }
    //Функции пошли
    
    void add(int value) { //O(1)
        data[dlina++] = value;
    }
    
    void add_index(int index, int value){ //O(1)
        data[index] = value;
    }
    
    int get_index(int index){ //O(1)
        return data[index];
    }
    
    void del_index(int index){ //O(n)
        for (int i = index; i<dlina; i++){
            data[i] = data[i + 1];
        }
        dlina--;
    }
    
    void zamena(int index, int value){ //O(1)
        data[index] = value;
    }
    
    int get_dlina(){ //O(1)
        return dlina;
    }
    //изменение вместимости
    void resize(int new_capacity) {
        int* new_data = new int[new_capacity];
        for (int i = 0; i < dlina; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        vmest = new_capacity;
    }
    
    void print(){ //O(n)
        for (int* it = begin(); it != end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
};

int main(){
    array arr(10);
    
    arr.add(1);
    arr.add(2);
    arr.add(3);
    arr.add(4);
    arr.add(11);
    arr.add_index(4, 5);
    cout << "1 index = " << arr.get_index(1) << endl;
    arr.del_index(1);
    arr.print();
    return 0;
}