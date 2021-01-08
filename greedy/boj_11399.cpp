#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, i, result;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    vector<int> v;
    int tmp;
    for(i = 0; i < n; i++){
        cin>> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    tmp = 0;
    for(i = 0; i < v.size(); i++){
        tmp += v[i];
        result += tmp;
    }
    cout<< result;
}