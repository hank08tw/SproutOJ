#include <iostream>
#include <vector>
using namespace std;
int stack[6];
void dfs(int depth,int last,const vector<int>& lucky){
    if(depth==6){
        for(int i=0;i<6;i++)
            cout << stack[i] << (i==5 ? '\n' : ' ');
    }
    else{
        for(int i=last+1;i<lucky.size();i++){
            stack[depth]=lucky[i];
            dfs(depth+1,i,lucky);
        }
    }
}
int main() {
    vector<int> lucky;
    bool flag=false;
    while(true){
        int k;
        cin >> k;
        if(k==0){
            break;
        }
        if(flag){
            cout << endl;
        }
        else{
            flag=true;
        }
        for(int i=0;i<k;i++){
            int tmp;
            cin >> tmp;
            lucky.push_back(tmp);
        }
        dfs(0,-1,lucky);
        lucky.clear();
    }
    return 0;
}
