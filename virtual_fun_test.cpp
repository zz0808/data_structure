#include <iostream>
using namespace std;

class A {
public:
	A() {
		cout << "I am construct A" << endl;
		fun();
	}
	~A() {
		cout << "I am destroy A" << endl;
		fun();
	} 
	virtual void fun() {
		cout << "I am  fun A" << endl;
	}
};

class B : public A{
public:
	B() {
		cout << "I am construct B" << endl;
		fun();
	}
	~B() {
		cout << "I am destroy B" << endl;
		fun();
	} 
	void fun() {
		cout << "I am  fun B" << endl;
	}
};

int main() {

	A* a = new B();
	a->fun();
	delete a;
	return 0;
}