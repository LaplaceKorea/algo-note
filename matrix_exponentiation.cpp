#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://riptutorial.com/algorithm/example/24256/
// http://codeforces.com/contest/1117/problem/D
ll n, m;

void mat_mul(ll m1[105][105], ll m2[105][105]) {
    ll tp[105][105];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            tp[i][j] = 0;
            for(int k = 0; k < m; k++) {
                tp[i][j] += m1[i][k] * m2[k][j];
                tp[i][j] %= 1000000007;
            }
        }
    }
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            m1[i][j] = tp[i][j];
        }
    }    
}

ll mat[105][105];
ll sum_mat[105][105];
int main() {
    cin >> n >> m;
    
    // f(n) = f(n-1) + f(n-m)
    
    /*
    ( . 1 . . . . . )  ( f(0)   )   ( f(1)   )
    ( . . 1 . . . . )  ( ...    )   ( ...    )
    ( . . . . . . . )  ( ...    ) = ( ...    )
    ( ............1 )  ( ...    )   ( ...    )
    ( 1...........1 )  ( f(m-1) )   ( f(m) = f(0) + f(m-1) )
    */
    
    for(int i = 0; i < m - 1; i++) {
        mat[i][i+1] = 1;
    }
    
    mat[m-1][0] = 1;
    mat[m-1][m-1] = 1;
    
    for(int i = 0; i < m; i++) {
        sum_mat[i][i] = 1; // identity matrix (f(m-1) = 1)
    }
    
    while(n > 0) {
//        cout << n << endl;
        if (n % 2 == 0) {
            mat_mul(mat, mat);
            n /= 2;
        } else {
            mat_mul(sum_mat, mat);
            n -= 1;
        }
    }
    
    cout << sum_mat[m-1][m-1] << endl;
}
