#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> a;

int binary_search(int b){
    int high = n - 1;
    int low = 0;
    int mid;
    while(high >= low){
        mid = (high + low) / 2;
        if(a[mid] == b) return 1;
        if(a[mid] > b) high = mid - 1;
        else low = mid + 1;
    }
    return 0;
}

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    int tmp;
    
    for(int i = 0; i < n; i++){
        cin>> tmp;
        a.push_back(tmp);
    }

    cin>> m;
    vector<int> b;
    for(int i = 0; i < m; i++){
        cin>> tmp;
        b.push_back(tmp);
    }
    sort(a.begin(), a.end());

    for(int i = 0; i < m; i++){
        cout<< binary_search(b[i])<< '\n';
    }
}