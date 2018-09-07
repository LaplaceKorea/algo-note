#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int n = 10;
    int arr[n];
    for(int i = 0; i < n; i++) arr[i] = n-i;
    
    // normal sort ~ O(nlogn)
    sort(arr, arr+n);
    stable_sort(arr, arr+n)
    
    // pick only k'th element ~ O(n) 
    int k = 3;
    nth_element(arr, arr+k, arr+n);
    
    // partial sort ~ O(nlogk)
    partial_sort(arr, arr+k, arr+n);
}
