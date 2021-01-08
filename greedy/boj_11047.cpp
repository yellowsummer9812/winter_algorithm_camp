#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, i, result;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n>> k;
    int tmp;
    vector<int> v;
    for(i = 0; i < n; i++){
        cin>> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), greater<>());
    for(i = 0; i < v.size(); i++){
        if(k < v[i]) continue;
        result += (k / v[i]);
        k -= ((k / v[i]) * v[i]);
    }
    cout<< result;

}