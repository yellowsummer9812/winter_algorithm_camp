#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> class_time;
priority_queue<int, vector<int>, greater<>> end_time; // 끝나는 시간 담음
int ans = 1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;

    for(int i = 0; i < n; i++){
        int a, b;
        cin>> a>> b;
        class_time.push({a, b});
    }

    end_time.push(0);
    for(int i = 0; i < n; i++){
        if(end_time.top() <= class_time.top().first){
            end_time.push(class_time.top().second);
            class_time.pop(); end_time.pop();
        }else{
            ans++;
            end_time.push(class_time.top().second);
            class_time.pop();
        }
    }

    cout<< ans;
}