#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int n, i;
int sum;
int alphabet[26]; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    cin.ignore();

    string tmp;
    // 문자열 입력받기
    for(i = 0; i < n; i++){
        getline(cin, tmp);
        reverse(tmp.begin(), tmp.end());
        for(int j = 0; j < tmp.length(); j++){
            alphabet[tmp[j] - 'A'] += pow(10, j);
        }
    }
   vector<int> a;
   for(i = 0; i < 26; i++){
       if(alphabet[i] == 0) continue;
       a.push_back(alphabet[i]);
   }
    sort(a.begin(), a.end(), greater<int>());

    int num = 9;
    for(i = 0; i < a.size(); i++){
        sum += a[i] * num;
        num--;
    }

    cout<< sum;
}