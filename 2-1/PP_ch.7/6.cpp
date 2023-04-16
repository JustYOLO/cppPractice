#include <iostream>
#include <string>
#include <vector>
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
class Order
{
    public:
        Order();
        Order(vector<IceCreamSundae> orders);
        vector<IceCreamSundae> getAllOrders();
        void addOrder(IceCreamSundae iceCream);
        int totalPrice();
        void orderDetails();
    private:
        vector<IceCreamSundae> orders;
};

int main()
{
    IceCreamSundae ice(0,0,2);
    IceCreamSundae vanillaLargeFivetoppings(1,2,5);
    vector<IceCreamSundae> orders;
    orders.push_back(ice);
    orders.push_back(vanillaLargeFivetoppings);
    Order orderNum1(orders);
    cout << orderNum1.totalPrice() << '\n';
    IceCreamSundae ice2(0,0,0);
    orderNum1.addOrder(ice2);
    cout << orderNum1.totalPrice() << '\n';
    orderNum1.orderDetails();

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

Order::Order() {orders.clear();}
Order::Order(vector<IceCreamSundae> orders): orders(orders)
{}
vector<IceCreamSundae> Order::getAllOrders() {return Order::orders;}
void Order::addOrder(IceCreamSundae iceCream) {Order::orders.push_back(iceCream);}
int Order::totalPrice()
{
    int sum = 0;
    for(int i = 0; i < Order::orders.size(); i++)
    {
        sum += orders[i].computePrice();
    }
    return sum;
}

void Order::orderDetails()
{
    for(int i = 0; i < Order::orders.size(); i++)
    {
        orders[i].outputDescription();
    }
    cout << "total price is: " << Order::totalPrice() << '\n';
}