#include <iostream>
#include <vector>
#include "math.h"
#define SWAP(a,b) a=a+b,b=a-b,a=a-b
using namespace  std;
struct node{
    int data;
    int parent_dir;//0沒有parent, 1parent在左邊2parent在右邊
    node* left;
    node* right;
    node* parent;
};
void findbiggest(node* thenode,int* num){
    if(thenode->right== nullptr){
        (*num)=thenode->data;
    }
    else{
        findbiggest(thenode->right,num);
    }
}
//bst節點刪除1.沒有左右子樹->直接刪除2.只有左子樹->刪除後接到parent（parent可能在左右邊）3.只有右子樹同理4.有左右子樹->刪除後找左子數的最大值
void insert(int num,node** thenode){//logn
    if((*thenode)== nullptr) {
        (*thenode)=new node;
        (*thenode)->data=num;
        (*thenode)->parent= nullptr;
        (*thenode)->left= nullptr;
        (*thenode)->right= nullptr;
        (*thenode)->parent_dir=0;
    }
    else{
        if(num>(*thenode)->data){
            if((*thenode)->right== nullptr){
                (*thenode)->right=new node;
                (*thenode)->right->data=num;
                (*thenode)->right->left= nullptr;
                (*thenode)->right->right= nullptr;
                (*thenode)->right->parent=(*thenode);
                (*thenode)->right->parent_dir=1;
            }
            else{
                insert(num,&((*thenode)->right));
            }
        }
        else{
            if((*thenode)->left== nullptr){
                (*thenode)->left=new node;
                (*thenode)->left->data=num;
                (*thenode)->left->left= nullptr;
                (*thenode)->left->right= nullptr;
                (*thenode)->left->parent=(*thenode);
                (*thenode)->left->parent_dir=2;
            }
            else{
                insert(num,&((*thenode)->left));
            }
        }
    }
}
void deletee(int num,node* thenode){//logn
    if(num>thenode->data){
        deletee (num,thenode->right);//(*thenode)->right這個是node的地址 &(*thenode)->right這個是儲存node的一級指針的地址
    }
    else if(num<thenode->data){
        deletee (num,thenode->left);
    }
    else{
        if(thenode->left== nullptr&&thenode->right== nullptr){
            if(thenode->parent_dir==1){
                thenode->parent->right= nullptr;
                delete(thenode);
            }
            else{
                thenode->parent->left= nullptr;
                delete(thenode);
            }
        }
        else if(thenode->left!= nullptr&&thenode->right== nullptr){
            if(thenode->parent_dir==1){
                thenode->parent->right=thenode->left;
                thenode->left->parent=thenode->parent;
                thenode->left->parent_dir=1;
                delete((thenode));
            }
            else if(thenode->parent_dir==2){
                (thenode)->parent->left=(thenode)->left;
                (thenode)->left->parent=(thenode)->parent;
                (thenode)->left->parent_dir=2;
                delete((thenode));
            }
        }
        else if((thenode)->left== nullptr&&(thenode)->right!= nullptr){
            if((thenode)->parent_dir==1){
                (thenode)->right->parent=(thenode)->parent;
                (thenode)->right->parent_dir=1;
                (thenode)->parent->right=(thenode)->right;
                delete(thenode);
            }
            else{
                (thenode)->right->parent=(thenode)->parent;
                (thenode)->right->parent_dir=2;
                (thenode)->parent->left=(thenode)->right;
                delete(thenode);
            }
        }
        else{
            int tmp=-1;
            findbiggest ((thenode)->left,&tmp);
            (thenode)->data=tmp;
            deletee(tmp,thenode->left);
        }
    }
}

void query(int num,node* thenode,int* distance,int* ans1,int* ans2){//logn
    if(abs(num-thenode->data)<(*distance)||*distance==-1){
        (*distance)=abs(num-thenode->data);
        *ans1=thenode->data;
        *ans2=-2000000000;
    }
    else if(abs(num-thenode->data)==(*distance)){
        *ans2=thenode->data;
    }
    if(num>thenode->data&&thenode->right!= nullptr){
        query (num,thenode->right,distance,ans1,ans2);
    }
    else if(num<thenode->data&&thenode->left!= nullptr){
        query (num,thenode->left,distance,ans1,ans2);
    }
}
int main() {
    int num,i,storenum;
    string op;
    cin >> num;
    node* thenode= nullptr;
    for(i=0;i<num;i++){
        cin >> op;
        cin >> storenum;
        if(op=="insert"){
            insert(storenum,&thenode);
        }
        else if(op=="query"){
            int distance=-1;
            int ans1=-2000000000,ans2=-2000000000;
            query(storenum,thenode,&distance,&ans1,&ans2);
            if(ans1>ans2&&ans2!=-2000000000){
                SWAP(ans1,ans2);
            }
            if(ans2!=-2000000000){cout << ans1 << " " << ans2;}
            else{cout << ans1;}
            cout << endl;
        }
        else if(op=="delete"){
            if(thenode->parent== nullptr&&thenode->left== nullptr&&thenode->right== nullptr){
                delete(thenode);
                thenode= nullptr;
            }
            else if(thenode->left!= nullptr&&thenode->right== nullptr&&thenode->parent== nullptr&&storenum==thenode->data){
                thenode=thenode->left;
                delete(thenode->parent);
                thenode->parent= nullptr;
                thenode->parent_dir=0;
            }
            else if((thenode)->left== nullptr&&(thenode)->right!= nullptr&&(thenode)->parent== nullptr&&storenum==thenode->data){
                (thenode)=(thenode)->right;
                delete((thenode)->parent);
                (thenode)->parent= nullptr;
                (thenode)->parent_dir=0;
            }
            else{
                deletee(storenum,thenode);
            }
        }
    }
    return 0;
}
//if(thenode!= nullptr){
//    printtree (thenode);
//}
/*
void printtree(node* thenode){
    vector<node*> tree;
    tree.push_back (thenode);
    while(!tree.empty ()){
        int size=(int)tree.size ();
        for(int i=0;i<size;i++){
            cout << tree[i]->data << " ";
            if(tree[i]->left!= nullptr){
                tree.push_back (tree[i]->left);
            }
            if(tree[i]->right!= nullptr){
                tree.push_back (tree[i]->right);
            }
        }
        tree.erase (tree.begin (),tree.begin ()+size);
        cout << endl;
    }
}
 */

/*
#include <iostream>
#include <string>
#include <cassert>

struct Node {
  Node(int num = 0, Node* lft = NULL, Node* rgt = NULL):
    num_(num), lft_(lft), rgt_(rgt) {}
  int num_;
  Node* lft_;
  Node* rgt_;
};

void printTree(Node* pNode, int indent = 0) {
  for (int i = 0; i < indent; ++i)
    std::cout << "  ";
  if (pNode == NULL) {
    std::cout << "X" << std::endl;
  } else {
    std::cout << pNode->num_ << std::endl;
    printTree(pNode->lft_, indent + 1);
    printTree(pNode->rgt_, indent + 1);
  }
}

void insertNode(Node** ppNode, int num) {
  while (*ppNode != NULL) {
    if (num < (*ppNode)->num_) {
      ppNode = &((*ppNode)->lft_);
    } else {
      ppNode = &((*ppNode)->rgt_);
    }
  }
  *ppNode = new Node(num);
}

Node** findNode(Node** ppNode, int num) {
  while (*ppNode != NULL) {
    if ((*ppNode)->num_ == num)
      return ppNode;
    if (num < (*ppNode)->num_) {
      ppNode = &((*ppNode)->lft_);
    } else {
      ppNode = &((*ppNode)->rgt_);
    }
  }
  // not found
  return NULL;
}

Node** findMaxNode(Node** ppNode) {
  while ((*ppNode)->rgt_ != NULL)
    ppNode = &((*ppNode)->rgt_);
  return ppNode;
}

void deleteNode(Node** ppNode, int num) {
  Node** ppDelNode = findNode(ppNode, num);
  while (1) {
    assert(ppDelNode != NULL);
    Node* pDelNode = *ppDelNode;
    if (pDelNode->lft_ == NULL && pDelNode->rgt_ == NULL) {
      *ppDelNode = NULL;
      delete pDelNode;
      break;
    } else if (pDelNode->lft_ == NULL) {
      *ppDelNode = pDelNode->rgt_;
      delete pDelNode;
      break;
    } else if (pDelNode->rgt_ == NULL) {
      *ppDelNode = pDelNode->lft_;
      delete pDelNode;
      break;
    } else {
      Node** ppMaxNode = findMaxNode(&(pDelNode->lft_));
      pDelNode->num_ = (*ppMaxNode)->num_;
      ppDelNode = ppMaxNode;
    }
  }
}

void queryNode(Node* pNode, int num) {
  Node *lNode = NULL, *rNode = NULL;
  while (pNode != NULL) {
    if (num < pNode->num_) {
      rNode = pNode;
      pNode = pNode->lft_;
    } else if (num > pNode->num_) {
      lNode = pNode;
      pNode = pNode->rgt_;
    } else {
      lNode = rNode = pNode;
      break;
    }
  }
  assert(lNode != NULL || rNode != NULL);
  if (lNode == rNode) {
    std::cout << lNode->num_ << std::endl;
  } else if (lNode == NULL) {
    std::cout << rNode->num_ << std::endl;
  } else if (rNode == NULL) {
    std::cout << lNode->num_ << std::endl;
  } else {
    if (num - lNode->num_ < rNode->num_ - num) {
      std::cout << lNode->num_ << std::endl;
    } else if (num - lNode->num_ > rNode->num_ - num) {
      std::cout << rNode->num_ << std::endl;
    } else {
      std::cout << lNode->num_ << " " << rNode->num_ << std::endl;
    }
  }
}

int main() {
  int T;
  std::string op;
  int num;
  Node* pRoot = NULL;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    std::cin >> op >> num;
    if (op == "insert") {
      insertNode(&pRoot, num);
    } else if (op == "delete") {
      deleteNode(&pRoot, num);
    } else if (op == "query") {
      queryNode(pRoot, num);
    }
    // printTree(pRoot);
  }
  return 0;
}
 */