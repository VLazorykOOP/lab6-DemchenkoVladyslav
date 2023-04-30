#include "Lab6Example.h"
#include <iostream>
#include <string>
using namespace std;
namespace SpaceExample3 {
	class Human
	{
	protected:
		string fullName;
		unsigned unsigned int age;
		virtual void Show() = 0;
		virtual void Input() = 0;
		Human()
		{
			fullName = "Newborn";
			age = 0;
		}
		Human(string fN, unsigned unsigned int a)
		{
			fullName = fN;
			age = a;
		}
		virtual ~Human()
		{
			cout << "Deleted " << fullName << endl;
		}
	};
	class Father :virtual public Human
	{
	public:
		virtual void Show() override
		{
			cout << "Father:" << endl;
			cout << fullName << endl;
			cout << "Age: " << age << endl;
		}
		virtual void Input() override
		{

		}
		Father(string fN, unsigned int a) : Human(fN, a) {

		}
	};
	class Mother : virtual public Human
	{
	public:
		virtual void Show() override
		{
			cout << "Mother:" << endl;
			cout << fullName << endl;
			cout << "Age: " << age << endl;
		}
		virtual void Input() override
		{

		}
		Mother(string fN, unsigned int a) : Human(fN, a) {

		}
	};
	class Daughter1 : virtual public Human
	{
	public:
		Mother mother;
		Father father;
		Daughter1(string fN, unsigned int a, Mother m, Father f) : Human(fN, a), mother(m), father(f)
		{

		}
		virtual void Show() override
		{
			father.Show();
			mother.Show();
			cout << "Daughter:" << endl;
			cout << fullName << endl;
			cout << "Age: " << age << endl;
		}
		virtual void Input() override
		{

		}
	};
	class Daughter2 : virtual public Father, virtual public Mother, public virtual Human
	{
	public:
		Daughter2(string fN, unsigned int a, Mother m, Father f) : Human(fN, a), Mother(m), Father(f)
		{

		}
		virtual void Show() override
		{
			Mother::Show();
			Father::Show();
			cout << "Daughter:" << endl;
			cout << fullName << endl;
			cout << "Age: " << age << endl;
		}
		virtual void Input() override
		{

		}
	};
	int mainExample3()
	{
		//Human h = Human("Human 1", 18); не можна створити об'єкт абстрактного класу
		Mother m = Mother("Mother 1", 33);
		Father f = Father("Father 1", 34);
		Daughter1 d1 = Daughter1("Daughter 1", 12, m, f);
		Daughter2 d2 = Daughter2("Daughter 2", 9, m, f);
		m.Show();
		f.Show();
		d1.Show();
		d2.Show();
		return 0;
	}


}