#include <iostream>
#define MAX 1001
using namespace std;

int n;
int cnt;
int isPrime[MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    fill_n(isPrime, MAX, 1);
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2; i * i < MAX; i++){
        if(isPrime[i]){
            for(int j = i * i; j < MAX; j += i){
                isPrime[j] = 0;
            }
        }
    }

    cin>> n;
    int a;
    while(n--){
        cin>> a;
        if(isPrime[a]) cnt++;
    }

    cout<< cnt;
}