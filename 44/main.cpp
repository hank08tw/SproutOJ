#include <iostream>
#include <vector>
using namespace std;
char map[100+2][100+2];
int dist[100+1][100+1];
struct block{
    int x,y;
    block(int x,int y){
        this->x=x;
        this->y=y;
    }
};
int main() {
    int num;
    vector<block> queue;
    while(true){
        queue.clear ();
        cin >> num;
        if(num==0){
            break;
        }
        for(int i=1;i<=num;i++){
            for(int j=1;j<=100;j++){
                dist[i][j]=9999;
            }
        }
        for(int i=0;i<=num+1;i++){
            for(int j=0;j<=101;j++){
                map[i][j]='#';
            }
        }
        for(int i=1;i<=num;i++){
            cin >> map[i]+1;
            for(int j=1;j<=100;j++){
                if(map[i][j]=='K'){
                    block tmp(j,i);
                    queue.push_back (tmp);
                    dist[i][j]=0;
                }
            }
        }

        while(true){
            int findrat=0;
            int nopath=1;
            int size=queue.size ();
            for(int i=1;i<=size;i++){
                int tmpx=queue[i-1].x,tmpy=queue[i-1].y,tmplevel=dist[tmpy][tmpx];
                if(map[tmpy][tmpx]=='@'){
                    cout << dist[tmpy][tmpx] << endl;
                    findrat=1;
                    break;
                }
                if(map[tmpy][tmpx+1]!='#'&&dist[tmpy][tmpx+1]>tmplevel+1){
                    dist[tmpy][tmpx+1]=tmplevel+1;
                    block tmp(tmpx+1,tmpy);
                    queue.push_back (tmp);
                    nopath=0;
                }
                if(map[tmpy-1][tmpx]!='#'&&dist[tmpy-1][tmpx]>tmplevel+1){
                    dist[tmpy-1][tmpx]=tmplevel+1;
                    block tmp(tmpx,tmpy-1);
                    queue.push_back (tmp);
                    nopath=0;
                }
                if(map[tmpy][tmpx-1]!='#'&&dist[tmpy][tmpx-1]>tmplevel+1){
                    dist[tmpy][tmpx-1]=tmplevel+1;
                    block tmp(tmpx-1,tmpy);
                    queue.push_back (tmp);
                    nopath=0;
                }
                if(map[tmpy+1][tmpx]!='#'&&dist[tmpy+1][tmpx]>tmplevel+1){
                    dist[tmpy+1][tmpx]=tmplevel+1;
                    block tmp(tmpx,tmpy+1);
                    queue.push_back (tmp);
                    nopath=0;
                }
            }
            if(findrat==1){
                break;
            }
            else if(nopath==1){
                cout << "= =\"" << endl;
                break;
            }
        }
    }
    return 0;
}