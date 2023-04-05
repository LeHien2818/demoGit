#include <iostream>
using namespace std;
void func(int x_value)
{
   int x;
   x = x_value;
   cout << &x << endl;
}
void gunc(int y_value)
{
   int y;
   y = y_value;
   cout << &y;

}
int main()
{
   func(7);
   gunc(11);
   return 0;
}

