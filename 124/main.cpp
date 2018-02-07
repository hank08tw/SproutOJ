#include <iostream>
void solve(int N,int X,int Y){
    if(N==1){
        return;
    }
    if(X<=(N/2)&&Y<=(N/2)){
        Report(N/2+1,N/2,N/2+1,N/2+1,N/2,N/2+1);
        solve(N/2,X,Y);
        solve(N/2,N/2+1,N/2);
        solve(N/2,N/2,N/2+1);
        solve(N/2,N/2+1,N/2+1);
    }
    else if(X>(N/2)&&Y<=(N/2)){
        Report(N/2,N/2,N/2+1,N/2+1,N/2,N/2+1);
        solve(N/2,N/2,N/2);
        solve(N/2,X,Y);
        solve(N/2,N/2,N/2+1);
        solve(N/2,N/2+1,N/2+1);
    }
    else if(X<=(N/2)&&Y>(N/2)){
        Report(N/2,N/2,N/2+1,N/2,N/2+1,N/2+1);
        solve(N/2,N/2,N/2);
        solve(N/2,N/2+1,N/2);
        solve(N/2,X,Y);
        solve(N/2,N/2+1,N/2+1);
    }
    else if(X>(N/2)&&Y>(N/2)){
        Report(N/2,N/2,N/2+1,N/2,N/2,N/2+1);
        solve(N/2,N/2,N/2);
        solve(N/2,N/2+1,N/2);
        solve(N/2,N/2,N/2+1);
        solve(N/2,X,Y);
    }
}
