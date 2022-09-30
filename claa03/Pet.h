#pragma once
#include <iostream>
#include <string>

using namespace std;
 
class Pet
{
	string name;
	int age;

public:
	//const string& name
	Pet(const char *name = "unnamed", int age = 0) :name(name), age(age) 
	{
		cout << "Pet constructor" << endl;
	}
	// const char *name
	/*
	Pet("happy",5);
	Pet("happy");
	Pet();
	Pet(5); (X)
	*/

	virtual ~Pet() 
	{
		cout << "Pet destructor" << endl;
	}

	string getName() { return name; }
	int getAge() { return age; }
	virtual void sleep() { cout << "sleep" << endl; }
	void eat() { cout << "eat" << endl; }


};


