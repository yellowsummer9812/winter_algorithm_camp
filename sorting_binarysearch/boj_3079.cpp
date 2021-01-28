#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, m;
long long mid, ans;
vector<long long> line;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n>> m;
    for(int i = 0; i < n; i++){
        int tmp;
        cin>> tmp;
        line.push_back(tmp);
    }

    long long high = (*max_element(line.begin(), line.end())) * m;
    long long low = 1;
    while(high >= low){
        mid = (high + low) / 2;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum += mid / line[i];
            if(sum >= m) break;
        }

        if(sum >= m){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
 
    }
    cout<< ans;
}