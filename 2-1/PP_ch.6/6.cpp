#include <iostream>
using namespace std;

class Odometer
{
    public:
        void resetTravel(); // resets travel distance
        void addTravel(double distance); // adds travel distance
        void setKmpl(double kmpl); // set kilmeter per liter
        double gasUsed(); // return gas used in this travel
        double getTravelDistance(); // returns travel distance
    private:
        double kmpl; // kilometer per liter
        double travel; // travel distance
};

int main()
{
    Odometer o;
    o.resetTravel();
    o.setKmpl(13.0);
    o.addTravel(100);
    cout << o.gasUsed() << '\n';
    cout << o.getTravelDistance() << '\n';
    o.addTravel(100);
    cout << o.gasUsed() << '\n';
    cout << o.getTravelDistance() << '\n';
    return 0;
}

void Odometer::resetTravel()
{
    Odometer::travel = 0;
}
void Odometer::addTravel(double distance)
{
    Odometer::travel += distance;
}
void Odometer::setKmpl(double kmpl)
{
    Odometer::kmpl = kmpl;
}
double Odometer::gasUsed()
{
    return Odometer::travel/kmpl;
}
double Odometer::getTravelDistance()
{
    return travel;
}