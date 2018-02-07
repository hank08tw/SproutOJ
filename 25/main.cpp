#include <iostream>
#include <vector>
//this is a queue data
using namespace std;
struct node{
    int data;
    node* forward;
    node* backward;
};
int main() {
    int M,N;//有N個店家，M筆資料
    string choice;
    int n,id;
    cin >> N >> M;
    vector<node*> queue,last;
    for(int i=0;i<N;i++){
        queue.push_back (nullptr);
        last.push_back (nullptr);
    }
    for(int i=0;i<M;i++){
        cin >> choice;
        if(choice=="ADD"){
            cin >> n >> id;
            if(queue[n-1]== nullptr){
                queue[n-1]=new node;
                queue[n-1]->data=id;
                queue[n-1]->forward= nullptr;
                queue[n-1]->backward= nullptr;
                last[n-1]=queue[n-1];
            }
            else{
                node* tmp= last[n-1];
                last[n-1]->backward=new node;
                last[n-1]->backward->data=id;
                last[n-1]=last[n-1]->backward;
                last[n-1]->backward= nullptr;
                last[n-1]->forward=tmp;
                if(queue[n-1]->backward== nullptr){
                    queue[n-1]->backward= last[n-1];
                }
            }
        }
        else if(choice=="LEAVE"){
            cin >> n;
            if(queue[n-1]== nullptr){
                cout << "queue " << n << " is empty!" << endl;
            }
            else if(queue[n-1]->backward== nullptr){
                queue[n-1]=nullptr;
                last[n-1]= nullptr;
            }
            else{
                /*
                if(last[n-1]->forward==queue[n-1]){
                    queue[n-1]->backward= nullptr;
                }
                last[n-1]=last[n-1]->forward;
                last[n-1]->backward= nullptr;
                */
                queue[n-1]=queue[n-1]->backward;
                queue[n-1]->forward= nullptr;
            }
        }
        else if(choice=="JOIN"){
            int before, after;
            cin >> before >> after;
            if(queue[before-1]!= nullptr){
                if(last[after-1]!=nullptr){
                    last[after-1]->backward=queue[before-1];
                    queue[before-1]->forward=last[after-1];
                }
                else{
                    queue[after-1]=queue[before-1];
                }
                last[after-1]=last[before-1];
                queue[before-1]= nullptr;
                last[before-1]= nullptr;
            }
        }
    }
    for(int i=0;i<N;i++){
        if(queue[i]== nullptr){
            cout << "queue " << i+1 << ": empty" << endl;
        }
        else{
            cout << "queue " << i+1 << ": ";
            while(queue[i]->backward!= nullptr){
                cout << queue[i]->data << " ";
                queue[i]=queue[i]->backward;
            }
            cout << queue[i]->data << endl;
        }
    }
    return 0;
}
