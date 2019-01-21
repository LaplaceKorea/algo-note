// code adapted from https://github.com/kjp4155/icpc-teamnote/blob/master/src/String/KMP.cpp

#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
using namespace std;

vector<int> kmp_table(string p) {
    int m = p.size();
    vector<int> table(m); // table[i] ==> prefix == suffix length in [0, i] 
    int j = 0;
    
    table[0] = 0;
    for(int i = 1; i < m; i++){
        while(j > 0 && p[i] != p[j]) j = table[j-1];
        if ( p[i] == p[j] ) {
            table[i] = j+1; // [0, j]
            j++;
        } else {
            table[i] = 0;
        }
    }
    return table;
}

vector<int> kmp(string s, string p){
    vector<int> table = kmp_table(p);
    vector<int> ans;
    int n = s.size();
    int m = p.size();
    int j = 0;
    
    for(int i = 0; i < n; i++){
        while(j > 0 && s[i] != p[j]) j = table[j-1];
        if ( s[i] == p[j] ) {
            if ( j == m-1 ) {
                ans.push_back(i-m+1);
                j = table[j];
            } else {
                j++;
            }
        }
    }
    return ans;
}

// https://www.acmicpc.net/problem/1786
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string s;
    string p;
    
    getline(cin, s);
    getline(cin, p);
    
    vector<int> matches = kmp(s, p);
    cout << matches.size() << '\n';
    for(int i: matches) {
        cout << i+1 << '\n';
    }
}
