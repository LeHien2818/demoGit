#include <iostream>
using namespace std;
void swapPointers(char**a, char**b)
{
   char *tmp;
   tmp = *a;
   *a = *b;
   *b = tmp;
}
int main()
{
   char arr[] = "I should print second";
   char barr[] = "I should print first";

   char *s1 = arr;
   char *s2 = barr;
   swapPointers(&s1,&s2);
   cout << "s1 is " << s1 << endl;
   cout << "s2 is " << s2 << endl;
   return 0;
}

