#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;

int n, m;
long long pre[MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n>> m;
    for(int i = 1; i <= n; i++){
        long long tmp;
        cin>> tmp;
        pre[i] = pre[i - 1] + tmp;
    }
    for(int k = 1; k <= m; k++){
        long long i, j;
        cin >> i>> j;
        cout<< pre[j] - pre[i - 1]<< '\n';
    }
}