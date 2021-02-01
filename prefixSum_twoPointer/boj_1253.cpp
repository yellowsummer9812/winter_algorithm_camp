#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    vector<long long> v;
    for(int i = 0; i < n; i++){
        long long tmp;
        cin>> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    
    for(int k = 0; k < v.size(); k++){
        int i = 0, j = v.size() - 1;
        long long sum;
        while(i < j){
            if(i == k){
                i++;
                continue;
            }
            if(j == k){
                j--;
                continue;
            }
            sum = v[i] + v[j];
            if(sum == v[k]) break;
            else if(sum < v[k]) i++;
            else j--;
        }
        if(sum == v[k]){
            ans++;
            continue;
        }
    }
    cout<< ans;
}