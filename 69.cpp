#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//time:o(NlogNlogC)C=100000001
template <typename T>
void merge(vector<T>& v){
	if(v.size()==1)return;
	int mid=v.size()/2;
	vector<T> left(v.begin(),v.begin()+mid);
	vector<T> right(v.begin()+mid,v.end());
	merge(left);
	merge(right);
	int i=0;
	int j=0;
	for(int k=0;k<v.size();k++){
		if(j==right.size()||(i<left.size()&&left[i]<right[j])){
			v[k]=left[i++];
		}
		else{
			v[k]=right[j++];
		}
	}
}
template <typename T>
bool check(long long m,vector<T>& a,vector<T>& b,vector<T>& c,int n,int k){//m一定要開long long
	vector<unsigned long long> you;
	for(int i=0;i<n;i++){
		you.push_back(a[i]+b[i]*m);
	}
	merge(you);
	merge(c);
	int pos=0;
	int j=n-1;
	for(int i=n-1;i>=0;i--){
		while(j>-1&&you[i]<=c[j]){
			j--;
		}
		if(j<0)break;
		if(you[i]>c[j]){pos++;j--;}
	}
	if(pos>=k)return true;
	return false;
}
int main(){
	int t,n,k;
	vector<int> a;
	vector<int> b;
	vector<int> c;
	scanf("%d",&t);
	while(t--){
		a.clear();
		b.clear();
		c.clear();
		scanf("%d %d",&n,&k);
		int ta,tb,tc;
		for(int i=0;i<n;i++){
			scanf("%d %d",&ta,&tb);
			a.push_back(ta);
			b.push_back(tb);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&tc);
			c.push_back(tc);
		}
		//如果有答案的情況下 經過100000000天的訓練一定能贏k場
		if(!check(100000001,a,b,c,n,k)){cout << "-1" << endl;continue;}
		if(check(0,a,b,c,n,k)){cout << "0" << endl;continue;}
		int ans=100000001;
		int l=1,r=100000000;
		while(r-l>=0){
			int mid=(r-l)/2;
			if(check(r-mid,a,b,c,n,k)){
				ans=min(ans,r-mid);
				r=r-mid-1;
				//cout << "cool " << ans << endl;
			}else{
				l=l+mid+1;
			}
			//cout << "l: " << l << "r: " << r << endl;
		}
		printf("%d\n",ans);
	}
}
