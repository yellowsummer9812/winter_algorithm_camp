#include <iostream>
using namespace std;

int n, s;
int a[21];
int ans;

void solve(int tmp, int i){
    if(i > n) return;

    if(tmp + a[i] == s){
        ans++;
    }
    for(int j = i + 1; j <= n; j++){
        solve(tmp + a[i], j);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n>> s;
    for(int i = 1; i <= n; i++){
        cin>> a[i];
    }

    
    for(int i = 1; i <= n; i++){
        int tmp = 0;
        solve(tmp, i);
    }
    
    cout<< ans;
}