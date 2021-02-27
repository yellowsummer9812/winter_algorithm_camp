#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int n;
int primeNums[500];
bool isNotPrime[50000001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int j = 0;
    isNotPrime[0] = isNotPrime[1] = true;
    for(int i = 2; i * i <= 5000000; i++){
        if(isNotPrime[i] == false){
            primeNums[j++] = i;
            for(int k = i * i; k <= 5000000; k += i){
                isNotPrime[k] = true;
            }
        }
    }

    cin>> n;

    int tmp;
    while(n--){
        cin>> tmp;

        while(tmp > 1){
            if(isNotPrime[tmp]){
                for(int i = 0; i < j; i++){
                    if(tmp % primeNums[i] == 0){
                        cout<< primeNums[i]<< ' ';
                        tmp /= primeNums[i];
                        break;
                    }
                }
            }else{
                cout<< tmp;
                tmp = -1;
            }
        }
        cout<< '\n';
    }
}