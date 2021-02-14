#include <iostream>
#include <vector>
using namespace std;

struct TREENODE{
    int parent = -1;
    vector<int> children;
};

int n, root, del, leaf;
struct TREENODE tree[50];

void f(int num){
    if(num == del){
        if(tree[tree[num].parent].children.size() == 1){
            leaf++;
        }
        return;
    }

    if( tree[num].children.size() == 0){
        leaf++;
    }else{
        for(int i = 0; i < tree[num].children.size(); i++){
            f(tree[num].children[i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;

    int tmp;
    for(int i = 0; i < n; i++){
        cin>> tmp;
        if(tmp != -1){
            tree[i].parent = tmp;
            tree[tmp].children.push_back(i);
        }else{
            root = i;
        }
    }

    cin>> del;
    f(root);
    cout<< leaf;

}