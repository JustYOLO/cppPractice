#ifndef TRUCK_H
#define TRUCK_H // 중복 include 방지

#include "Vehicle.h"
#include "Person.h"

class Truck : public Vehicle // Vehicle 객체를 상속받음
{
    public:
        Truck(); // 기본 생성자
        Truck(double loadCapacity, int towingCapacity, string manufacturerName, int numCylinders, const Person& owner); // 소유주를 Person 객체로 받는 생성자
        Truck(double loadCapacity, int towingCapacity, string manufacturerName, int numCylinders, string owner); // 소유주를 string으로 받는 생성자
        Truck(const Truck& rtSide); // 복사 생성자
        Truck& operator =(const Truck& rtSide); // 복사 대입 연산자

        double getLoadCapacity() const; // 최대 적재량을 가져오는 getter 함수
        int getTowingCapacity() const; // 최대 견인 무게를 가져오는 getter 함수

    private:
        double loadCapacity; // 최대 적재량을 저장하는 변수
        int towingCapacity; // 최대 견인무게를 저장하는 변수
};

#endif
