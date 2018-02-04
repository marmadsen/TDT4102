#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

template<typename T>
void shuffle(T a[], int size){
	for (int i = 0; i < size - 1; i++){
		int j = rand() % (size - i);
		T tmp = a[i];
		a[i] = a[i + j];
		a[i + j] = tmp;
	}

}

template<typename T>
T maximum(T a, T b){
	
	if (b < a){
		return a;
	}else{
		return b;
	}
}

int main(){
	srand(time(NULL));
	
	int a[] = {1,2,3,4,5,6,7};
	shuffle(a, 7);
	for (int i = 0; i < 7; i ++){
		cout << a[i] << " ";
	}
	cout << endl;

	double b[] = {1.1, 2.2, 3.3, 4.4};
	shuffle(b, 4);
	for (int i = 0; i < 4; i ++){
		cout << b[i] << " ";
	}
	cout << endl;

	string c[] = {"one", "two", "three", "four"};
	shuffle(c, 4);
	for (int i = 0; i < 4; i ++){
		cout << c[i] << " ";
	}
	cout << endl << endl;

	
	cout << "maximum(1, 2) = " << maximum(1, 2) << endl;
	cout << "maximum(1.0, 2.3) = " << maximum(1.0, 2.3) << endl;
	cout << "maximum('X', 'Y') = " <<maximum('X', 'Y') << endl;
	cout << "maximum(string(\"tre\"), string(\"fire\")) = " << maximum(string("tre"), string("fire")) << endl;
	
	return 0;
	
}
