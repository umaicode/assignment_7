//수업 시간에 연습 코딩 실습
//virtual 상속시에 생성자 문제를 해결하는 것이 필요하다 
// overloading 과 overriding 차이
// overloading : 파라미터가 다름.
// overriding : 함수는 같은 거를 쓰고 함수 바디가 다름. -> 함수 재정의 : 클래스 계층에서 적용. 동적바인딩을 위하여.
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string pname;
public:
    virtual void print() { cout << pname; }
    Person() {}
    Person(string pname):pname(pname) {}

    string getPname() {
        return pname;
    }
};

ostream& operator <<(ostream& os, Person& person) {
    os << person.getPname();
    return os;
}

class Employee : virtual public Person {
private:
    string eno;
public:
    void print() { cout << eno; }
    Employee() {}
    Employee(string eno):eno(eno) {}
    Employee(string eno, string pname):Person(pname), eno(eno){}
    string getEno() {
        return eno;
    }
    int Employee::operator>(Employee& other) {
        return this->eno > other.eno;
    }
    friend ostream& operator<<(ostream& os, Employee& employee);
};
ostream& operator<<(ostream& os, Employee& employee) {
    os << employee.getEno();
    return os;
}

class Student : virtual public Person {
private:
    string sno;
public:
    Student() {}
    Student(string sno):sno(sno) {}
    Student(string sno, string pname):Person(pname), sno(sno){}
    int Student::operator>(Student& other) {
        return this->sno > other.sno;
    }
    string getSno() {
        return sno;
    }
    friend ostream& operator<<(ostream& os, Student& student);
};

ostream& operator<<(ostream& os, Student& student) {
    os << student.getSno();
    return os;
}

class WorkStudent : public Student, public Employee {
    string cowork;
public:
    WorkStudent() {}
    WorkStudent(string sno, string pname, string eno, string cowork) :Student(sno), Employee(eno), cowork(cowork) {}
    int operator >(WorkStudent&);
    string getCowork() {
        return cowork;
    }
    friend ostream& operator<<(ostream& os, WorkStudent& ws);
};

int WorkStudent::operator >(WorkStudent& ws) {
    Student *s = dynamic_cast<Student*>(&ws);
    Employee* e = dynamic_cast<Employee*>(&ws);
    int result = this->cowork.compare(ws.cowork);
    if (result > 0) return 1;
    else if (result < 0) return -1;
    else if (*dynamic_cast<Student*>(this) > *s) return 1;
    else return -1;
}
ostream& operator<<(ostream& os, WorkStudent& ws) {
    os << " " << ws.getSno() << ", " << ws.getPname() << ", " << ws.getEno() << ", " << ws.getCowork() << endl;
    return os;
}

class Designer : public Employee {
    string design;
};

void swap(Person* p[], int i, int j) {
    Person* temp;
    temp = p[i];
    p[i] = p[j];
    p[j] = temp;
}

int main() {
    while (1)
    {
        Person* workstudents[20];//Person 선언으로 변경하는 문제 해결 필요 
        Person* designers[20];
        int select;
        Person* p;
        WorkStudent cx;
        cout << "\n선택 1: WorkStudent 객체 10개 입력과 출력, 2: WorkStudent객체 정렬(Dept 이름> 도시 순서로 정렬)과 출력, 3. 종료" << endl;

        cin >> select;
        switch (select) {
            case 1://1: WorkStudent 객체 10개 입력과 출력
            {
                workstudents[0] = new WorkStudent("p1", "hong", "E1", "Coding");
                workstudents[1] = new WorkStudent("p2", "hee", "E2", "Coding");
                workstudents[2] = new WorkStudent("p3", "kim", "E3", "Test");
                workstudents[3] = new WorkStudent("p4", "lee", "E4", "Test");
                workstudents[4] = new WorkStudent("p5", "ko", "E5", "Design");
                workstudents[5] = new WorkStudent("p6", "choi", "E6", "Design");
                workstudents[6] = new WorkStudent("p7", "han", "E7", "Sales");
                workstudents[7] = new WorkStudent("p8", "na", "E8", "Sales");
                workstudents[8] = new WorkStudent("p9", "you", "E9", "Account");
                workstudents[9] = new WorkStudent("p10", "song", "E10", "Production");
                for (int i = 0; i < 10; i++)
                {
                    cout << *workstudents[i];
                }
                break;
            }

            case 2:
            {
                designers[0] = new Designer();
                break;
            }

            case 3://3: WorkStudent객체 정렬
            {
                for (int i = 0; i < 10; i++)
                    for (int j = i + 1; j < 10; j++)
                    {
                        // Student* s = (Student)workstudents[i];
                        // Student* s = dynamic_cast<Student*>(workstudents[i]);
                        // if (*workstudents[i] > *workstudents[j]) {
                        //     swap(workstudents, i, j);
                        // }
                        WorkStudent* ws1 = dynamic_cast<WorkStudent*>(workstudents[i]);
                        WorkStudent* ws2 = dynamic_cast<WorkStudent*>(workstudents[j]);

                        if (*ws1 > *ws2) {
                            swap(workstudents, i, j);
                        }
                    }
                for (int i = 0; i < 10; i++)
                {
                    cout << i + 1 << ". " << *(workstudents[i]) << endl;
                }
                break;
            }

            case 4:
            {
                for (int i = 0; i < 10; i++)
                    for (int j = i + 1; j < 10; j++)
                    {
                        //designers의 정렬
                        Designer* ws1 = dynamic_cast<Designer*>(workstudents[i]);
                        Designer* ws2 = dynamic_cast<Designer*>(workstudents[i]);

                        if (*ws1 > *ws2) {
                            swap(designers, i, j);
                        }
                    }

                for (int i = 0; i < 10; i++)
                {
                    //cout<<designers[i];
                }
                break;
            }

            default:
                exit(0);

            }
    }
    system("pause");
    return 1;
}