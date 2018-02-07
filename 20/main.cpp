#include <cstdio>
#include <iostream>
#include <vector>
#define GROUPNUM 1001
#define PEOPLENUM 1000000
using namespace std;
struct node{
    int val;
    node* next;
};
int main() {
    int groupnum,T=1;
    node* tail;//排隊的尾端
    node* queue;//排隊
    node* lastpeople_pos[GROUPNUM];//各個group裡最後一個成員queue裡的位置
    while(scanf("%d",&groupnum)!=EOF){
        cout << "Line #" << T++ << endl;
        int people[PEOPLENUM]={0};//這個人在那個group
        queue= nullptr;
        tail=nullptr;
        for(int i=1;i<GROUPNUM;i++){
            lastpeople_pos[i]=nullptr;
        }
        int n,t;
        for(int i=1;i<=groupnum;i++){
            scanf("%d",&n);
            for(int j=1;j<=n;j++){
                scanf("%d",&t);
                people[t]=i;
            }
        }
        string choice;
        while(cin >> choice){
            if(choice=="ENQUEUE"){
                //cout << 'cool';
                scanf(" %d",&t);

                node* tmp=new node;
                tmp->val=t;
                tmp->next=nullptr;
                if(people[t]!=0&&lastpeople_pos[people[t]]==nullptr){
                    if(queue!=nullptr){
                        tail->next=tmp;
                        tail=tail->next;
                    }
                    else{
                        queue=tmp;
                        tail=tmp;
                    }
                    lastpeople_pos[people[t]]=tail;
                }
                else if(people[t]!=0&&lastpeople_pos[people[t]]!=nullptr){
                    node* tmp2=lastpeople_pos[people[t]]->next;
                    lastpeople_pos[people[t]]->next=tmp;
                    tmp->next=tmp2;
                    lastpeople_pos[people[t]]=tmp;
                    if(tmp2==nullptr){
                        tail=tmp;
                    }
                }
                else{
                    if(queue!= nullptr){
                        tail->next=tmp;
                        tail=tail->next;
                    }
                    else{
                        queue=tmp;
                        tail=tmp;
                    }
                }
            }
            else if(choice=="DEQUEUE"){
                if(queue->next==nullptr){
                    lastpeople_pos[people[queue->val]]= nullptr;
                    cout << queue->val << endl;
                    delete(queue);
                    queue=nullptr;

                }
                else{
                    if(people[queue->val]!=0&&queue==lastpeople_pos[people[queue->val]]){
                        lastpeople_pos[people[queue->val]]= nullptr;
                    }
                    node* tmp2=queue;
                    cout << queue->val << endl;
                    queue=queue->next;
                    delete(tmp2);
                }
            }
            else if(choice=="STOP"){
                break;
            }
            /*
            node* printout=queue;
            cout << "print:";
            while(printout!= nullptr){
                cout << printout->val << " ";
                printout=printout->next;
            }
            cout<< endl;
            */
        }
    }
    return 0;
}
/*
#include <iostream>
#include <vector>
#define GROUPNUM 1001
#define PEOPLENUM 1000000
using namespace std;
int main() {
    int groupnum,pop_pos=0,T=1;
    vector<int> group[GROUPNUM];//各個group裡的成員編號
    vector<int> queue;//排隊
    int lastpeople_pos[GROUPNUM];//各個group裡最後一個成員queue裡的位置
    while(cin >> groupnum){
        cout << "Line #" << T++ << endl;
        int people[PEOPLENUM]={0};//這個人在那個group
        queue.clear ();
        pop_pos=0;
        for(int i=1;i<GROUPNUM;i++){
            lastpeople_pos[i]=-1;
            group[i].clear ();
        }
        int n,t;
        for(int i=1;i<=groupnum;i++){
            cin >> n;
            for(int j=1;j<=n;j++){
                cin >> t;
                group[i].push_back (t);
                people[t]=i;
            }
        }
        string choice;
        while(cin >> choice){
            if(choice=="STOP"){
                break;
            }
            if(choice=="ENQUEUE"){
                cin >> t;
                if(people[t]!=0&&lastpeople_pos[people[t]]==-1){
                    lastpeople_pos[people[t]]=(int)queue.size ();
                    queue.push_back (t);
                }
                else if(people[t]!=0&&lastpeople_pos[people[t]]!=-1){
                    lastpeople_pos[people[t]]+=1;
                    queue.insert (queue.begin ()+lastpeople_pos[people[t]],t);
                    for(int i=1;i<=GROUPNUM;i++){
                        if(lastpeople_pos[i]>=lastpeople_pos[people[t]]&&lastpeople_pos[i]!=-1&&i!=people[t]){
                            lastpeople_pos[i]++;
                        }
                    }
                }
                else{
                    queue.push_back (t);
                }
            }
            else if(choice=="DEQUEUE"){
                if(people[queue[pop_pos]]!=0&&pop_pos==lastpeople_pos[people[queue[pop_pos]]]){
                    lastpeople_pos[people[queue[pop_pos]]]=-1;
                }
                cout << queue[pop_pos] << endl;
                pop_pos++;
            }
        }
    }
    return 0;
}
 */