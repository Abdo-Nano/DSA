//
// Created by nano on 11/13/24.
//

#ifndef ARRAY_H
#define ARRAY_H

#endif //ARRAY_H
#include <cassert>
#include <iostream>
using namespace std;

class DynamicArray {
private:
    int *arr{nullptr};
    int size{0};
    int capacity{};
    void extendCapacity() {
        capacity *= 2;
        int *secondArr = new int[capacity]{};
        for(int i = 0 ;i < size ;i++) {
            secondArr[i] = arr[i];
        }
        swap(arr , secondArr);
        delete[] secondArr;
    }
public:

    DynamicArray(int size) {
        this->size = size;
        capacity = size * 2;
        arr = new int[capacity]{};
    }

    void push_back(int item){
       if(size == capacity)
           extendCapacity();
       arr[size++] = item;

    }

    void insert(int index , int value) {
        assert(index >= 0 && index < size);
        if(size == capacity)
            extendCapacity();
        for(int i = size -1 ;i >= index ;i--) {
            arr[i+1] = arr[i];
        }
        arr[index] = value;
        size++;
    }
    void display() {
        for(int i = 0 ;i < size;i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    void righRotation() {
        int last = arr[size-1];
        for(int i = size -2;i >= 0 ;i--){
            arr[i+1] = arr[i];
        }
        arr[0] = last;
    }
    void pop(int index) {
        for(int i = index ;i < size -1 ;i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }
    int getFront(){return arr[0];}
    int getBack(){return arr[size -1];}




};