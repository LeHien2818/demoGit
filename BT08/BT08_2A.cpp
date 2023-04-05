#include <iostream>
using namespace std;
int main( )
{
    char arr[4] = "abc";
    for (char *p = arr; (*p) != '\0'; p++)
    {
        cout << (void*) p << " : " << (*p) << endl;
    }


    int barr[4] = {1,2,3,4};
    for (int i =0; i < 4; i++)
    {
        cout << &barr[i] << " : " << barr[i] << endl;
    }
    double carr[4] = {1,2,3,4};
    for (int i = 0; i < 4; i+= 2)
    {
        cout << &carr[i] << " : " << carr[i] << endl;
    }

    return 0;
}

