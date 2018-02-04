#include <iostream>
#include <string>
#include <forward_list>
#include <list>

using namespace std;

class Person{
private:
    string firstName;
    string lastName;
public:
    Person(string f, string l) : firstName(f), lastName(l){}
    string getFirstName(){return firstName;}
    string getLastName(){return lastName;}
    
    bool operator <(Person& p);
    friend ostream& operator <<(ostream& out, Person& p);
};

bool Person::operator <(Person& p){
    //concatenate last + first and compare
    if ((lastName + firstName) < (p.lastName + p.firstName)){
        return true;
    }
    return false;
}

ostream& operator <<(ostream& out, Person& p){
    out << p.lastName << ", " << p.firstName;
    return out;
}

void insertOrdered(forward_list<Person> &p, Person person){
    forward_list<Person>::iterator pit;
    forward_list<Person>::iterator previous;
    for (pit = p.begin(); pit != p.end(); ++pit){	//Iterate through the list
        //std::cout << *pit << endl;
        if (person  < *pit){			//until we reach an element that is larger than the element we wish to insert
            if (pit != p.begin()) {
                p.insert_after(previous, person);		//and insert out element at the found position.
            } else {
                p.push_front(person);
            }
            return;
        }
        previous = pit;
    }
    
    if (p.begin() == p.end()) {
        p.push_front(person);
        return;
    }
    
    forward_list<Person>::iterator prev = p.begin();
    for (pit = p.begin(); pit != p.end(); ++pit) {
        if (pit != p.end()) {
            prev = pit;
        }
    }
    p.insert_after(prev, person);
}

void insertOrdered(list<Person> &p, Person person){
	list<Person>::iterator pit;
	for (pit = p.begin(); pit != p.end(); ++pit){	//Iterate through the list
		if (person  < *pit){			//until we reach an element that is larger than the element we wish to insert
			p.insert(pit, person);		//and insert out element at the found position.
			return;
		}
	}
	p.push_back(person);				//If there is no element in the list larger than the one we wish to insert,
}							//the element is inserted at the back of the list.

int main(){
	cout << "forward_list:" << endl;

    forward_list<Person> persons;
    insertOrdered(persons, Person("Trond", "Aalberg"));
    insertOrdered(persons, Person("Arne", "Aalberg"));
    insertOrdered(persons, Person("Trine", "Bakke"));
    insertOrdered(persons, Person("Ola", "Norman"));
    insertOrdered(persons, Person("Kari", "Norman"));

    forward_list<Person>::iterator pit;
    for (pit = persons.begin(); pit != persons.end(); ++pit){
        cout << *pit << endl;
    }

    cout << "list:" << endl;

    list<Person> persons2;
    insertOrdered(persons2, Person("Trond", "Aalberg"));
    insertOrdered(persons2, Person("Arne", "Aalberg"));
    insertOrdered(persons2, Person("Trine", "Bakke"));
    insertOrdered(persons2, Person("Ola", "Norman"));
    insertOrdered(persons2, Person("Kari", "Norman"));
    
    list<Person>::iterator pit2;
    for (pit2 = persons2.begin(); pit2 != persons2.end(); ++pit2){
        cout << *pit2 << endl;
    }
    
    return 0;
}

/*

Teorispørsmål fra oppgave 5 g):

1) I en lenket liste kan man sette inn og fjerne elementer i konstant tid O(1), men hvis man skal finne et element må man iterere gjennom hele listen, noe som er sakte.
I en vektor er det raskt å finne et element, men det krever O(n) tid å sette inn et element. Hvis man tror at man kommer til å sette inn og fjerne elementer mye er
derfor lenkede lister mer effektive enn vektorer.

2) Se f.eks.:

http://www.labri.fr/perso/strandh/Teaching/MTP/Common/Strandh-Tutorial/queue-list.html
https://www.cs.bu.edu/teaching/c/stack/linked-list/

*/