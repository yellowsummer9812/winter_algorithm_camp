#include <iostream>
#include <queue>
using namespace std;

long long a, b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> a>> b;

    queue<pair<long long, long long>> q;
    q.push({a, 1});

    while(q.size()){
        pair<long long, long long> tmp = q.front();
        q.pop();
        if(tmp.first == b){
            cout<< tmp.second;
            return 0;
        }else{
            if(tmp.first * 2 <= b){
                q.push({tmp.first * 2, tmp.second + 1});
            }
            if(tmp.first * 10 + 1 <= b){
                q.push({tmp.first * 10 + 1, tmp.second + 1});
            }
        }
        
    }
    cout<< -1;

}