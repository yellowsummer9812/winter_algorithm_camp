#include <iostream>
#include <queue>
using namespace std;

long long n, k, ans;
short check[100010];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n>> k;

    queue<pair<long long, long long>> q;
    q.push({n, 0});

    while(q.size()){
        pair<long long, long long> tmp = q.front();
        q.pop();
        if(tmp.first == k){
            ans = tmp.second;
            break;
        }else{
            
            if(!check[tmp.first + 1] && ((tmp.first + 1) <= k)){
                q.push({tmp.first + 1, tmp.second + 1});
                check[tmp.first + 1] = 1;
            }

            if( 2 * tmp.first <= 100000){
                q.push({tmp.first * 2, tmp.second + 1});
                check[tmp.first * 2] = 1;
            }
            
            if(!check[tmp.first - 1] && 0 <=(tmp.first - 1)){
                q.push({tmp.first - 1, tmp.second + 1});
                check[tmp.first - 1] = 1;
            }
        
        }
    }
    cout<< ans;
}