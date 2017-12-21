/* References
    - http://jason9319.tistory.com/113?category=670441
*/

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 987654321

int main(){
    int n;
    int len = 0;
    scanf("%d", &n);
    
    vector<int> v;
    v.push_back(-INF);
    
    for(int i = 0, x; i < n; i++){
        scanf("%d", &x);
        if(v.back() < x){
            v.push_back(x);
            len++;
        } else {
            auto it = lower_bound(v.begin(), v.end(), x);
            *it = x;
        }
    }
    
    printf("%d\n", len);
}
