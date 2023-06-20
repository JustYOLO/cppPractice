#ifndef PERSON_H
#define PERSON_H // 중복 include 방지

#include <iostream>
#include <string> 
using std::istream;
using std::ostream;
using std::string;

class Person
{
    public:
        Person(); // 기본 생성자
        Person(string theName); // 이름 받는 생성자
        Person(const Person& theObject); // 복사 생성자
        string getName() const; // name의 데이터를 가져오는 getter 함수
        Person& operator =(const Person& rtSide); // 복사 대입 연산자
        friend istream& operator >>(istream& inStream, Person& personObject);
        friend ostream& operator <<(ostream& outStream, const Person& personObject);
            // 입출력을 위한 연산자 >>, << 연산자
    private:
        string name; // 이름 데이터를 저장하는 변수 name
};

#endif
