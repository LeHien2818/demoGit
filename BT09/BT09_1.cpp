#include <iostream>
#include <cstring>
using namespace std;
char *concat(char* a, char*b)
{
    int x = strlen(a);
    int y = strlen(b);
    int n = x + y;
    char *res = new char[n];
    for(int i = 0; i < x; i ++)
    {
        *(res + i ) = *(a + i);
    }
    for(int i = 0; i < y; i ++)
    {
        *(res + x + i) = *(b + i);
    }
}
int main()
{
    char xarr[] = "Hello";
    char yarr[] = "World";
    cout<<concat(xarr, yarr);

}
