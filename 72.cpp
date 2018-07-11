#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
typedef long double ld;
//三分搜索o(n*k) n是總共有多少函數 每次要取最大值 k是縮小幾次區間 比較中間左邊跟中間右邊哪個大 不停縮小區間
ld findmax(ld target,ld* a,ld* b,ld* c,int n){
	ld value=-1;
	for(int i=1;i<=n;i++){
		ld tmp=a[i]*(target-b[i])*(target-b[i])+c[i];
		if(tmp>value){
			value=tmp;
		}
	}
	return value;
}
int main(){
	int t,n;
	//ld a,b,c;
	ld arraya[11];
	ld arrayb[11];
	ld arrayc[11];
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> arraya[i] >> arrayb[i] >> arrayc[i];
		}
		long double l=0,r=300;
		while(r-l>0.00000001){
			ld interval=(r-l)/3;
			ld leftmid=findmax(l+interval,arraya,arrayb,arrayc,n);
			ld rightmid=findmax(r-interval,arraya,arrayb,arrayc,n);
			if(leftmid<rightmid){
				r=r-interval;
			}else if(leftmid>rightmid){
				l=l+interval;
			}else{
				r=r-interval;
				l=l+interval;
			}
		}
		cout << fixed << setprecision(5) << findmax((l+r)/2,arraya,arrayb,arrayc,n)<< endl ;
	}
}
