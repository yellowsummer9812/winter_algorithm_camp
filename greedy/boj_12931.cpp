#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 50

int n, i, zero_index, result;
int a[MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    vector<int> b;
    int tmp;
    for(i = 0; i < n; i++){
        cin>> tmp;
        b.push_back(tmp);
    }
    sort(b.begin(), b.end());

    // zero_index(마지막 0의 위치) 초깃값
    zero_index = -1;
    for(i = 0; i < b.size(); i++){
        if(b[i] == 0){
            zero_index = i;
        }
    } 

    while(zero_index != (n - 1)){
        for(i = zero_index + 1; i < b.size(); i++){ // 홀수이면 1 빼줌
            if(b[i] % 2 != 0){
                b[i] -= 1;
                result++;
                // 1 빼줬는데 0이됐으면 zero_index 갱신
                if(b[i] == 0){
                    zero_index = i;
                }
            }
        }
        if(zero_index != (n - 1)){
            // 전체 1/2배
            for(i = zero_index + 1; i < n; i++){
                b[i] /= 2;
            }
            result++;
        }
    }
    cout<< result;
}