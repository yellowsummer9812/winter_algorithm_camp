#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int k = 1;
vector<int> v;

void solve(int level, int k){
    if(m <= level){
        for(int i = 0; i < v.size(); i++){
            cout<< v[i]<< " ";
        }
        cout<< '\n';
        return;
    }
    for(int i = k; i <= n; i++){
        v.push_back(i);
        solve(level + 1, i + 1);
        v.pop_back(); 
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n>> m;
    solve(0, k);
}