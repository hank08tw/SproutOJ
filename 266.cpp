#include <iostream>
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <cstdio>
#include <unordered_map>
using namespace std;
int c;
struct node{
        int num;
        unordered_map <char,node*> m;
};
void insert(const string& s,int cur,node* thenode){
        if(cur==s.length()){
		thenode->num+=1;
        }else{
                if(thenode->m.find(s[cur])!=thenode->m.end()){
                        insert(s,cur+1,thenode->m[s[cur]]);
                }else{
                        thenode->m[s[cur]]=new node;
                        thenode->m[s[cur]]->num=0;
                        insert(s,cur+1,thenode->m[s[cur]]);
                }
        }
}
void query(const string& s,int cur,node* thenode){
	if(cur==s.length()){
                cout << thenode->num << '\n';
        }else{
                if(thenode->m.find(s[cur])!=thenode->m.end()){
                        query(s,cur+1,thenode->m[s[cur]]);
                }else{
			cout << "0\n"; 
                }
        }

}
void freenode(node* thenode){
        unordered_map <char,node*>::iterator it;
        for(it=thenode->m.begin();it!=thenode->m.end();it++){
                freenode((*it).second);
        }
        thenode->m.clear();
        delete thenode;
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int n,m;
	cin >> n >> m;
          	node* first= new node;
                first->num=0;
                first->m.clear();
                for(int i=0;i<n;i++){
                        string tmp;
                        cin >> tmp;
                        insert(tmp,0,first);
                }
		for(int i=0;i<m;i++){
			string tmp;
			cin >> tmp;
			query(tmp,0,first);
		}
                //freenode(first);
        return 0;
}
