#include <iostream>
#include <string>
#include <random>
using namespace std;

class BoxOfProduce
{
    public:
        BoxOfProduce(string* vegArr);
        string* getVeg();
        void setVeg(string vegArr[]);
        void output();
    private:
        string* vegArr;
};

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> rand(0,4);
    string vegges[5];
    vegges[0] = "Broccoli";
    vegges[1] = "Tomato";
    vegges[2] = "Kiwi";
    vegges[3] = "Kale";
    vegges[4] = "Tomatillo";
    string randVegges[3];
    for(int i = 0; i < 3; i++)
    {
        randVegges[i] = vegges[rand(gen)];
        cout << randVegges[i] << ' ';
    }
    cout << "\n**************\n";
    BoxOfProduce box1(randVegges);
    string* boxTest = box1.getVeg();
    for(int i = 0; i < 3; i++)
    {
        cout << boxTest[i] << ' ';
    }
    cout << '\n';
    
    for(int i = 0; i < 3; i++)
    {
        randVegges[i] = vegges[rand(gen)];
        cout << randVegges[i] << ' ';
    }
    cout << "\n\n\n";
    BoxOfProduce box2(randVegges);

    box1.output();
    box2.output();

    return 0;
}

BoxOfProduce::BoxOfProduce(string* vegArr): vegArr(vegArr)
{}
string* BoxOfProduce::getVeg()
{
    return BoxOfProduce::vegArr;
}
void BoxOfProduce::setVeg(string vegArr[])
{
    BoxOfProduce::vegArr = vegArr;
}
void BoxOfProduce::output()
{
    for(int i = 0; i < 3; i++)
    {
        cout << vegArr[i] << ' ';
    }
    cout << '\n';
}