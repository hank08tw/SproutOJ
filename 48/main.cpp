#include <iostream>
using namespace std;
struct binary_tree{
    int data;
    binary_tree* left;//binary_tree* left= nullptr;
    binary_tree* right;//binary_tree* right= nullptr;
};
void preorder(binary_tree* top,int num){
    if(num>top->data){
        if(top->right== nullptr){
            top->right=new binary_tree;
            top->right->data=num;
            top->right->left= nullptr;
            top->right->right= nullptr;
        }
        else{preorder(top->right,num);}
    }
    else if(num<top->data){
        if(top->left== nullptr){
            top->left=new binary_tree;
            top->left->data=num;
            top->left->left= nullptr;
            top->left->right= nullptr;
        }
        else{preorder(top->left,num);}
    }
}
void lastorder(binary_tree* top){
    if(top->left!=nullptr){
        lastorder (top->left);
    }
    if(top->right!=nullptr){
        lastorder (top->right);
    }
    cout << top->data << endl;
}
int main() {
    int num;
    binary_tree* thetree=new binary_tree;
    thetree->left= nullptr;
    thetree->right= nullptr;
    cin >> num;
    thetree->data=num;
    while(cin >> num){
        preorder(thetree,num);
    }
    lastorder(thetree);
    return 0;
}