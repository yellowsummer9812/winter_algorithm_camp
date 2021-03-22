#include <iostream>
using namespace std;

// 앨버트의 최적 위치는 중요하지 않기 때문에
// two 포인터를 통해 연속된 2k+1개의 요소의 합이 가장 큰 것을 구하면 됨

int x[1000001];
int n, k;
int s = 1000000;
int e;
int tmp;
int ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n>> k;
    int xi,q;
    for(int i = 0; i < n; i++){
        cin>> q>> xi;
        x[xi] = q;
        if(xi < s){
            s = xi;
        }
        if(e < xi){
            e = xi;
        }
    }
    int a = s;
    int b = s + 2 * k;
    if(b > 1000000){
        b = 1000000;
    }
    for(int i = a; i <= b; i++){
        ans += x[i];
    }
    tmp = ans;
    while(b < e){
        tmp -= x[a++];
        tmp += x[++b];
        if(ans < tmp){
            ans = tmp;
        }
    }
    
    cout<< ans;
}