#include <iostream>
#define MAX 10001
using namespace std;

int n, m, i, j;
long long ans, sum;
long long a[MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n>> m;
    for(int i = 1; i <= n; i++){
        cin>> a[i];
    }
    i = 1, j = 1, sum = a[1];
    while(j <= n){
        if(sum == m){
            ans++;
            sum += a[++j];
        }else if(sum < m){
            sum += a[++j];
        }else{
            sum -= a[i++];
        }
    }
    cout<< ans;
}