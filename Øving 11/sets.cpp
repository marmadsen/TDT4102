#include <cstdio>
#include <set>
#include <map>
#include <iostream>

using namespace std;

void testSet(){
    set<int> integerSet;

    for (int i = 0; i < 100; i++){
        integerSet.insert(i);
    }
    

    for (int i = 0; i < 100; i += 2)
        integerSet.erase(i);

    for (int i = 3; i < 50; i++)
        for (int j = i*2; j < 100; j += i)
            integerSet.erase(j);


    for (set<int>::iterator it = integerSet.begin(); it != integerSet.end(); it++){
        cout << *it << "\t";
    }
    cout << endl;
}

int main(){
    testSet();
}
