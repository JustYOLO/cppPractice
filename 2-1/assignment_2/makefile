Person.o : Person.h Person.cpp
	g++-12 -c Person.cpp

Vehicle.o : Vehicle.h Vehicle.cpp
	g++-12 -c Vehicle.cpp

Truck.o : Truck.h Truck.cpp
	g++-12 -c Truck.cpp

app.o : app.cpp
	g++-12 -c app.cpp

main : Person.o Vehicle.o Truck.o app.o
	g++-12 Person.o Vehicle.o Truck.o app.o -o main
