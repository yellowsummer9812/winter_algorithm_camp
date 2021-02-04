#include <iostream>
#include <queue>
using namespace std;

int n, k;
int ans[5000];
queue<int> q;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n>> k;

    for(int i = 1; i <= n; i++)
        q.push(i);

    int cnt = 0;
    int i = 0;
    while(!q.empty()){
        cnt++;
        int a = q.front();
        q.pop();
        if(cnt == k){
            ans[i++] = a;
            cnt = 0;
        }else{
            q.push(a);
        }
    }
    cout<< "<";
    for(int i = 0; i < n; i++){
        cout<< ans[i];
        if(i != n - 1){
            cout<<", ";
        }
    }
    cout<< ">";
    
}