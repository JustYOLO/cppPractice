#ifndef VEHICLE_H
#define VEHICLE_H // 중복 include 방지

#include <string>
#include "Person.h"
using std::string;

class Vehicle{
    public:
        Vehicle(); // 기본 생성자
        Vehicle(string manufacturerName, int numCylinders, const Person& owner); // owner를 Person객체로 받는 생성자
        Vehicle(string manufacturerName, int numCylinders, string owner); // owner를 string으로 받는 생성자
        Vehicle(const Vehicle& rtSide); // 복사 생성자
        Vehicle& operator =(const Vehicle& rtSide); // 복사 대입 연산자
        string getManufacturerName() const; // 제조 회사명을 가져오는 getter 함수
        int getNumCylinders() const; // 실린더의 개수를 가져오는 getter 함수
        const Person& getOwner() const; // 차량의 소유주를 가져오는 getter 함수

    private:
        string manufacturerName; // 차량의 제조 회사명을 저장하는 변수
        int numCylinders; // 차량의 실린더 개수를 저장하는 변수
        Person owner; // 차량의 소유주를 보여주는 Person 객체
};

#endif
