#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


bool cmp(string a, string b){
    if(a.size() == b.size()){
        return a.compare(b) < 0;
    }else{
        return a.size() < b.size();
    }
}


int n;
vector<string> v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    string tmp;
    for(int i = 0; i < n; i++){
        cin>> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end(), cmp);
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i = 0; i < v.size(); i++){
        cout<< v[i]<<'\n';
    }

}