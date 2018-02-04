#pragma once

#include <iostream>

template <class T>
class SimpleSet{
    public:
        SimpleSet();
        ~SimpleSet();
        bool insert(T i);
        bool exists(T i);
        bool remove(T i);
    private:
        T *data;
        int find(T i);
        int currentSize;
        int maxSize;       
        void resize(int n); 
};

template<class T>
SimpleSet<T>::~SimpleSet() {
    delete[] data;
}

template<class T>
SimpleSet<T>::SimpleSet(){
    maxSize = 0;
    currentSize = 0;
}

template <class T>
bool SimpleSet<T>::insert(T value){
    if(find(value) != -1){
        return false;
    }
    if (currentSize >= maxSize){
        resize(maxSize+5);
    }
    data[currentSize] = value;
    currentSize++;
    return true;
}

template <class T>
bool SimpleSet<T>::exists(T value){
    return find(value) != -1;
}

template <class T>
bool SimpleSet<T>::remove(T value){
    int index = find(value);

    if (index != -1){
        if (currentSize-1 != index)
            data[index] = data[currentSize-1];
        currentSize--;
    } else {
        return false;
    }
    return true;
}

template <class T>
int SimpleSet<T>::find(T value){
    for (int index = 0; index < currentSize; index++){
        if (data[index] == value){
            return index;
        }
    }
    return -1;
}


template <class T>
void SimpleSet<T>::resize(int newSize){
    T *newData = new T[newSize];
    for (int index = 0; index < maxSize; index++){
        newData[index] = data[index];
    }
    T *temp = data;
    data = newData;
    if (maxSize > 0)
        delete temp;
    maxSize = newSize;
    std::cout << "New size of the simple list " << newSize << std::endl;
}
