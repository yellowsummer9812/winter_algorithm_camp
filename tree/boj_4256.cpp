#include <iostream>
using namespace std;

int tc, n;
int pre[1000];
int in[1000];

void solve(int pre_s, int pre_e, int in_s, int in_e){
    if(pre_s > pre_e || in_s > in_e){return;}
    int root = pre[pre_s];

    int i;
    for(i = 0; i < n; i++){
        if(in[i] == root){
            break;
        }
    }

    int l, r;
    l = i - in_s;
    r = in_e - i;
    solve(pre_s + 1, pre_s + l, in_s, i - 1); // 왼쪽 서브트리
    solve(pre_s + l + 1, pre_e, i + 1, in_e); // 오른쪽 서브트리
    cout<< root<< " ";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> tc;
    while(tc--){
        cin>> n;
        for(int i = 0; i < n; i++){
            cin>> pre[i];
        }
        for(int i = 0; i < n; i++){
            cin>> in[i];
        }
        solve(0, n - 1, 0, n - 1);
        cout<<"\n";
    }
}