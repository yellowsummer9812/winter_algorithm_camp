#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
long long sum;
long long ans;
vector<long long> length;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> m>> n;
    for(int i = 0; i < n; i++){
        int tmp;
        cin>> tmp;
        length.push_back(tmp);
    }

    long long high = *max_element(length.begin(), length.end());
    long long low = 1;
    long long mid;

    while(high >= low){
        mid = (high + low) / 2;
        sum = 0;
        for(int i = 0; i < n; i++){
            if(length[i] < mid) continue;
            sum += length[i] / mid;
        }
        if(m <= sum){
            ans = mid;
            low = mid + 1;
        }else{
           high = mid - 1;
        }
    }
    cout<< ans;
}