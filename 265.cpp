#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
using namespace std;
int main(){
	string small,big;
	cin >> small;
	cin >> big;
	int f[500001];
	int ans[500001];
	int count=0;
	f[1]=0;
	int cur=0;
	for(int i=2;i<=small.length();i++){
		if(small[cur]==small[i-1]){
			cur++;
			f[i]=cur;
		}else{
			if(cur==0){
				f[i]=0;
				continue;
			}else{
				cur=f[cur];
				i--;
			}
		}
	}
	cur=0;
	for(int i=1;i<=big.length();i++){
		if(small[cur]==big[i-1]){
			cur++;
		}else{
			if(cur==0){continue;}
			cur=f[cur];
			i--;
		}
		if(cur==small.size()){
			ans[count++]=i-small.size();
			//cout << i-small.size() << " ";
		}
	}
	for(int i=0;i<count-1;i++){
		cout << ans[i] << " ";
	}
	if(count>0)cout << ans[count-1];
	cout << endl;//must have endl!!!
}
