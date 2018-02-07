#include <iostream>
//#include <stdio.h>
//#include <cstring>
//#include <cstdlib>
#include <vector>
//#include <ctime>
using namespace std;

const int MAX_N = 100003;

vector<int> edg[MAX_N];

struct Node {
    int val;
    int sum;
    int max;
} node[MAX_N];

bool visit[MAX_N];

int dfs(int id) {
    visit[id]=true;
    int len=edg[id].size();
    for (int x=0;len>x;x++) {
        int tmp=edg[id][x];
        if (visit[tmp]==true) ;  //回到父親
        else {
            int t=dfs(tmp);
            node[id].sum+=t;
            node[id].max = max(node[id].max,t);
        }
    }
    return node[id].sum+1;
}

int main () {
    srand(time(NULL));
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        //init
        for (int x=0;n>x;x++) {
            edg[x].clear();
            node[x].sum=node[x].max = 0;
            node[x].val = x;
            visit[x]=false;
        }
        for (int x=0;n-1>x;x++) {
            int a,b;
            scanf("%d %d",&a,&b);
            edg[a].push_back(b);
            edg[b].push_back(a);
        }
        int id = rand() % n;
        dfs(id);
        int ans=n;
        for (int x=0;n>x;x++) {
            int tmp=max(node[x].max,n-node[x].sum-1);
            ans=min(ans,tmp);
        }
        for (int x=0;n>x;x++) {
            int tmp=max(node[x].max,n-node[x].sum-1);
            if (tmp==ans) {
                printf("%d\n",x);
                break;
            }
        }

    }
}
/*
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
struct node{
    //int value;//0,1,2,3...
    int max;//最大子樹節點值
    int sum;//所以子樹節點總和值
    bool visit;
    vector<node*> side;
};
int dfs(node* thenode){
    thenode->visit=true;
    for(int i=0;i<thenode->side.size ();i++){
        if(thenode->side[i]->visit==false){
            int t=dfs(thenode->side[i]);
            thenode->sum+=t;
            thenode->max=max(thenode->max,t);
        }
    }
    return thenode->sum+1;
}
int main() {
    int num,a,b,T;
    cin >> T;
    for(int t=0;t<T;t++){
        cin >> num;
        vector<node*> thenode;
        for(int i=0;i<num;i++){
            node* tmp=new node;
            tmp->sum=0;
            tmp->max=0;
            tmp->visit=false;
            thenode.push_back (tmp);
        }
        for(int i=0;i<num-1;i++){
            cin >> a >> b;
            thenode[a]->side.push_back (thenode[b]);
            thenode[b]->side.push_back (thenode[a]);
        }
        //const int start=num/2;
        dfs(thenode[0]);
        int smallest_node=num;int tmpi;
        for(int i=0;i<num;i++){
            int tmp=max(thenode[i]->max,num-thenode[i]->sum-1);
            if(tmp<smallest_node){
                tmpi=i;
                smallest_node=tmp;
            }
            else if(tmp==smallest_node&&i<tmpi){
                tmpi=i;
            }
            //cout << tmp << endl;
        }
        cout << tmpi << endl;
    }
    return 0;
}
*/