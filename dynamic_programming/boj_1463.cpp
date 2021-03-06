#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001]; // index의 연산 최솟값

int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    dp[1] = 0, dp[2] = 1, dp[3] = 1;
    for(int i = 4; i <= n; i++){
        dp[i] = dp[i-1] + 1;
        if(i % 3 == 0){
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
        if(i % 2 == 0){
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
    }
    cout<< dp[n];
}