#include <iostream>
#define MAX 1025
using namespace std;

int n, m;
long long pre[MAX][MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n>> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            long long tmp;
            cin>> tmp;
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + tmp;
        }
    }
    int x1, y1, x2, y2;
    for(int i = 1; i <= m; i++){
        cin>> x1>> y1>> x2>> y2;
        cout<< pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1]<< '\n';
    }
}