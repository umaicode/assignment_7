//7�� Ŭ���� ��� ����
// 1) dynamic_cast <> : ����ؾ� �Ѵ�.
// 2) virtual : ����ؾ� �Ѵ�.
// => �������ε�
#include <iostream>
#include <string>
using namespace std;
class Dept {
	string dname;
	string city;
	friend ostream& operator<<(ostream&, Dept&);
};
class Person {
private:
	string pid;
	string pname;
	friend ostream& operator<<(ostream&, Person&);

};
class Employee : protected Person {
private:
	string eno;
	Dept* dname;
	friend ostream& operator<<(ostream&, Employee&);

};
class Student : private Person {
private: 
    string sid;
    Dept* dname;
    friend ostream& operator<<(ostream&, Student&);
};
class Coder : private Employee {
private:
	string language;
	double workYears;
public:
	int operator > (Coder&);//
	Coder(string language, double workYears, string eno, string dept, string city, string pid, string pname);
	friend ostream& operator<<(ostream&, Coder&);

};
class PartTimeStudent : private Employee, private Student {
private:
    double salary;
    double grade;
    friend ostream& operator<<(ostream&, PartTimeStudent&);
};
int main() {
    while (1)
    {
        Coder *codings[10];
        PartTimeStudent* workStudents[10];

        int select;
        //������ ��뿡 ���� �Է��� new Coder("�̸�", ...)���� ���� �����Ͽ� �Է�
        //��ü ����� cout<<*codings[i]���� ����Ѵ�.
        cout << "\n���� 1: Coder ��ü 10�� �Է°� ���, 2. PartTimeStudent ��ü 10�� �Է°� ���, 3: Coder��ü ����(Dept �̸�> ���� ������ ����)�� ���,4. partTimeStudents ��ü ����(eno > sid ������ ����)�� ���, 5. ����" << endl;

        cin >> select;
        switch (select) {
        case 1://1: Coder ��ü 10�� �Է°� ���

            break;
        case 2://2. PartTimeStudent ��ü 10�� �Է°� ���

            break;

        case 3://3: Coder��ü ����(Dept �̸��� ����)�� ���

            break;
        case 4://4. partTimeStudents ��ü ����(eno > sid)�� ���

            break;

        default:
            exit(0);
            break;
        }
    }
    system("pause");
    return 1;
}