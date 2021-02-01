#include <iostream>
#define MAX 100001
using namespace std;

long long g;
long long a[MAX];
int cnt;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> g;
    for(int i = 1; i < MAX; i++){
        a[i] = i * i;
    }
    int i = 1, j = 1;
    while(j < MAX){
        int dif = a[j] - a[i];
        if(dif == g){
            cout<< j<< '\n';
            j++;
            cnt++;
        }
        else if(dif < g) j++;
        else i++;
    }
    if(cnt == 0) cout<< -1;
}