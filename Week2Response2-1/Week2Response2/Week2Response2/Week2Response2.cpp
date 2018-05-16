// Week2Response2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class A {
public:
	int a;
};

class B {
public:
	A *a;
	B() {
		this->a = 0;
	}
	B(const B &copy) {
		this->a = copy.a;
	}
};

int main()
{
	A object1;
	int num = 10;
	object1.a = num;
	A object2 = object1;
	B object3;
	object3.a = &object2;
	cout << &object2 << endl;
	cout << object3.a << endl;
	B object4 = object3;
	cout << object4.a << endl;
	object1.a = 20;

    return 0;
}

