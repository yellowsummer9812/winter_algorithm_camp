#include <iostream>
#include <vector>
#define MAX 8
using namespace std;

int n, m;
vector<int> ans;
int level_state[MAX];

void solve(int level){

    if(m <= level){
        for(int i = 0; i < m; i++){
            cout<< ans[i] << " ";
        }
        cout<<endl;
        return;
    }

    for(int i = level_state[level]; i <= n; i++){
        ans.push_back(i);
        if(level + 1 != m)
            level_state[level + 1] = i;
        solve(level + 1);
        ans.pop_back();
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >>n>> m;
    level_state[0] = 1;
    solve(0);
}