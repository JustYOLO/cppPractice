#include <iostream>

void sort(int* array, int size)
{
    int cur;
    for(int i = 1; i < size; i++)
    {
        cur = array[i];
        int j = i - 1;
        while(j >= 0 && array[j] > cur)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = cur;
    }
}

int main()
{
    int array[] = {5,3,2,4,1};
    sort(array, 5);
    for(int i: array)
        std::cout << i << "\n";
}