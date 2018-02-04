#include "SimpleSet.h"
#include <iostream>

using namespace std;

SimpleSet::SimpleSet(){
    maxSize = 0;
    currentSize = 0;
}
SimpleSet::~SimpleSet() {
    delete[] data;
}
bool SimpleSet::insert(int value){
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
bool SimpleSet::exists(int value){
    return find(value) != -1;
}
bool SimpleSet::remove(int value){
    int index = find(value);

    if (index != -1){
        if (currentSize-1 != index)
            data[index] = data[currentSize-1];
        currentSize--;
		return true;
    }
    else{
        return false;
    }
}
int SimpleSet::find(int value){
    for (int index = 0; index < currentSize; index++){
        if (data[index] == value){
            return index;
        }
    }
    return -1;
}

void SimpleSet::resize(int newSize){
    int *newData = new int[newSize];
    for (int index = 0; index < maxSize; index++){
        newData[index] = data[index];
    }
    int *temp = data;
    data = newData;
    if (maxSize > 0)
        delete temp;
    maxSize = newSize;
   // std::cout << "New size of the simple list " << newSize << std::endl;
}

void testSimpleSet(){
    SimpleSet s; 
    cout << "Inserting values into the set: "<< endl;
    for (int value = 0; value < 20; value++){
        bool t = s.insert(value);
        if (t) 
            cout << "Inserting value " << value << " into set " << endl;
        else
            cout << "Failed to insert " << value << " into set " << endl;
    }
    cout << endl << endl;
    cout << "Removing values from the set: " << endl;
    for (int value = 1; value < 20; value+=2){
        bool t = s.remove(value);
        if (t)
            cout << "Value " << value << " was removed from the set" << endl;
        else            
            cout << "Value " << value << " is not in the set" << endl;
    }
    cout << endl << endl;
    cout << "Checking for values in the set: " << endl;
    for (int value = 0; value < 10; value++){
        bool t = s.exists(value);
        if (t)
            cout << "Value " << value << " exists in the set" << endl;
        else            
            cout << "Value " << value << " is not in the set" << endl;
    }
}

int main() {
    testSimpleSet();
}