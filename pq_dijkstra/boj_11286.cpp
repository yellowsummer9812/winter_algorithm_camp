#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cmp{
    bool operator() (long long x, long long y){
        if(abs(x) == abs(y)) return x > y;
        return abs(x) > abs(y);
    }
};

int x;
priority_queue<long long, vector<long long>, cmp> pq;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> x;
    while(x--){
        int tmp;
        cin>> tmp;

        if(tmp == 0){
            if(pq.empty()){
                cout<< 0<< '\n';
            }else{
                cout<< pq.top()<< '\n';
                pq.pop();
            }
        }else{
            pq.push(tmp);
        }
    }
}