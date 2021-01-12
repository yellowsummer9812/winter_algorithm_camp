#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first > b.first;
}


int n, i, j, result;
int schedule[MAX + 1]; // 0: 과제 배정 안 됨, 1: 과제 배정 됨
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    int d, w;
    vector<pair<int, int>> v;
    for(i = 0; i < n; i++){
        cin>> d>> w;
        v.push_back({w, d}); // 벡터에는 과제 점수부터 push
    }
    sort(v.begin(), v.end(), cmp); // 과제 점수로 내림차순 정리
    
    // 과제 배정
    for(i = 0; i < v.size(); i++){ // i는 벡터 v에 대한 index
        for(j = v[i].second; 0 < j; j--){ // j는 배열 schedule에 대한 index
            if(schedule[j] != 1){
                schedule[j] = 1;
                result += v[i].first;
                break;
            }
        }
    }
    
    cout<< result;
}