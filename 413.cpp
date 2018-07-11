#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[200005];
int main(){
	int n,k,d;
	//cin >> n >> k >> d;
	scanf("%d %d %d",&n,&k,&d);
	for(int i=0;i<n;i++)scanf("%d", &a[i]);
	sort(a,a+n);
	int ans=1000000000;
	int l=1;
	int r=1000000000;
	while(l<=r){
		int mid=(l+r)/2;
		//bool pos=false;
		int curheight=0;
		int use=0;
		for(int i=0;i<n;i++){
			if(a[i]-curheight>mid){
				break;
			}else{
				if((i+1>=n||a[i+1]-curheight>mid)){curheight=a[i];use+=1;if(use==k)break;}
				else{continue;}
			}
		}
		if(curheight+mid>=d){ans=min(ans,mid);r=mid-1;}
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}
