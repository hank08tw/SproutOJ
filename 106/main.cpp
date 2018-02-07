#include <iostream>
#include <vector>
using namespace std;
struct node{
    int find;
    vector<node*> address;
};
void counting(node* thenode){
    if(thenode->find==0){
        thenode->find=1;
        for(int i=0;i<(thenode->address).size ();i++){
            counting(thenode->address[i]);
        }
    }
}
int main() {
    int T,N,M,a,b,num=0;
    vector<int> vec;
    cin >> T;
    for(int i=0;i<T;i++){
        vector<node*> block;
        cin >> N >> M;
        for(int j=0;j<N;j++){
            node* tmp=new node;
            tmp->find=0;
            block.push_back (tmp);
        }
        for(int j=0;j<M;j++){
            cin >> a >> b;
            block[a]->address.push_back (block[b]);
            block[b]->address.push_back (block[a]);
        }
        for(int j=0;j<N;j++){
            if(block[j]->find==0){
                counting(block[j]);
                num++;
            }
        }
        cout << num << endl;
        num=0;
    }

    return 0;
}