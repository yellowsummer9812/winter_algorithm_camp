#include <iostream>
#include <map>
using namespace std;

// 메모리 제한이 8MB이고 입력받는 수의 최댓값이 10000000이어서
// int가 10000000개 있으면 이미 40MB이기 때문에 기본적인 정렬 알고리즘으로 풀지 않음 
int n;
int num[10001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    for(int i = 0; i < n; i++){
        int tmp;
        cin>> tmp;
        num[tmp]++;
    }

    for(int i = 1; i < 10001; i++){
        if(num[i] == 0) continue;
        while(num[i] != 0){
            cout<< i<<'\n';
            num[i]--;
        }
    }
}