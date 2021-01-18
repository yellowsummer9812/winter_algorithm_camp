#include <iostream>
using namespace std;

int n, ans;
int isUsed1[14]; // 열
int isUsed2[26];  // 우측상향
int isUsed3[26];  // 좌측상향

void solve(int row){ // 행
    if(n <= row){
        ans++;
        return;
    }
    int a, b;
    for(int i = 0; i < n; i++){ // 열
        a = row + i;
        b = row - i + n - 1;
        if(isUsed1[i] || isUsed2[a] || isUsed3[b])  continue;
        isUsed1[i] = 1;
        isUsed2[a] = 1;
        isUsed3[b] = 1;
        solve(row + 1);
        isUsed1[i] = 0;
        isUsed2[a] = 0;
        isUsed3[b] = 0;
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    solve(0);
    cout<< ans;
}