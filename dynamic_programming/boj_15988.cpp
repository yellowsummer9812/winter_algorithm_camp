#include <iostream>
#define MAX 1000001
using namespace std;

int t, n;
long long f[MAX];
long long m = 1000000009;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    f[1] = 1, f[2] = 2, f[3] = 4;
    for(int i = 4; i < MAX; i++){
        f[i] = f[i - 1] + f[i - 2] + f[i - 3];
        f[i] %= m;
    }
    
    cin>> t;
    for(int i = 0; i < t; i++){
        cin>> n;
        cout<< f[n]<< '\n';
    }
}