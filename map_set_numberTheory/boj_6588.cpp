#include <iostream>
#include <vector>
#define MAX 1000001
typedef long long ll;
using namespace std;

vector<ll> primeNums;
bool g;
bool isNotPrime[MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    isNotPrime[0] = isNotPrime[1] = true;
    for(ll i = 2; i < MAX; i++){
        if(isNotPrime[i] == false){
            primeNums.push_back(i);
            for(ll k = i; i * k < MAX; k++){
                isNotPrime[i * k] = true;
            }
        }
    }

    while(1){
        ll n;
        cin>> n;
        if(n == 0) break;

        for(ll i = 0; i < primeNums.size(); i++){
            if(n < primeNums[i]) break;

            ll a = n - primeNums[i];
            if(!isNotPrime[a]){
                cout<< n<< " = "<< primeNums[i]<< " + "<< a<<'\n';
                g = true;
                break;
            }
        }

        if(!g){
            cout<< "Goldbach's conjecture is wrong.\n";
        }
    }
    
}