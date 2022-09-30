#define _CRT_SECURE_NO_WARINGS

#include <iostream>
#include <string>
#include "Dog.h"
#include "Utils.h"

using namespace std;

/*
// ���� ����
// string _somethingHidden("unhappy");
// const char *_somethingHidden = "unhappy";
Pet unhappy("unhappy", 0); // ���� ����
// unhappy("unhappy",0);�� �� const char *name ���� �Ǿ������� 
// unhappy�� char�ڷ�������, ���ڿ��� �����ؼ� ���� �� - ���� ���� (���� ������ ȣ�� X)
Pet& anotherUnhappy = unhappy;
Pet* anotherAnotherUnhappy = &unhappy;
// anotherAnotherUnhappy->name = "hello"; �̷��� �ϸ� �̸��� "unhappy"���� "hello"�� �ٲ��.
*/

int main()
{ 
// ���� ���� 
// 
	// Dog happy = Dog("happy", 4, 3); ������ + ���� ������
	// Dog happy("happy", 4, 3);
	Pet *happy = new Dog("happy", 4, 3); 
	// ���� dog�� �����ڰ� ȣ�������, dog�� pet�� �����ؼ� pet�� ���� �����Ǽ� pet�� ���� ȣ��ǰ�,
	// ���� dog�Լ��� ����Ǹ鼭 dog�����ڵ� ȣ���Ѵ�.
	// Dog another_happy(happy); // ���������
	// 
	// 	Pet *happy = new Dog("happy", 4, 3);  �̷��� �ٲٸ� happy�� �׳� pet�̶� dog�� bark�� �� �� ����.
	// 
	// cout << happy.getName() << endl;
	cout << happy->getName() << endl; // �θ𿡰� ��ӹ޾Ƽ� dog�� �������� �ʾƵ� ��� ����
	// ��� ������ �������� �θ��� �޼��带 ����� �� �ִ�.
	// �����ϰ� ���� ��� �θ��Լ��� virtual�� �Ἥ ������ �ش�.
	/*
	Pet* pet = &happy; // ��ĳ����, �θ� �ڽ��� ����
	
	happy.bark();
	happy.eat();
	happy.sleep();
	*/

	Pet* pet = happy;

	// happy->bark();
	happy->eat();
	happy->sleep();

	// pet->bark(); ��ĳ�����ϸ� dog�� �޼ҵ�� ��������
	pet->eat();
	pet->sleep();

	((Dog*)pet)->bark(); // �ٿ�ĳ����, �������� ������ ��� ��������

	(static_cast<Dog*>(pet))->bark(); // pet�̶�� �����͸� dog��� �����ͷ� �ٲ��ּ���
	// �̷��� �ٲٴ°� �����ϴ�.

	delete happy; 
	// happy�� Pet�� �����Ϳ��� happy �Ҹ��ڰ� ȣ��ȴ�. 
	// ������, ���� ������� ���� dog���� 
	// delete (static_cast<Dog*>(happy)); �ٿ� ĳ������ �ؼ� dog�Ҹ��ڸ� ȣ���Ѵ�.
	// �ƴϸ� virtual�� pet�Ҹ��ڿ� �ۼ��ؼ� dog�Ҹ��ڸ� ȣ���Ѵ�.

	return 0;
}