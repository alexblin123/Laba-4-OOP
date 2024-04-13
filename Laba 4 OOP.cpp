#include <iostream>

using namespace std;

class Person {

protected:

	string name;
	int age;

};

class Student : Person {
	
	string subject;
	int grade;

public:

	Student() {

		cout << "\nКонструктор по умолчанию\n";

		this->name = "Иван";
		this->age = 10;
		this->grade = 4;
		this->subject = "Математика";
	}

	Student(string name, int age, string subject, int grade) {

		cout << "\nКонструктор с параметрами\n";

		this->name = name;
		this->age = age;
		this->subject = subject;
		this->grade = grade;
	}

	Student(const Student& someStudent) {

		cout << "\nКонструктор копирования\n";

		this->name = someStudent.name;
		this->age = someStudent.age;
		this->grade = someStudent.grade;
		this->subject = someStudent.subject;
	}

	~Student() {
		cout << "\nДеструктор\n";
	}
	
	void getInfo() {

		cout << name << endl << age << " лет\n" << subject << endl << "Оценка: " << grade << endl;
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

		cout << "\nВызов оператора '='\n";

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

	outPut << a.name << endl << a.age << " лет\n" << a.subject << endl << "Оценка: " << a.grade << endl;
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

	return 0;
}


