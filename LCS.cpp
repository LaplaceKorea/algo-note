#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int arr[1005][1005];

int main(){
    char a[1005];
    char b[1005];
    scanf("%s", a);
    scanf("%s", b);
    
    int la = strlen(a);
    int lb = strlen(b);
    
    for(int i = 1; i <= la; i++){
        for(int j = 1; j <= lb; j++){
            if(a[i-1] == b[j-1]) arr[i][j] = arr[i-1][j-1] + 1;
            else{
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }
    
    printf("%d\n", arr[la][lb]);
}
