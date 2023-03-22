#include<bits/stdc++.h>
using namespace std;

int binary_search(int *arr, int sizeA, int target) {
    int low = 1, high = sizeA;
    while (low <= high) {
        int mid = low + (high - low)/2;
        if (*(arr + mid) == target)
            return mid;
        else if (*(arr + mid) < target)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}

int main(){
    int n,k;
    cin >> n >> k;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin >> *(arr+i);
    cout << binary_search(arr,n,k);
    return 0;
}
