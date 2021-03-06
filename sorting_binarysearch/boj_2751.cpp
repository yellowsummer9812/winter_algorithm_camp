#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;
int ans[1000000];

void merge(int low, int high){
    int mid = (low + high) / 2;
    int i = low, j = mid + 1;
    int a = low;

    while(i <= mid && j <= high){
        if(v[i] < v[j]){
            ans[a++] = v[i++]; 
        }else{
            ans[a++] = v[j++];
        }
    }
    
    while(i <= mid) ans[a++] = v[i++];
    while(j <= high) ans[a++] = v[j++];

    for(int k = low; k <= high; k++) v[k] = ans[k];
}

void mergeSort(int low, int high){
    if(low == high) return;
    int mid = (low + high) / 2;
    mergeSort(low, mid);
    mergeSort(mid + 1, high);
    merge(low, high);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    for(int i = 0; i < n; i++){
        int tmp;
        cin>> tmp;
        v.push_back(tmp);
    }
    mergeSort(0, v.size() - 1);

    for(int i = 0; i < n; i++){
        cout<< v[i]<<'\n';
    }
}