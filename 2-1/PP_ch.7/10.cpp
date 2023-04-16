#include <iostream>
#include <string>
#include <random>
#include <vector>
using namespace std;

class BoxOfProduce
{
    public:
        BoxOfProduce(vector<string> vegArr);
        vector<string> getVeg();
        void setVeg(vector<string> vegArr);
        void output();
    private:
        vector<string> vegArr;
        bool havePaper = false;
        static int paper;
};
int BoxOfProduce::paper = 5;

int main()
{
    int left = 5;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> rand(0,4);
    string vegges[5];
    vegges[0] = "Broccoli";
    vegges[1] = "Tomato";
    vegges[2] = "Kiwi";
    vegges[3] = "Kale";
    vegges[4] = "Tomatillo";
    vector<BoxOfProduce> boxes;
    while(left > 0)
    {
        string randVegges[3];
        for(int i = 0; i < 3; i++)
        {
            randVegges[i] = vegges[rand(gen)];
            cout << randVegges[i] << ' ';
        }
        for(int i = 0; i < 3; i++)
        {
            if(randVegges[i] == "Tomatillo"){
                left--;
                break;
            }
        }
        boxes.push_back(BoxOfProduce(randVegges));
        cout << "\n**************\n";
    }

    for(int i = 0; i < boxes.size(); i++)
    {
        boxes[i].output();
    }

    return 0;
}

BoxOfProduce::BoxOfProduce(string* vegArr)
{
    for(int i = 0; i < 3; i++)
    {
        BoxOfProduce::vegArr[i] = vegArr[i];
    }
    for(int i = 0; i < 3; i++)
    {
        if(vegArr[i] == "Tomatillo" && paper > 0) 
        {
            havePaper = true;
            paper--;
            break;
        }
    }
}
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
    if(BoxOfProduce::havePaper) cout << "with salsa verde paper!";
    cout << '\n';
}