// 입력받는 수의 최대 자리수가 10^5이기 때문에 long long으로도 커버가 안 되므로 string으로 입력받아주어야한다. 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
typedef long long ll;
using namespace std;

char n[100000];
ll sum;
int z;
vector<int> v;
bool cmp(int a, int b){
    return a > b;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string tmp;
    cin>> tmp;
    strcpy(n, tmp.c_str());
    
    for(int i = 0; i < tmp.size(); i++){
        if((int)n[i] - 48 == 0){
            z = 1;
        }
        v.push_back((int)n[i] - 48);
        sum += (int)n[i] - 48;
    }
    
    sort(v.begin(), v.end(), cmp);
    if(sum % 3 == 0 && z == 1){
        for(int i = 0; i < v.size(); i++){
            cout<< v[i];
        }
    }else{
        cout<< -1;
    }

}