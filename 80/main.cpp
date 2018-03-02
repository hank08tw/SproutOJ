#include <iostream>
using namespace std;
//單點修改 區間詢問
struct node{
    int l,r;
    int lch,rch;
    int min;
};
int N[1000000];
node tree[2000000];
int contruct(int n,int l,int r){
    tree[n].l=l;
    tree[n].r=r;
    if(l==r-1){
        tree[n].min=N[l];
        return N[l];
    }
    int lch=tree[n].lch=n*2;
    int rch=tree[n].rch=n*2+1;
    int left=contruct(lch,l,(int)(l+r)/2);
    int right=contruct(rch,(int)(l+r)/2,r);
    tree[n].min=min(left,right);
    return tree[n].min;
}
void revise(int tar,int val,int n){
    if(tree[n].l==tree[n].r-1){
        tree[n].min=val;
        return;
    }
    if(tar<(int)(tree[n].l+tree[n].r)/2){
        revise(tar,val,tree[n].lch);
        tree[n].min=min(tree[tree[n].lch].min,tree[tree[n].rch].min);
    }
    else{
        revise(tar,val,tree[n].rch);
        tree[n].min=min(tree[tree[n].lch].min,tree[tree[n].rch].min);
    }

}
int query(int l,int r,int n){
    if(tree[n].l==l&&tree[n].r==r){
        return tree[n].min;
    }
    int mid=(int)((tree[n].l+tree[n].r)/2);
    if(r<=mid){
        return query(l,r,tree[n].lch);
    }
    if(l>=mid){
        return query(l,r,tree[n].rch);
    }
    return min(query(l,mid,tree[n].lch),query(mid,r,tree[n].rch));
}
int main() {
    int t,n,choice,x,y;
    cin >> t >> n;
    for(int i=0;i<n;i++){
        scanf ("%d",&N[i]);
    }
    contruct(1,0,n);
    for(int i=0;i<t;i++){
        scanf("%d %d %d",&choice,&x,&y);
        if(choice==1){
            printf("%d\n",query(x,y+1,1));
        }
        else{
            revise(x,y,1);
        }
    }
    return 0;
}