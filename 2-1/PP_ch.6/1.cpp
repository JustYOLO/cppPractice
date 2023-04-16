#include <iostream>
using namespace std;

class Student
{
    public:
        Student(int q1, int q2, int midExam, int finalExam);
        double getAvg();
        char getGrade();
    private:
        int q1, q2;
        int midExam, finalExam;
};

int main()
{
    Student s1(10,5,80,80);
    cout << s1.getGrade();

    return 0;
}

Student::Student(int q1, int q2, int midExam, int finalExam): q1(q1), q2(q2), midExam(midExam), finalExam(finalExam)
{}
double Student::getAvg()
{
    return (Student::q1 + Student::q2 + Student::midExam + Student::finalExam) / 4.0;
}
char Student::getGrade()
{
    double sum = 0;
    sum += (Student::q1 + Student::q2)*1.25;
    sum += Student::midExam * 0.25;
    sum += Student::finalExam * 0.5;
    if(sum >= 90) return 'A';
    else if(sum >= 80) return 'B';
    else if(sum >= 70) return 'C';
    else if(sum >= 60) return 'D';
    else return 'F';
}