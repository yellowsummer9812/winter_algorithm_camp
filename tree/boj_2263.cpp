#include <iostream>
using namespace std;

int n;
int in[100000];
int post[100000];

void solve(int in_s, int in_e, int post_s, int post_e){
    if(in_s > in_e || post_s > post_e) return;
    int root = post[post_e];
    cout<< root<<" ";

    if(in_s == in_e && post_s == post_e){
        return;
    }

    // inorder에서 root가 어디있는지 찾기
    int ri;
    for(ri = 0; ri < n; ri++){
        if(in[ri] == root)
            break;
    }
    int l, r;
    l = ri - in_s;
    r = in_e - ri;

    solve(in_s, ri - 1, post_s, post_s + l - 1);
    solve(ri + 1, in_e,  post_s + l, post_e - 1);    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    for(int i = 0; i < n; i++){
        cin>> in[i];
    }
    for(int i = 0; i < n; i++){
        cin>> post[i];
    }

    solve(0, n - 1, 0, n - 1);
}