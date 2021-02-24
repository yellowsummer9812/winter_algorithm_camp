#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

int n;
int dist[MAX][MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    int tmp;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>> tmp;
            dist[i][j] = tmp;
        }
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dist[i][j] == 1) continue;
                if(dist[i][k] && dist[k][j]){
                    dist[i][j] = 1;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout<< dist[i][j]<< " ";
        }
        cout<< '\n';
    }
}