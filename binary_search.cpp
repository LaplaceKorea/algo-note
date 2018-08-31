#include<cstdio>
#include<algorithm> // lower_bound, upper_bound, sort
#include<vector>
using namespace std;

int main(){

    vector<int> v(10);
    for(int i = 0; i < 10; i++) v.push_back(i);

    int lower_idx = lower_bound(v.begin(), v.end(), 5) - v.begin();
    int upper_idx = upper_bound(v.begin(), v.end(), 5) - v.begin();

    //           l          
    // 0 1 2 3 4 5 6 7 8 9
    //             h
    
    printf("lower: %d\n", v[lower_idx]);
    printf("upper: %d\n", v[upper_idx]);
}
