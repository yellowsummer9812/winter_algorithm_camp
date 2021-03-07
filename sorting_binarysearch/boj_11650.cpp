#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> v;
vector<pair<int, int>> tmp;

void merge(int low, int high){
    int mid = (low + high) / 2;
    int i = low, j = mid + 1;
    int k = low;

    while(i <= mid && j <= high){
        if(v[i].first < v[j].first){
            tmp[k++] = v[i++];
        }else if(v[i].first == v[j].first){
            if(v[i].second < v[j].second){
                tmp[k++] = v[i++];
            }else{
                tmp[k++] = v[j++];
            }
        }else{
            tmp[k++] = v[j++];
        }
    }

    while(i <= mid) tmp[k++] = v[i++];
    while(j <= high) tmp[k++] = v[j++];

    for(int a = low; a <= high; a++) {
        v[a] = tmp[a];
    }
}

void mergesort(int low, int high){
    if(low == high) return;
    int mid = (low + high) / 2;
    mergesort(low, mid);
    mergesort(mid + 1, high);
    merge(low, high);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin>> x>> y;
        v.push_back({x, y});
        tmp.push_back({0, 0});
    }

    mergesort(0, v.size() - 1);

    for(int i = 0; i < v.size(); i++){
        cout<< v[i].first<< " "<< v[i].second<< '\n';
    }
}