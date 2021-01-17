#include <iostream>
using namespace std;

int n, i, j, tmp, ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;

    for(i = n; 0 < i; i--){
        tmp = 0;
        j = i;
        tmp += j; // 자기 자신 더하기
        while(1){
            tmp += (j % 10);
            j /= 10;
            if(j == 0)
                break;
        }
        if(tmp == n){
            ans = i;
        }
    }
    cout<< ans;
}