#pragma once

#include <iostream>
using namespace std;

template <typename T>
class Array{
    public:
   int vmest; 
   int dlina;
   T *data;
   
   //Конструктор
   Array(int init_vmest): dlina(0), vmest(init_vmest){
       data = new T[init_vmest];
   }
   //Деструктор
   ~Array() {
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
    
    void add(T value) { //O(1)
        data[dlina++] = value;
    }
    
    void add_index(int index, T value){ //O(1)
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
    
    void zamena(int index, T value){ //O(1)
        data[index] = value;
    }
    
    int get_dlina(){ //O(1)
        return dlina;
    }
    //изменение вместимости
    void resize(int new_capacity) {
        T* new_data = new int[new_capacity];
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

