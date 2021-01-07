#include <iostream>
#include <vector>
using namespace std;

int n, i, tmp, result;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>>n;
    vector<int> v;
    for(i = 0; i < n; i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    for(i = n-2; i >= 0; i--){
        if(v[i+1] <= v[i]){
            result += v[i] - (v[i+1] - 1);
            v[i] = v[i+1] - 1;
        }
    }
    cout<<result;

}