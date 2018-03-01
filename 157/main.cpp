#include <iostream>
//dp解法 時間:o(物品數乘上總滿足感總和)  空間:o(滿足感總和)
using namespace std;
int w[100];
int v[100];
int dp[10001];
int main() {
    int t,n,m;
    cin >> t;
    while(t--){
        scanf("%d %d",&n,&m);
        int vsum=0;
        int wsum=0;
        for(int i=0;i<n;i++){
            scanf("%d %d",&w[i],&v[i]);
            vsum+=v[i];
            wsum+=w[i];
        }
        for(int i=1;i<=vsum;i++){
            dp[i]=1000001;
        }
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=vsum;j>=v[i];j--){
                dp[j] = min (dp[j], dp[j - v[i]]+w[i]);
            }
        }
        int v=0;
        for(int i=1;i<=vsum;i++){
            if(dp[i]<=m){
                v=i;
            }
        }
        printf ("%d\n",v);
    }
    return 0;
}