#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int x, y, m, js_m, i, j;
vector<int> result;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> x>> y>> m;
    js_m = m;
    int tmp;
    vector<int> enemy;
    vector<int> potion;
    for(i = 0; i < x; i++){
        cin>> tmp;
        enemy.push_back(tmp);
    }
    for(i = 0; i < y; i++){
        cin>> tmp;
        potion.push_back(tmp);
    }

    i = 0; // i : 처리한 적 수 - 1
    j = 0; // j : 먹은 포션 수 - 1
    while(i < x || j < y){
        // 일단 적이 남아있어야함(i < x), 그리고 체력이 절반보다 많아야하거나 포션이 안남아있거나
        if(((i < x) && (js_m > (m / 2))) || ((i < x) && (y <= j))){ // 적과 싸우는 경우
            js_m -= enemy[i];
            if(js_m <= 0){
                break;
            }
            result.push_back(-(i + 1));
            i++;
        }else if(((j < y) && (js_m <= (m / 2))) || ((j < y) && (x <= i))){ // 포션을 먹는 경우
            // 일단 포션이 있어야함(j < y), 그리고 체력이 절반보다 없거나 적이 안남아있거나.

            // 포션 먹었을 때 최대 체력을 넘어가면 그냥 최대체력만큼만 회복시킴
            if(js_m + potion[j] > m){
                js_m = m;
            }else{
                js_m += potion[j];
            }
            result.push_back(j + 1);
            j++;
        }
    }
   
    // 결과 출력
    if(js_m <= 0){
        cout<< 0 << "\n";
    }else{
        for(i = 0; i < result.size(); i++){
            cout<< result[i]<< "\n";
        }
    }

    return 0;
}