#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct team{
    int id;
    int *question;
    int submit_count;
    int last_submit_time;
    int total;
};

int tc;
vector<struct team> v;

bool cmp(struct team a, struct team b){
    if(a.total != b.total){
        return a.total > b.total;
    }else if(a.submit_count != b.submit_count){
        return a.submit_count < b.submit_count;
    }else{
        return a.last_submit_time < b.last_submit_time;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie();

    cin>> tc;
    int n, k, t, m;
    while(tc--){
        cin>> n>> k>> t>> m;
        for(int i = 1; i <= n; i++){
            struct team tmp;
            tmp.id = i;
            tmp.question = new int[k + 1]();
            tmp.submit_count = 0;
            tmp.last_submit_time = 0;
            tmp.total = 0;
            v.push_back(tmp);
        }

        int i, j, s;
        for(int p = 1; p <= m; p++){
            cin>> i>> j>> s;
            if(v[i - 1].question[j] < s){
                v[i - 1].question[j] = s;
            }
            v[i - 1].submit_count++;
            v[i - 1].last_submit_time = p;
        }

        for(int p = 0; p < n; p++){
            for(int q = 1; q <= k; q++){
                v[p].total += v[p].question[q];
            }
        }

        sort(v.begin(), v.end(), cmp);

        for(int p = 0; p < n; p++){
            if(v[p].id == t){
                cout<< p + 1<< '\n';
                break;
            }
        }

        for(int p = 0; p < n; p++){
            delete[] v[p].question;
        }
        v.clear();
        vector <struct team>().swap(v);
    }
}