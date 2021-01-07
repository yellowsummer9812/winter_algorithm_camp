#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, i, j, k, result;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n >> m;
    vector<int> v_10;
    vector<int> v;
    int tmp;
    for(i = 0; i < n; i++){
        cin>> tmp;
        if((tmp % 10) == 0){
            if(tmp == 10) result++;
            v_10.push_back(tmp);
        }else{
            v.push_back(tmp);
        }
    }
    sort(v_10.begin(), v_10.end());
    i = 0; // i는 현재까지 자른 회수
    for(j = 0; j < v_10.size(); j++){
        if(v_10[j] == 10) continue;
        while(i < m){
            v_10[j] -= 10;
            i++;
            if(v_10[j] == 10){
                result += 2;
                break;
            }
            else{
                result++;
            }
        }
        if(m <= i) break;
    }
    if(i < m){
        for(j = 0; j < v.size(); j++){
            if(v[j] < 10) continue;
            while(i < m){
                v[j] -= 10;
                i++;
                result++;
                if(v[j] < 10){
                    break;
                }
            }
            if(m <= i) break;
        }
    }
    cout<<result;
}