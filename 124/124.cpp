//
// Created by 詹士翰 on 2018/1/1.
//
void recursion(int X,int Y,int l,int r,int u,int d){
    if(l==r){
        return;
    }
    if(X<=(l+r)/2&&Y<=(u+d)/2){
        Report((l+r)/2+1,(u+d)/2,(l+r)/2,(u+d)/2+1,(l+r)/2+1,(u+d)/2+1);
        recursion(X,Y,l,(l+r)/2,u,(u+d)/2);
        recursion((l+r)/2+1,(u+d)/2,(l+r)/2+1,r,u,(u+d)/2);
        recursion((l+r)/2,(u+d)/2+1,l,(l+r)/2,(u+d)/2+1,d);
        recursion((l+r)/2+1,(u+d)/2+1,(l+r)/2+1,r,(u+d)/2+1,d);
    }
    else if(X>(l+r)/2&&Y<=(u+d)/2){
        Report((l+r)/2,(u+d)/2,(l+r)/2,(u+d)/2+1,(l+r)/2+1,(u+d)/2+1);
        recursion((l+r)/2,(u+d)/2,l,(l+r)/2,u,(u+d)/2);
        recursion(X,Y,(l+r)/2+1,r,u,(u+d)/2);
        recursion((l+r)/2,(u+d)/2+1,l,(l+r)/2,(u+d)/2+1,d);
        recursion((l+r)/2+1,(u+d)/2+1,(l+r)/2+1,r,(u+d)/2+1,d);
    }
    else if(X<=(l+r)/2&&Y>(u+d)/2){
        Report((l+r)/2,(u+d)/2,(l+r)/2+1,(u+d)/2,(l+r)/2+1,(u+d)/2+1);
        recursion((l+r)/2,(u+d)/2,l,(l+r)/2,u,(u+d)/2);
        recursion((l+r)/2+1,(u+d)/2,(l+r)/2+1,r,u,(u+d)/2);
        recursion(X,Y,l,(l+r)/2,(u+d)/2+1,d);
        recursion((l+r)/2+1,(u+d)/2+1,(l+r)/2+1,r,(u+d)/2+1,d);
    }
    else if(X>(l+r)/2&&Y>(u+d)/2){
        Report((l+r)/2,(u+d)/2,(l+r)/2,(u+d)/2+1,(l+r)/2+1,(u+d)/2+1);
        recursion((l+r)/2,(u+d)/2,l,(l+r)/2,u,(u+d)/2);
        recursion((l+r)/2+1,(u+d)/2,(l+r)/2+1,r,u,(u+d)/2);
        recursion((l+r)/2,(u+d)/2+1,l,(l+r)/2,(u+d)/2+1,d);
        recursion(X,Y,(l+r)/2+1,r,(u+d)/2+1,d);
    }
}
void solve(int N,int X,int Y){
    recursion(X,Y,1,N,1,N);
}


