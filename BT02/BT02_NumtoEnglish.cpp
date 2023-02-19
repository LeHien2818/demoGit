#include <bits/stdc++.h>

using namespace std;

string donvi[12] ={"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string _teen[12] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string chuc[12] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

string triplet(string a){
    string res = "";
    if(a[0] != '0'){
        res += donvi[a[0] - '0' - 1];
        res += " hundred ";
    }
    if(a[1] != '0'){
        if(a[1] == '1'){
            res += _teen[a[2] - '0'];
        }else{
            res += chuc[a[1] - '0' - 2];
            res += '-';
            res += donvi[a[2] - '0' - 1];
        }
    }
    else{
        res += donvi[a[2] - '0' - 1];
    }
        return res;

}
string numToText (string a){
    string ans = "";
    string res ="";
    while(a.size() < 9){
        a = '0' + a;
    }
    ans = a.substr(0, 3);
    if(ans != "000"){
        res += triplet(ans);
        res += " million ";
    }
    ans = a.substr(3, 3);
    if(ans != "000"){
        res += triplet(ans);
        res += " thousand ";
    }
    ans = a.substr(6,3);
    res += triplet(ans);
    return res;
}
int main(){
    string a;
    cin >> a;
    string res = "";
    if(a[0] == '-'){
        a.erase(0,1);
        res += "negative ";
    }
    res += numToText(a);
    cout << res;
}
// nine hundred thirty-two million three hundred forty-three thousand
// nine hundred thirty-two million three hundred forty-three thousand

