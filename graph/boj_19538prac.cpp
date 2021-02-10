#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define MAX 200001
using namespace std;

int n, m;
vector<int> v[MAX]; // 이웃 정보
queue<int> q;
int answer[MAX]; // 0보다 작으면 루머 안 믿는 사람
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;

    for(int i = 1; i <= n; i++){
        answer[i] = -1; // answer : -1로 초기화
        string tmp;
        getline(cin, tmp, '0');

        for(char c : tmp){
            if('1' <= c && c <= '9'){
                v[i].push_back(c - '0');
            }
        }
    }

    cin>> m;
    for(int i = 0; i < m; i++){
        int tmp;
        cin>> tmp;
        answer[tmp] = 0;
        q.push(tmp);
    }

    queue<pair<int,int>> tmp;
    while(!q.empty()){
        while(!q.empty()){
            int cur = q.front(); q.pop();
            int half; 
            
            for(int i = 0; i < v[cur].size(); i++){
                if(answer[v[cur][i]] != -1) continue; // 이웃 중 루머 믿고있으면 스킵

                half = 1 + ((v[v[cur][i]].size() - 1) / 2) ; // cur의 이웃 중 루머를 안 믿는 이웃의 이웃 수 ㅋㅋ...

                int r = 0;
                //cur의 루머를 안 믿는 이웃 중에서 루머를 믿는 사람의 수 r 구하기
                for(int j = 0; j < v[v[cur][i]].size(); j++){
                    if(answer[v[v[cur][i]][j]] == -1) continue;
                    r++; 
                }

                // r이 half 이상이면 cur의 이웃은 루머를 믿게됨
                if(half <= r){
                    tmp.push({v[cur][i], answer[cur] + 1}); // 같은 시간대에 믿게되는 거는 나중에 한꺼번에 처리하기 위해 tmp 사용
                }
            }
        }
        // 여기서 한꺼번에 처리
        while(!tmp.empty()){
            pair<int, int> a = tmp.front(); tmp.pop();
            answer[a.first] = a.second;
            q.push(a.first);
        }
    }

    for(int i = 1; i <= n; i++){
        cout<< answer[i]<< " ";
    }
}