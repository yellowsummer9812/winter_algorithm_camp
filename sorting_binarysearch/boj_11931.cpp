#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    vector<int> v;
    int tmp;
    for(int i = 0; i < n; i++){
        cin>> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < n; i++){
        cout<< v[i]<< '\n';   
    }
}