#include <iostream>
using namespace std;
int main(){
	int a,b,c,d,e,f;
	while(cin >> a >> b >> c >> d >> e >>f){
		if(a==0&&b==0&&c==0&&d==0&&e==0&&f==0)break;
		int ans=0;
		ans+=f;
		ans+=e;
		a=max(0,a-11*e);
		ans+=d;
		if(b>=5*d){
			b-=5*d;
		}else{
			a=max(0,a-4*(5*d-b));
			b=0;
		}
		ans+=(c/4);
		c%=4;
		if(c>0)ans++;
		switch(c){
			case 0:break;
			case 1:
				if(b>=5){
                        		b-=5;
					a=max(0,a-7);
                		}else{  
                        		a=max(0,a-7-(4*(5-b)));
                        		b=0;
                		}
				break;
			case 2:
				if(b>=3){
                                        b-=3;
                                        a=max(0,a-6);
                                }else{
                                        a=max(0,a-6-(4*(3-b)));
                                        b=0;
                                }
                                break;
			case 3:
				if(b>=1){
                                        b-=1;
                                        a=max(0,a-5);
                                }else{
                                        a=max(0,a-5-(4*(1-b)));
                                        b=0;
                                }break;
		}
		//
		ans+=(b/9);
		b%=9;
		if(b>0){
			a=max(0,a-(36-4*b));
			ans++;
		}
		ans+=(a/36);
		a%=36;
		if(a>0)ans++;
		cout << ans << endl;
	}
}
