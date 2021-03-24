#include <iostream>
using namespace std;

double a[10001];
double m;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cout<< fixed;
    cout.precision(3);

    cin>> n;
    for(int i = 0; i < n; i++){
        cin>> a[i];
    }

    m = a[0];
    for(int i = 1; i < n; i++){
        if(a[i - 1] * a[i] > a[i]){
            a[i] = a[i - 1] * a[i];
        }
        if(m < a[i]){
            m = a[i];
        }
    }

    cout<< m;
}