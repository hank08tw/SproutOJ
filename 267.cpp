#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cstring>
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
                return;
        }else{
                if(thenode->m.find(s[cur])!=thenode->m.end()){
			thenode->num+=1;
                        insert(s,cur+1,thenode->m[s[cur]]);
                }else{
			thenode->num+=1;
                        thenode->m[s[cur]]=new node;
                        thenode->m[s[cur]]->num=0;
                        insert(s,cur+1,thenode->m[s[cur]]);
                }
        }
}
int query(const string& s,int cur,node* thenode){
	if(thenode->num==1){
		if(cur==0)return 1;
		else return cur;
	}
	if(cur==s.length())return s.length();
        return query(s,cur+1,thenode->m[s[cur]]);
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
	int t,n,ans;
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> n;
                node* first= new node;
                first->num=0;
                first->m.clear();
		ans=0;
                for(int j=1;j<=n;j++){
                        string tmp;
                        cin >> tmp;
                        insert(tmp,0,first);
			ans+=query(tmp,0,first);
                }
		cout << "Case #" << i << ": " << ans << endl;
		freenode(first);
	}
        return 0;
}
