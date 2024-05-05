#include <iostream>

using namespace std;

class Person {

protected:

	string name;
	int age;

public:

	Person() {

		this->name = "Человек 1";
		this->age = 100;
	}

	Person(string personName, int personAge) {

		this->name = personName;
		this->age = personAge;
	}

	Person(const Person& somePerson) {

		this->name = somePerson.name;
		this->age = somePerson.age;
	}

	~Person() { cout << "\nДекструктор класса Person\n"; }

	void setName(string& personName) {
		this->name = personName;
	}

	void setAge(int& personAge) {
		this->age = personAge;
	}

	void getInfo() { cout << "Имя: " << name << endl << "Возраст: " << age << endl; }

	Person& operator =(const Person& newPerson) {

		cout << "\nВызов оператора '=' для класса Person\n";

		this->name = newPerson.name;
		this->age = newPerson.age;

		return *this;
	}

	friend ostream& operator<<(ostream&, const Person&);
	friend istream& operator>>(istream&, Person&);
};

ostream& operator<<(ostream& outPut, const Person& a) {

	outPut << "Имя: " << a.name << endl << "Возраст: " << a.age << endl;
	
	return outPut;
}

istream& operator>>(istream& inPut, Person& a) {

	cout << "Введите имя: "; inPut >> a.name;
	cout << "\nВведите возраст: "; inPut >> a.age;

	return inPut;
}

class Student : Person {
	
	string subject;
	int grade;

public:

	Student() {

		this->name = "Иван";
		this->age = 10;
		this->grade = 4;
		this->subject = "Математика";
	}

	Student(string name, int age, string subject, int grade) {

		this->name = name;
		this->age = age;
		this->subject = subject;
		this->grade = grade;
	}

	Student(const Student& someStudent) {

		this->name = someStudent.name;
		this->age = someStudent.age;
		this->grade = someStudent.grade;
		this->subject = someStudent.subject;
	}

	~Student() { cout << "\nДеструктор класса Student\n"; }
	
	void getInfo() {

		cout << "Имя: " << name << endl << "Возраст: " << age << endl << "Предмет: " << subject << endl << "Оценка: " << grade << endl;
		if (grade < 3) cout << grade << " - неудовл. оценка.\n";
	}

	void setName(string& name) {
		this->name = name;
	}

	void setAge(int& age) {
		this->age = age;
	}

	void setSubj(string& subject) {
		this->subject = subject;
	}

	void setGrade(int& mark) {
		this->grade = mark;
	}

	Student& operator =(const Student& user) {

		cout << "\nВызов оператора '=' для класса Student\n";

		this->name = user.name;
		this->age = user.age;
		this->subject = user.subject;
		this->grade = user.grade;

		return *this;
	}

	friend ostream& operator<<(ostream&, const Student&);
	friend istream& operator>>(istream&, Student& );
};

ostream& operator<<(ostream& outPut, const Student& a) {

	outPut << "Имя: " << a.name << endl << "Возраст: " << a.age << endl << "Предмет: " << a.subject << endl << "Оценка: " << a.grade << endl;
	if (a.grade < 3) cout << a.grade << " - неудовл. оценка.\n";
	return outPut;
}

istream& operator>>(istream& inPut, Student& a) {

	cout << "Введите имя: "; inPut >> a.name;
	cout << "\nВведите возраст: "; inPut >> a.age;
	cout << "\nВведите предмет: "; inPut >> a.subject;
	cout << "\nВведите оценку: "; inPut >> a.grade;

	return inPut;
}

int main() {

	system("chcp 1251 > Null");

	Student example; // по умолчанию

	example.getInfo();
	cout << endl;

	Student example_2("Вася", 18, "Физкультура", 5); // с параметрами

	example_2.getInfo();
	cout << endl;

	Student example_2_1("Саша", 20, "Физика", 2); // с параметрами (для копирования)

	Student example_3(example_2_1);

	cout << example_3;
	cout << endl;

	cin >> example_3; // ввод с клавы
	cout << endl;

	Student example_4; // перегрузка '='

	example_4 = example_3;
	cout << example_4 << endl;

	Person somePerson1;

	somePerson1.getInfo();
	cout << endl;

	Person somePerson2("Пришелец", 2000);

	somePerson2.getInfo();
	cout << endl;

	Person somePerson3(somePerson2);
	
	cout << somePerson3 << endl;

	Person somePerson4;
	
	cin >> somePerson4;
	cout << endl;
	
	Person somePerson5;

	somePerson5 = somePerson4;

	cout << somePerson5 << endl;


	return 0;
}


