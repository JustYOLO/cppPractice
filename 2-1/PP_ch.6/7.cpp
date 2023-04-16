#include <iostream>
#include <string>
using namespace std;

class IceCreamSundae
{
    public:
        IceCreamSundae(int iceCream, int size, int toppings);
        void outputDescription();
        int computePrice();
    private:
        int iceCream; // 0 == chocolate, 1 == vanilla, 2 == strawberry
        int size; // 0 == small, 1 == regular, 2 == large
        int toppings;
};

int main()
{
    IceCreamSundae ice(0,0,2);
    ice.outputDescription();
    cout << ice.computePrice() << '\n';
    IceCreamSundae vanillaLargeFivetoppings(1,2,5);
    vanillaLargeFivetoppings.outputDescription();
    cout << vanillaLargeFivetoppings.computePrice() << '\n';
    return 0;
}

IceCreamSundae::IceCreamSundae(int iceCream, int size, int toppings): iceCream(iceCream), size(size), toppings(toppings)
{}

void IceCreamSundae::outputDescription()
{
    string type, size;
    switch (IceCreamSundae::iceCream)
    {
    case 0:
        type = "chocolate";
        break;
    case 1:
        type = "vanilla";
        break;
    case 2:
        type = "strawberry";
        break;
    default:
        break;
    }
    switch (IceCreamSundae::size)
    {
    case 0:
        size = "small";
        break;
    case 1:
        size = "regular";
        break;
    case 2:
        size = "large";
        break;
    default:
        break;
    }
    cout << "The icecream type is " << type << ", size is " << size << " and number of topping(s): " << IceCreamSundae::toppings << '\n';
}
int IceCreamSundae::computePrice()
{
    int sum = 0;
    switch (IceCreamSundae::size)
    {
    case 0:
        sum = 10;
        break;
    case 1:
        sum = 14;
        break;
    case 2:
        sum = 17;
        break;
    default:
        break;
    }
    return sum + IceCreamSundae::toppings * 2;
}