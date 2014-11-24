#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
	string Name;
	int Age;
public:
	Person()
	{
		Name = "Default name";
		Age = 1;
	}
	void SayHello()
	{
		cout << "Hello. I'm person" << endl;
	}
	void SetName(string Name)
	{
		for (int i = 0; i < Name.length(); i++)
		{
			if (Name[i] > '0' && Name[i] < '9')
			{
				cout << "Wrong name set" << endl;
				return;
			}
		}
		this->Name = Name;
	
	}
	void SetAge(int Age)
	{
		if (Age > 0 && Age < 150)
		{
			this->Age = Age;
		}
		else {
			cout << "Wrong age set" << endl;
		}
	}
	void Show()
	{
		cout << Name << " | " << Age << endl;
	}
};

class Student : public Person
{
public:
	Student() {}
	Student(string Name, int Age)
	{
		SetName(Name);
		SetAge(Age);
	}
	void SetAge(int Age)
	{
		if (Age > 15 && Age < 40)
		{
			this->Age = Age;
		}
		else
		{
			cout << "Wrong age set" << endl;
		}
	}
	void SayHello()
	{
		cout << "Hello, I'm student" << endl;
	}

};

void main()
{
	Person p;
	p.SetName("Alex");
	p.SetAge(48);
	p.SayHello();
	p.Show();

	Student s("Ivan", 20);
	s.SayHello();
	s.Show();
	
	system("pause");
}