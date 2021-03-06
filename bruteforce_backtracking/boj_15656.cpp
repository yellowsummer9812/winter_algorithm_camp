#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 8
using namespace std;

int n, m;
vector<int> v;
vector<int> ans;

void solve(int level){
    if(m <= level){
        for(int j = 0; j < ans.size(); j++){
            cout<< ans[j]<< " ";
        }
        cout<<"\n";
        return;
    }

    for(int j = 0; j < v.size(); j++){
        ans.push_back(v[j]);
        solve(level + 1);
        ans.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n>> m;
    int tmp;
    for(int i = 0; i < n; i++){
        cin>> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    solve(0);
}