#include <iostream>
#define NDEBUG // assert toggle definement
#include <cassert>
using namespace std;

void show_number(int* ptr)
{
    assert(ptr != NULL);
    cout << "The number is " << *ptr << "\n";
}

int main(void) 
{
    int x;
    int* first_ptr = NULL;
    int* second_ptr = NULL;

    x = 10;
    first_ptr = &x;

    show_number(first_ptr);
    show_number(second_ptr);
    // runtime error: segmentation fault
    //null pointer exception

    return 0;
}