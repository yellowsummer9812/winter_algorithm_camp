#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, i, j, result;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>>n;
    n *= 2;
    vector<int> v;
    int tmp;
    for(i=0; i < n; i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    result = v[0] + v[n - 1];
    for(i = 1, j = (n - 2); i < j; i++ , j--){
        result = min(result, v[i] + v[j]);
    }
    cout<<result;
    
}