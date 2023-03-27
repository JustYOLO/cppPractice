#include <stdio.h>
//#define XXX

int main()
{
#ifdef XXX
    printf("%s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
    printf("%s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
#endif

    return 0;
}