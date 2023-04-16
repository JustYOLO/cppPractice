#include <iostream>
using namespace std;

class HotDogStand
{
    public:
        HotDogStand(int id, int sold);
        void reset();
        void JustSold();
        int getSold();
        static int getTotalSold();
        static void setTotalSold(int num);
    private:
        int ID;
        int sold;
        static int totalSold;
};

int HotDogStand::totalSold = 0;

int main()
{
    HotDogStand shop1(912, 0);
    for(int i = 0; i < 10; i++) shop1.JustSold();
    HotDogStand shop2(913, 20);
    HotDogStand shop3(914, 30);
    cout << shop1.getSold() << " " << shop2.getSold() << " " << shop3.getSold() << "\n";
    cout << HotDogStand::getTotalSold();
    return 0;
}

HotDogStand::HotDogStand(int id, int sold): ID(id), sold(sold)
{
    HotDogStand::totalSold += sold;
}
void HotDogStand::reset() {HotDogStand::sold = 0;}
void HotDogStand::JustSold()
{
    HotDogStand::sold++;
    HotDogStand::totalSold++;
}
int HotDogStand::getSold()
{
    return HotDogStand::sold;
}
int HotDogStand::getTotalSold()
{
    return HotDogStand::totalSold;
}
void HotDogStand::setTotalSold(int num)
{
    HotDogStand::totalSold = num;
}