//7�� Ŭ���� ��� ����
#include <iostream>
#include <string>
using namespace std;

class Dept {
	char dname[10];
	char* city;

public:
    int operator>(Dept&); // ������ �� �̿�
    Dept(char* dname, char* city);
	ostream& operator<<(Dept&);
};

class Person {
private:
	string pid;
	string pname;
	ostream& operator<<(Person&);
public:
    Person(string pid, string pname) {};

};

class Employee : protected Person {
private:
	char* eno;
	Dept* dname;
protected: 
	void MoveDept(Dept* dname);
public:
    int operator>(Employee&); // ������ �� �̿�
    Employee(char* eno, Dept* dname, char* pname, char* pid) : Person(pid, pname) {};
	ostream& operator<<(Employee&);

};

class Coder : private Employee {
private:
	char* language;
	double workYears;
public:
    int operator > (Coder&) {
        // ������ �� �̿�
        Employee e = (Employee)(*this); // this�� Coder ��ü��.
        // ���⿡�� dept ��ü�� �����ϱ� upcasting �ؾ��Ѵ�.
        if (e > e1) {
            // �ᱹ�� > �����ڸ� �����ؾ� �Ѵ�.
            // ���� Ŭ������ ���ǵ� �񱳿����ڸ� ����.
        }
    }
	Coder(char* language, double workYears, char* eno, Dept* dname, string pid, string pname);
	void MoveDept(Dept* dname);//�μ� �̵�
	ostream& operator<<(Coder&);

};

void SortCoder(Coder* []p, int n) {
    for () {
        if (p[i] > p[j]) {}
    }
}

int main() {
    while (1)
    {
        Coder *codings[20];

        int select;
        //������ ��뿡 ���� �Է��� new Coder("�̸�", ...)���� ���� �����Ͽ� �Է�
        cout << "\n���� 1: ��ü 4�� �Է�(cin ���), 2. ��ü 10�� �Է�(������ ���), 3: ��ü ����(Dept �̸�)�� ���,4. ��ü ����(Coder workYears)�� ���, 5. ����" << endl;

        cin >> select;
        switch (select) {
        case 1://1: ��ü 4�� �Է�(cin ���)

            break;
        case 2://2. ��ü 10�� �Է�(������ ���)
            codings[o] = new Coder("Hello", 15, "E1", "cs"); // cs�� �ٷ� ���� �ȵǰ� new �� ����ؾ� �Ѵ�.
            break;

        case 3://3: ��ü ����(Dept �̸�)�� ���

            break;
        case 4://4. ��ü ����(Coder workYears)�� ���
            SortCoder(coding, 14);
            break;

        default:
            exit(0);
            break;
        }
    }
    system("pause");
    return 1;
}