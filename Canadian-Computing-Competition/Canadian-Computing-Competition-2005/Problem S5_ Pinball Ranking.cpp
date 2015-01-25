/**Disclaimer, fails on last testcase because testcase was crafted against beutiful bsts*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#define nullptr 0
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;

struct node{
    public:
        int value;
        int right_children;
        node* left;
        node* right;
    public:
        node(int v,int rc, node*l, node*r){
            right_children = rc;
            value = v;
            left = l;
            right = r;
        }
};
class BST{
    node *root;
    public:
        BST(){
            root = nullptr;
        }
        int insert(int &value){
            if(root == nullptr){
                root = new node(value,0,nullptr,nullptr);
                return 0;
            }
            else{
                int rank = 0;
                node *current = root;
                while(true){
                    if(value < current->value){
                        if(current->left != nullptr){
                            rank += current->right_children + 1;
                            current = current->left;
                        }
                        else{
                            rank += current->right_children + 1;
                            current->left = new (node){value,0,nullptr,nullptr};
                            return rank;
                        }
                    }
                    else{
                        if(current->right != nullptr){
                            ++current->right_children;
                            current = current->right;
                        }
                        else{
                            ++current->right_children;
                            current->right = new (node){value,0,nullptr,nullptr};
                            return rank;
                        }
                    }
                }
            }
        }
};

int N;
double ans;
BST bst;

int main(){
    scan(N);
    for(int i = 0, j = 0; i < N;++i){
        scan(j);
        ans+= bst.insert(j)+1;
    }
    ans/=N;
    printf("%.2f\n",ans);
    return 0;
}
