#include <iostream>
#include <string>
#include <vector>
#include <locale.h>
using namespace std;

void replace(vector<string> &myVector, string find, string replace){
	vector<string>::iterator it;
	for(it = myVector.begin(); it != myVector.end(); ++it){	//Iterates through the vector
		if(*it == find){				//When a matching string is found
			it = myVector.erase(it);		//it is erased
			it = myVector.insert(it, replace);	//and the new string is inserted at the current position
		}
	}
}

int main(){
	vector<string> v;
	v.push_back("C++");
	v.push_back("and");
	v.push_back("iterators");
	v.push_back("are");
	v.push_back("power");

	vector<string>::iterator vit;
	for (vit = v.begin(); vit != v.end(); ++vit)
		cout << *vit << " ";
	cout << endl;
	
	vector<string>::reverse_iterator rit;
	for ( rit=v.rbegin() ; rit < v.rend(); ++rit ){
		cout << *rit << " ";
	}
	cout << endl;

	replace(v, "are", "is");
	
	for ( rit=v.rbegin() ; rit < v.rend(); ++rit ){
		cout << *rit << " ";
	}
	cout << endl;
	
	return 0;
}
