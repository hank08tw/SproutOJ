#include <iostream>
#include <vector>
#include <string.h>
#define PEOPLE 1000000//100000WA???
using namespace std;
vector<int> sex[PEOPLE];//每個人愛的別人
int color[PEOPLE]={0};//每個人的顏色（二分圖）
bool conflict=false;
void dfs(int num,int cur_color){
    if(conflict){return;}
    color[num]=cur_color;
    for(int i=0;i<sex[num].size ();i++){
        if(color[sex[num][i]]==0){
            if(cur_color==1){
                dfs(sex[num][i],2);
            }
            else{
                dfs(sex[num][i],1);
            }
        }
        else if(cur_color==color[sex[num][i]]){
            conflict=true;
            return;
        }
    }
}
int main() {
    int n,m,a,b;
    while(cin >> n){
        if(n==0){break;}
        cin >> m;
        for(int i=0;i<m;i++){
            cin >> a >> b;
            sex[a].push_back (b);
            sex[b].push_back (a);

        }
        memset (color,0,PEOPLE);
        for(int j=0;j<PEOPLE;j++){
            if(color[j]==0){
                dfs(j,1);
            }
            if(conflict){ break;}
        }
        if(conflict){
            cout << "RAINBOW." << endl;
            conflict=false;
        }
        else {
            cout << "NORMAL." << endl;
        }
        for(int i=0;i<PEOPLE;i++){
            sex[i].clear ();
        }
    }
    return 0;
}