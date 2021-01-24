#include <iostream>
using namespace std;

int n;
int num[1000];

void merge(int low, int mid, int high){
    int r = low;
    int l = mid + 1;
    int a = low;
    int tmp[1000];
    while(r <= mid && l <= high){
        if(num[r] < num[l]){
            tmp[a++] = num[r++];
        }else{
            tmp[a++] = num[l++];
        }
    }
    
    while(r <= mid){
        tmp[a++] = num[r++];       
    }
    while(l <= high){
        tmp[a++] = num[l++];
    }
    for(int i = low; i <= high; i++){
        num[i] = tmp[i];
    }
    
}

void merge_sort(int low, int high){
    if(low == high) return;
    int mid = (low + high) / 2;
    merge_sort(low, mid);
    merge_sort(mid + 1, high);
    merge(low, mid, high);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    int tmp;
    for(int i = 0; i < n; i++){
        cin>> num[i];
    }

    merge_sort(0, n - 1);
    for(int i = 0; i < n;i++){
        cout<< num[i]<< '\n';
    }
}