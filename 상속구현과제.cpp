//7장 클래스 상속 과제
#include <iostream>
#include <string>
using namespace std;

class Dept {
	char dname[10];
	char* city;

public:
    int operator>(Dept&); // 정렬할 때 이용
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
    int operator>(Employee&); // 정렬할 때 이용
    Employee(char* eno, Dept* dname, char* pname, char* pid) : Person(pid, pname) {};
	ostream& operator<<(Employee&);

};

class Coder : private Employee {
private:
	char* language;
	double workYears;
public:
    int operator > (Coder&) {
        // 정렬할 때 이용
        Employee e = (Employee)(*this); // this는 Coder 객체임.
        // 여기에스 dept 객체가 없으니까 upcasting 해야한다.
        if (e > e1) {
            // 결국에 > 연산자를 재사용해야 한다.
            // 상위 클래스에 정의된 비교연산자를 재사용.
        }
    }
	Coder(char* language, double workYears, char* eno, Dept* dname, string pid, string pname);
	void MoveDept(Dept* dname);//부서 이동
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
        //생성자 사용에 의한 입력은 new Coder("이름", ...)으로 값을 지정하여 입력
        cout << "\n선택 1: 객체 4개 입력(cin 사용), 2. 객체 10개 입력(생성자 사용), 3: 객체 정렬(Dept 이름)과 출력,4. 객체 정렬(Coder workYears)과 출력, 5. 종료" << endl;

        cin >> select;
        switch (select) {
        case 1://1: 객체 4개 입력(cin 사용)

            break;
        case 2://2. 객체 10개 입력(생성자 사용)
            codings[o] = new Coder("Hello", 15, "E1", "cs"); // cs를 바로 쓰면 안되고 new 를 사용해야 한다.
            break;

        case 3://3: 객체 정렬(Dept 이름)과 출력

            break;
        case 4://4. 객체 정렬(Coder workYears)과 출력
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