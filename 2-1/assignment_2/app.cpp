#include <iostream>
#include <cassert>
#include <string>
#include "Person.h"
#include "Vehicle.h"
#include "Truck.h"

using std::string;
using std::cout;
using std::cin;

void printInfo(string type, string name); // 객체의 타입과 이름을 출력
void printPerson(Person p); // Person 객체의 정보 출력
void personCheck(Person p1, Person p2); // Person 객체의 이름이 같은지 확인하는 함수 (assert 매크로 이용)
void printVehicle(Vehicle v); // Vehicle 객체의 정보 출력
void vehicleCheck(Vehicle v1, Vehicle v2); // 2개의 Vehicle 객체가 같은 멤버변수 값을 가지고 있는지 확인하는 함수 (assert 매크로 이용)
void printTruck(Truck t);
void truckCheck(Truck t1, Truck t2);

int main()
{
    Person p1("Park");
    Person p2("Choi");
    Person pList[2];
    printInfo("Person", "p1");
    printPerson(p1);
    printInfo("Person", "p2");
    printPerson(p2);
    for(int i = 0; i < 2; i++)
    {
        pList[i] = Person();
    }
    pList[0] = p1; // 복사 대입 연산자
    cout << "input pList[1]'s name: ";
    cin >> pList[1]; // istream 오버로딩
    Person p3(pList[1]); // 복사 생성자
    
    printInfo("Person", "pList[0]");
    printPerson(pList[0]);
    personCheck(pList[0], p1); // 복사 대입 연산자가 제대로 작동했는지 확인
    
    printInfo("Person", "pList[1]");
    printPerson(pList[1]);
    printInfo("Person", "p3");
    printPerson(p3);
    assert(pList[1]. getName() == p3.getName() && "Unexpected output");
    personCheck(pList[1], p3); // 복사 생성자가 제대로 작동했는지 확인
    
    Vehicle v1("KIA", 4, "Lee");
    Vehicle v2("Hyundai", 4, "Kim");
    Vehicle v3;

    printInfo("Vehicle", "v1");
    printVehicle(v1);
    
    printInfo("Vehicle", "v2");
    printVehicle(v2);

    printInfo("Vehicle", "v3");
    printVehicle(v3);
    
    v3 = v1;
    Vehicle v4(v2);
    
    printInfo("Vehicle", "v3");
    printVehicle(v3);
    
    printInfo("Vehicle", "v4");
    printVehicle(v4);
    
    Truck t1(100, 100, "test", 6, "lee");
    Truck t2;
    Truck t3(100, 100, "test", 6, "1ee");
    t2 = t1;
    printInfo("Truck", "t1");
    printTruck(t1);
    printInfo("Truck", "t2");
    printTruck(t2);
    truckCheck(t1, t2);
    
    return 0;
}

void printInfo(string type, string name)
{
    cout << type << ' '
        << name << ' '
        << "data: \n";
}
void printPerson(Person p)
{
    cout << p.getName() << "\n\n";
}
void personCheck(Person p1, Person p2)
{
    assert(p1.getName() == p2.getName() && "Person name is different");
}
void printVehicle(Vehicle v)
{
    cout << v.getManufacturerName() << '\n';
    cout << v.getNumCylinders() << '\n';
    cout << v.getOwner() << "\n\n";
}
void vehicleCheck(Vehicle v1, Vehicle v2)
{
    assert(v1.getManufacturerName() == v2.getManufacturerName() && "Manufacturer name is different");
    assert(v1.getNumCylinders() == v2.getNumCylinders() && "Number of cylinder is different");
    personCheck(v1.getOwner(), v2.getOwner());
}
void printTruck(Truck t)
{
    printVehicle(t);
    cout << t.getLoadCapacity() << '\n';
    cout << t.getTowingCapacity() << "\n\n";
}
void truckCheck(Truck t1, Truck t2)
{
    vehicleCheck(t1, t2);
    assert(t1.getLoadCapacity() == t2.getLoadCapacity() && "Load capacity is different");
    assert(t1.getTowingCapacity() == t2.getTowingCapacity() && "Towing capacity is different");
}
