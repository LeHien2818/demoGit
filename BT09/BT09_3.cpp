#include <iostream>
using namespace std;

int main()
{
    char* arr = new char[10];
    char* c = arr + 3;
    for (int i = 0; i < 9; i++) arr[i] = 'a';
    arr[9] = '\0';
    cerr <<"a: " << "-" << arr << "-" << endl;
    cerr <<"c: " << "-" << c << "-" << endl;
    delete c;
    cerr << "a after deleting c:" << "-" << arr << "-" << endl;

    // lỗi vì c không được cấp phát bởi new nên không thể dùng delete
}
