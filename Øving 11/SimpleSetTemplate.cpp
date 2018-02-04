#include "SimpleSetTemplate.h"

using namespace std;

void testSimpleSetTemplate() {
    SimpleSet<double> s; 
    cout << "Inserting values into the set: "<< endl;
    for (double value = 0; value < 20; value++){
        bool t = s.insert(value);
        if (t) 
            cout << "Inserting value " << value << " into set " << endl;
        else
            cout << "Failed to insert " << value << " into set " << endl;
    }
    cout << endl << endl;
    cout << "Removing values from the set: " << endl;
    for (double value = 1; value < 20; value+=2){
        bool t = s.remove(value);
        if (t)
            cout << "Value " << value << " was removed from the set" << endl;
        else            
            cout << "Value " << value << " is not in the set" << endl;
    }
    cout << endl << endl;
    cout << "Checking for values in the set: " << endl;
    for (double value = 0; value < 10; value++){
        bool t = s.exists(value);
        if (t)
            cout << "Value " << value << " exists in the set" << endl;
        else            
            cout << "Value " << value << " is not in the set" << endl;
    }
}

int main() {
	testSimpleSetTemplate();
}