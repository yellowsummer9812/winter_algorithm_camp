#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int ans;
vector<int> a;
vector<int> b;

bool cmp(int x, int y){
    return x > y;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    int tmp;
    for(int i = 0; i < n; i++){
        cin>>tmp;
        a.push_back(tmp);
    }
    for(int i = 0; i < n; i++){
        cin>>tmp;
        b.push_back(tmp);
    }
    sort(b.begin(), b.end());
    sort(a.begin(), a.end(), cmp);

    for(int i = 0; i < n; i++){
        ans += a[i] * b[i];
    }
    cout<< ans;
}