#include "Truck.h"

Truck::Truck() : Vehicle(), loadCapacity(0), towingCapacity(0)
{} // 기본 생성자

Truck::Truck(double loadCapacity, int towingCapacity, string manufacturerName, int numCylinders, const Person& owner) : Vehicle(manufacturerName, numCylinders, owner), loadCapacity(loadCapacity), towingCapacity(towingCapacity)
{} // owner를 Person객체로 받는 생성자
Truck::Truck(double loadCapacity, int towingCapacity, string manufacturerName, int numCylinders, string owner) : Vehicle(manufacturerName, numCylinders, owner), loadCapacity(loadCapacity), towingCapacity(towingCapacity)
{} // owner를 string으로 받는 생성자
Truck::Truck(const Truck& rtSide) : Vehicle(rtSide),  loadCapacity(rtSide.loadCapacity), towingCapacity(rtSide.towingCapacity)
{} // 복사 생성자, Vehicle의 복사 생성자에 rtSide를 넣어서 생성

Truck& Truck::operator =(const Truck& rtSide)
{ // 복사 대입 연산자
    Vehicle::operator =(rtSide); // 객체의 부모 클래스인 Vehicle의 복사 대입 연산자를 이용
    loadCapacity = rtSide.loadCapacity;
    towingCapacity = rtSide.towingCapacity;
    // rtSide의 데이터로 변경
    return *this; // 객체 자신을 반환
}

double Truck::getLoadCapacity() const
{
    return loadCapacity; // 최대 적재량을 반환
}
int Truck::getTowingCapacity() const
{
    return towingCapacity; // 최대 견인무게를 반환
}
