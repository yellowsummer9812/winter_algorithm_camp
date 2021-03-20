#include <iostream>
using namespace std;

int n, s;
int a[20];
int ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n>> s;
    for(int i = 0; i < n; i++){
        cin>> a[i];
    }

    for(int i = 0; i < n; i++){// 수열의 원소 개수 -1
        for(int j = 0; j + i < n; j++){// 수열의 시작하는 수
            int tmp = 0;
            for(int k = 0; k <= i; k++){
                tmp += a[j + k];
            }
            if(tmp == s) {
                ans++;
            }
        }
    }
    cout<< ans;
}