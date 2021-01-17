#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int isUsed[10];
vector<int> v;

void solve(int level){
    if(m <= level){
        for(int i = 0; i < v.size(); i++){
            cout<< v[i]<< " ";
        }
        cout<< '\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        if(isUsed[i] == 1) continue;
        isUsed[i] = 1;
        v.push_back(i);
        solve(level + 1);
        v.pop_back();  
        isUsed[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n>> m;
    solve(0);
}
