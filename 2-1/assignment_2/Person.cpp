#include "Person.h"

Person::Person() : name("")
{} // 기본 생성자
Person::Person(string theName) : name(theName)
{} // 이름을 받는 생성자
Person::Person(const Person& theObject) : name(theObject.name)
{} // 복사 생성자
string Person::getName() const
{
    return name; // 이름을 반환
}
Person& Person::operator =(const Person& rtSide)
{  
    this->name = rtSide.name; // 객체의 name을 대입한 rtSide의 name으로 변경
    return *this; // 객체 자신을 반환
}
istream& operator >>(istream& inStream, Person& personObject)
{
    inStream >> personObject.name; // istream으로 부터 이름을 받아 Person 객체의 name에 저장함
    return inStream; // istream 객체 반환
}
ostream& operator <<(ostream& outStream, const Person& personObject)
{
    outStream << personObject.name; // Person 객체의 이름을 ostream으로 제공
    return outStream; // ostream 객체 반환
}
