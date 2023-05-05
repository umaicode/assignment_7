//���� �ð��� ���� �ڵ� �ǽ�
//virtual ��ӽÿ� ������ ������ �ذ��ϴ� ���� �ʿ��ϴ� 
// overloading �� overriding ����
// overloading : �Ķ���Ͱ� �ٸ�.
// overriding : �Լ��� ���� �Ÿ� ���� �Լ� �ٵ� �ٸ�. -> �Լ� ������ : Ŭ���� �������� ����. �������ε��� ���Ͽ�.
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
        Person* workstudents[20];//Person �������� �����ϴ� ���� �ذ� �ʿ� 
        Person* designers[20];
        int select;
        Person* p;
        WorkStudent cx;
        cout << "\n���� 1: WorkStudent ��ü 10�� �Է°� ���, 2: WorkStudent��ü ����(Dept �̸�> ���� ������ ����)�� ���, 3. ����" << endl;

        cin >> select;
        switch (select) {
            case 1://1: WorkStudent ��ü 10�� �Է°� ���
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

            case 3://3: WorkStudent��ü ����
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
                        //designers�� ����
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