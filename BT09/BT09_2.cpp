#include <iostream>
using namespace std;

int main()
{
    int* pointer = new int;
    int* poin2 = pointer;
    *pointer = 10;
    delete pointer;
    *poin2 = 100;
    cout << *poin2;
    delete poin2;


}
