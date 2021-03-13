#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<pair<int, string>> v;
bool cmp(pair<int, string> p1, pair<int, string> p2){
    return p1.first < p2.first;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    int age;
    string name;
    for(int i = 0; i < n; i++){
        cin>> age>> name;
        v.push_back({age, name});
    }
    stable_sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < v.size(); i++){
        cout<< v[i].first<<" "<< v[i].second<< "\n";
    }
}