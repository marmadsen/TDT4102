#include <iostream>
#include <cstdlib>
#include "DynamicMemory.h"
#include "Matrix.h"

using namespace std;

int main()
{
	// Oppgave 1
	{
		createFibonacci();
	}

	// Oppgave 2
	{
		Matrix Invalid;
		Matrix A(4, 2);
		Matrix B(4);

		cout << Invalid.isValid() << endl;  // 0
		cout << A.isValid() << endl;        // 1
		cout << B.isValid() << endl;        // 1 

		cout << Invalid << endl;
		cout << A << endl;
		cout << B << endl;

		B.set(2, 3, 5.0);
		cout << B << endl;

		cout << B.get(2, 3) << endl;
	}

	// Oppgave 3
	{
		Matrix A(3), B(4);
		A = B;
		Matrix C(A);
		Matrix D = B;
	}

	// Oppgave 4 og 5
	{
		Matrix A(2), B(2), C(2);
		A.set(0, 0, 1.0);
		A.set(0, 1, 2.0);
		A.set(1, 0, 3.0);
		A.set(1, 1, 4.0);

		B.set(0, 0, 4.0);
		B.set(0, 1, 3.0);
		B.set(1, 0, 2.0);
		B.set(1, 1, 1.0);

		C.set(0, 0, 1.0);
		C.set(0, 1, 3.0);
		C.set(1, 0, 1.5);
		C.set(1, 1, 2.0);

		cout << "A = " << A << endl;
		cout << "B = " << B << endl;
		cout << "C = " << C << endl;

		A += (B + C);

		cout << "A + B + C = " << A << endl;
	}

	return 0;
}
