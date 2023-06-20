#include "Vehicle.h"

Vehicle::Vehicle() : manufacturerName(""), numCylinders(0), owner("")
{} // 기본 생성자로 생성

Vehicle::Vehicle(string manufacturerName, int numCylinders, const Person& owner) : manufacturerName(manufacturerName), numCylinders(numCylinders), owner(owner)
{} // 이름을 string, 실린더 개수를 int, 소유주를 Person 객체로 받는 생성자

Vehicle::Vehicle(string manufacturerName, int numCylinders, string owner) : manufacturerName(manufacturerName), numCylinders(numCylinders), owner(Person(owner))
{} // 소유주를 string으로 받는 생성자

Vehicle::Vehicle(const Vehicle& rtSide) : manufacturerName(rtSide.manufacturerName), numCylinders(rtSide.numCylinders), owner(rtSide.owner)
{} // 복사 생성자

Vehicle& Vehicle::operator =(const Vehicle& rtSide)
{
    this->manufacturerName = rtSide.manufacturerName;
    this->numCylinders = rtSide.numCylinders;
    this->owner = rtSide.owner; // 대입된 rtSide의 데이터를 객체에 저장
    return *this; // 객체 자신을 반환
}

string Vehicle::getManufacturerName() const
{
    return manufacturerName; // 제조 회사를 반환
}

int Vehicle::getNumCylinders() const
{
    return numCylinders; // 실린더의 개수를 반환
}

const Person& Vehicle::getOwner() const
{
    return owner; // 소유주를 반환
}
