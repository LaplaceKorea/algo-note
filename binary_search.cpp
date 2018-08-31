#include<cstdio>
#include<algorithm> // lower_bound, upper_bound, sort
#include<vector>
using namespace std;

int main(){

    vector<int> v;
    for(int i = 0; i < 10; i++) v.push_back(i);
    for(int i = 11; i < 21; i++) v.push_back(i);

    int lower_idx = lower_bound(v.begin(), v.end(), 5) - v.begin();
    int upper_idx = upper_bound(v.begin(), v.end(), 5) - v.begin();

    //           l          
    // 0 1 2 3 4 5 6 7 8 9
    //             h
    
    printf("lower: %d\n", v[lower_idx]);
    printf("upper: %d\n", v[upper_idx]);


    int start = 0;
    int end = 20 - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (v[mid] < 10) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    printf("bsearch: %d\n", v[start]);
}
