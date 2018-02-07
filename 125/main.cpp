#include <iostream>
#include <vector>
using namespace std;
#define NUM 10000019
//int all=0;
struct thedata{
    int val;
    int time;
};
int add(int a,int n){
    if(n==1)return a;
    if(n%2==0){
        int num=add(a,n/2);
        return ((num%NUM)+num)%NUM;
    }
    int num=add(a,(n-1)/2);
    return ((((num%NUM)+num)%NUM)+a)%NUM;
}
void merge(vector<thedata>& data){
    if(data.size ()==1)return;
    int mid=int(data.size ())/2;
    vector<thedata> left(data.begin (),data.begin ()+mid);
    vector<thedata> right(data.begin ()+mid,data.end ());
    merge(left);
    merge(right);
    int l=0;int r=0;
    for(l=0;l<left.size ();l++){
        while(left[l].val>right[r].val&&r<right.size ()){
            right[r].time+=(int)left.size ()-l;
            r++;
        }
        left[l].time+=r;
        //all+=r;
    }
    l=0,r=0;
    for(int i=0;i<data.size ();i++){
        if(r==right.size ()||(r<right.size ()&&l<left.size ()&&left[l].val<=right[r].val)){
            data[i]=left[l++];
        }
        else{data[i]=right[r++];}
    }

}

int main() {
    int N,tmp;
    scanf("%d",&N);
    vector<thedata> data;
    for(int i=0;i<N;i++){
        scanf("%d",&tmp);
        thedata tmpdata;
        tmpdata.val=tmp;
        tmpdata.time=0;
        data.push_back (tmpdata);
    }
    merge(data);
    /*
    for(int i=0;i<data.size ();i++){
        cout << data[i].val << " " << data[i].time << endl;
    }
     */
    int ans=0;
    for(int i=0;i<data.size ();i++){
        if(data[i].time==0)continue;
        ans=(ans+add(data[i].val,data[i].time))%NUM;
    }
    cout << ans << endl;
    //cout << all << endl;
    return 0;
}
/* 只找逆序數對的數量
#include <iostream>
#include <vector>
using namespace std;
int all=0;
void merge(vector<int>& data){
    if(data.size ()==1)return;
    int mid=int(data.size ())/2;
    vector<int> left(data.begin (),data.begin ()+mid);
    vector<int> right(data.begin ()+mid,data.end ());
    merge(left);
    merge(right);
    int l=0,r=0;
    for(l=0;l<left.size ();l++){
        while(left[l]>right[r]&&r<right.size ()){
            r++;
        }
        all+=r;
    }
    l=0,r=0;
    for(int i=0;i<data.size ();i++){
        if(r==right.size ()||(r<right.size ()&&l<left.size ()&&left[l]<=right[r])){
            data[i]=left[l++];
        }
        else{data[i]=right[r++];}
    }
}

int main() {
    int N,tmp;
    //scanf("%d",&N);
    cin >> N;
    vector<int> data;
    for(int i=0;i<N;i++){
        //scanf("%d",&tmp);
        cin >> tmp;
        data.push_back (tmp);
    }
    merge(data);
    for(int i=0;i<data.size ();i++)cout << data[i] << " ";
    cout << all << endl;
    return 0;
}
 */