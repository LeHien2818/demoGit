#include <bits/stdc++.h>

using namespace std;
void sortxuoi(int arr[]){
   int tmp;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3 - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
void sortnguoc(int arr[]){
   int tmp;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(arr[j] < arr[j + 1]){
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
int main(){
    int arr[3], arr1[3];
    bool b;
    int check1 = 0, check2 = 0;
    for(int i = 0; i < 3; i++){
        cin >> arr[i];
        arr1[i] = arr[i];
    }
    sortxuoi(arr);
    for(int i = 0; i < 3; i++){
        if(arr[i] == arr1[i]){
            check1++;
        }
    }
    sortnguoc(arr);
    for(int i = 0; i < 3; i++){

    }
    for(int i = 0; i < 3; i++){
        if(arr[i] == arr1[i]){
            check2++;
        }
    }
    cout << check2 <<" ";
    if(check1 == 3 || check2 == 3){
        b = true;
        cout << b ;
        return 0;
    }else{
        b = false;
        cout << b ;
    }
}


