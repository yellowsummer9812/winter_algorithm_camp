#include <iostream>
using namespace std;

int n;
long long f[100];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    for(int i = 1; i <= n; i++){
        if(i == 1 || i == 2) f[i] = 1;
        else f[i] = f[i - 1] + f[i - 2];
    }
    cout<< f[n];
}