#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<>> pq;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    int m;
    while(n--){
        cin>> m;
        if(m != 0){
            pq.push(m);
        }else{
            if(!pq.empty()){
                cout<< pq.top()<<'\n';
                pq.pop();
            }else{
                cout<< 0<< '\n';
            }
        }
    }
}