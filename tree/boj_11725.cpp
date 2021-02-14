#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

struct TREENODE{
    int parent;
    vector<int> connect;
};

int n;
struct TREENODE tree[MAX];
bool check[MAX];

void f(int num){
    check[num] = true;

    for(int i = 0; i < tree[num].connect.size(); i++){
        if(check[tree[num].connect[i]] == true) continue;
        tree[tree[num].connect[i]].parent = num;
        f(tree[num].connect[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    int a, b;
    for(int i = 1; i <= n - 1; i++){
        cin>> a>> b;
        tree[a].connect.push_back(b);
        tree[b].connect.push_back(a);
    }

    f(1);
    for(int i = 2; i <= n; i++){
        cout<< tree[i].parent<< '\n';
    }
}