#include <iostream>
using namespace std;

struct BinaryTreeNode{
    int num;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

struct BinaryTreeNode tree[10000];
int add_index = 0;

void add(int key){
    struct BinaryTreeNode *p, *q, *r;

    p = tree;
    r = &tree[add_index];
    r -> num = key;
    r -> left = NULL;
    r -> right = NULL;

    if(add_index == 0){
        add_index++;
        return;
    }else{
        while(p != NULL){
            if(key < p->num){
               q = p;
               p = p->left;
            }else{
                q = p;
                p = p -> right;
            }
        }
        if(key < q -> num){
            q -> left = r;
        }else{
            q -> right = r;
        }
    }
    add_index++;
}

void post_order(struct BinaryTreeNode *p){
    if(p == NULL) return; 
    post_order(p -> left);
    post_order(p ->right);
    cout<< p -> num<< '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cin.tie(0);

    int a;
    while(cin>> a){
        add(a);
    }

    post_order(tree);
}