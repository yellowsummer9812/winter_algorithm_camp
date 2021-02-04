#include <iostream>
#include <deque>
#define MAX 50
using namespace std;

int a[MAX];
int ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin>> n>> m;

    deque<int> dq;
    for(int i = 1; i <= n; i++){
        dq.push_back(i);
    }

    for(int i = 0; i < m; i++){
        cin>> a[i];
    }

    for(int i = 0; i < m; i++){
        //cout<< a[i]<<", " <<dq.front()<<endl;
        if(a[i] == dq.front()){
            dq.pop_front();
        }else{
            // dq 내의 index 찾기
            int idx;
            for(int j = 0; j < dq.size(); j++){
                if(dq[j] == a[i]){
                    idx = j + 1;
                }
            }
            
            if((dq.size() / 2 + 1) < idx){// 오른쪽 이동
                while(a[i] != dq.front()){
                    int tmp = dq.back();
                    dq.pop_back();
                    dq.push_front(tmp);
                    ans++;
                }
            }else{ // 왼쪽 이동
                while(a[i] != dq.front()){
                    int tmp = dq.front();
                    dq.pop_front();
                    dq.push_back(tmp);
                    ans++;
                }
            }
            dq.pop_front();
        }
    }
    cout<< ans;

}