#include <iostream>
#include <vector>
using namespace std;

int n, i, cur_max, kill, kill_max;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    vector<int> v;
    cin>>n;
    int tmp;
    for(i = 0; i < n; i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    
    cur_max = v[0];
    for(i = 1; i < n; i++){
        if(v[i] < cur_max){
            kill++;
        }else{
            cur_max = v[i];
            if(kill > kill_max){ 
                kill_max = kill;
            }
            kill = 0;
        }
    }
    if(kill_max < kill){
        kill_max = kill;
    }
    cout<<kill_max;

}