#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int tc;
    cin>> tc;

    
    for(int i = 0; i < tc; i++){
        int n, m;
        cin>> n>> m;
       
        vector<pair<int, int>> v;
        for(int j = 0; j < n; j++){
            int tmp;
            cin>> tmp;

            v.push_back({tmp, j});
        }

        int cnt = 0;
        while(!v.empty()){
            pair<int, int> max = *max_element(v.begin(), v.end());

            pair<int, int> tmp = v[0];
            v.erase(v.begin());
          
        
            if(tmp.first < max.first){
                v.push_back(tmp);
            }else{
                cnt++;
                if(tmp.second == m){
                    cout<< cnt<<'\n';
                    break;
                }
            }
           
        }

    }
}