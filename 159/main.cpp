#include <iostream>
#include <memory.h>
using namespace std;
int main() {
    int t,n,m,c,k,bag;
    cin >> t;
    bool dp[20001];
    int v[1000];
    while(t--){
        bag=0;
        memset(dp,false,sizeof(dp));
        dp[0]=true;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%d %d",&c,&k);
            int tmp=1;
            while(tmp<k){
                k-=tmp;
                v[bag++]=c*tmp;
                tmp*=2;
            }
            if(k>0){
                v[bag++]=k*c;
            }
        }
        for(int i=0;i<bag;i++){
            for(int j=m;j>=v[i];j--){
                dp[j]=dp[j]||dp[j-v[i]];
            }
        }
        if(dp[m]){
            printf("Yes");
        }
        else{
            printf("No");
        }
        printf("\n");
    }
    return 0;
}