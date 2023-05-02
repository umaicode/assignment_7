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
    Person(string pname):pname(pname) {}

};

ostream& operator <<(ostream& os, Person& person) {

}
class Employee : virtual public Person {
private:
    string eno;
public:
    void print() { cout << eno; }
    Employee(string eno, string pname):Person(pname), eno(eno){}

};
ostream& operator<<(ostream& os, Employee& employee) {

}

class Student : virtual public Person {
private:
    string sno;
public:
    Student(string sno, string pname):Person(pname), sno(sno){}

};
ostream& operator<<(ostream& os, Student& st) {
 
}
class WorkStudent : public Student, public Employee {
    string cowork;
public:
    WorkStudent() {}
    WorkStudent(string cowork, string sno, string eno, string pname) :Student(sno), Employee(eno), cowork(cowork) {}
    int operator >(WorkStudent&);

};
int WorkStudent::operator >(WorkStudent& ws) {
    Student s = (Student)ws;
    int result = this->cowork.compare(ws.cowork);
    if (result > 0) return 1;
    else if (result < 0) return -1;
    else if (Student(*this) > s) return 1;
    else return -1;
}
class Designer : public Employee {
    string design;
};
void swap(Person* p[], int i, int j) {
    Person* temp;
    temp = p[i]; p[i] = p[j]; p[j] = temp;
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
                //cout << 
            }
            break;
        case 2:
            break;
            designers[0] = new Designer();

        case 3://3: WorkStudent��ü ����
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
                //cout<<workstudents[i];
            }
            break;
        case 4:
            for (int i = 0; i < 10; i++)
                for (int j = i + 1; j < 10; j++)
                {
                    //designers�� ����
                    Designer* ws1 = dynamic_cast<Designer*>(workstudents[i]);
                    Designer* ws2 = dynamic_cast<Designer*>(workstudents[i]);

                    if(*ws1 > *ws2) {
                        swap(designers, i, j);
                    }
                }

            for (int i = 0; i < 10; i++)
            {
                //cout<<designers[i];
            }
            break;
        default:
            exit(0);

        }
    }
    system("pause");
    return 1;
}