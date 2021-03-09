#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ans;
vector<int> v;

void search(int low, int high){
    int mid;
    int a;
    while(low <= high){
        a = m;
        mid = (low + high) / 2;
        for(int i = 0; i < n; i++){
            if(v[i] < mid){
                a -= v[i];
            }else{
                a -= mid;
            }
        }

        if(a < 0){
            high = mid - 1;
        }else{
            ans = mid;
            low = mid + 1;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    int tmp;
    for(int i = 0; i < n; i++){
        cin>> tmp;
        v.push_back(tmp);
    }
    cin>> m;
    sort(v.begin(), v.end());

    tmp = 0;
    for(int i = 0; i < n; i++){
        tmp += v[i];
    }

    if(tmp <= m){
        ans = v[n - 1];
    }else{
        search(0, v[n - 1]);
    }
    cout<< ans;
}