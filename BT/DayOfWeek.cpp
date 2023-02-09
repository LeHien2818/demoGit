#include <bits/stdc++.h>

using namespace std;
// tham khảo Jullian Day Cal
string get_day(int day, int month, int year){
  int Jullday;
   Jullday = (day + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5) +
     (365 * (year + 4800 - ((14 - month) / 12))) +
     ((year + 4800 - ((14 - month) / 12)) / 4) -
    ((year + 4800 - ((14 - month) / 12)) / 100) +
    ((year + 4800 - ((14 - month) / 12)) / 400)  - 32045) % 7;
    string dayInWeek[] = {"Thu 2", "Thu 3", "Thu 4", "Thu 5", "Thu 6", "Thu 7", "Chu nhat"};
 return dayInWeek[Jullday];
}
int main(){
    cout << "nhap ngay thang nam theo thu tu: ";
    int day, month, year;
    cin >> day >> month >> year;
    cout << get_day(day, month, year);



}
