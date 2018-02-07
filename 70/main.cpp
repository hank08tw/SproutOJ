#include <iostream>
#include <vector>
#define SWAP(a,b,t) (t=a,a=b,b=t);
using namespace std;
void permuation(vector<int>& array,int flag,int big,vector<int>& thecost){
    int tmp;
    if(flag==big){
        int cost=0;
        while(array.size ()>1){
            cost+=(array[0]+array[1]);
            array[1]+=array[0];
            array.erase(array.begin (),array.begin ()+1);
        }
        thecost.push_back (cost);
    }
    else{
        permuation(array,flag+1,big,thecost);
        for(int i=flag;i<array.size ();i++){
            SWAP(array[i],array[flag-1],tmp);
            permuation (array,flag+1,big,thecost);
            SWAP(array[i],array[flag-1],tmp);
        }
    }
}
int main() {
    int n,input;
    vector<int> array;
    vector<int> cost;
    while(true){
        cin >> n;
        if(n==0){break;}
        for(int i=0;i<n;i++){
            cin >> input;
            array.push_back (input);
        }
        permuation(array,1,(int)array.size (),cost);
        int lowestcost=99999999;
        for(int i=0;i<cost.size ();i++){
            if(cost[i]<lowestcost){
                lowestcost=cost[i];
            }
        }
        cout << lowestcost << endl;
        array.clear ();
        cost.clear ();
    }
    return 0;
}