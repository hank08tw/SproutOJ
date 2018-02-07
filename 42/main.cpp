#include <iostream>
using namespace std;
/*
char map[10000+1][10000+1];
void dfs(int x,int y,int max_x,int max_y){
    if(map[y][x]=='.'){
        map[y][x]='#';
    }
    if(x+1<=max_x&&map[y][x+1]=='.'){
        dfs(x+1,y,max_x,max_y);
    }
    if(x-1>=1&&map[y][x-1]=='.'){
        dfs(x-1,y,max_x,max_y);
    }
    if(y+1<=max_y&&map[y+1][x]=='.'){
        dfs(x,y+1,max_x,max_y);
    }
    if(y-1>=1&&map[y-1][x]=='.'){
        dfs(x,y-1,max_x,max_y);
    }
}
int main() {
    int t;
    cin >> t;
    for(int a=0;a<t;a++) {
        int height, width, i, j;
        cin >> height >> width;
        for (i = 1; i <= height; i++) {
            cin >> map[i]+1;
        }

        for (i = 1; i <= height; i++) {
            for (j = 1; j <= width; j++) {
                cout << map[i][j];
            }
            cout << endl;
        }

        int count =0;
        for (i=1;i<=height;i++) {
            for(j=1;j<=width;j++) {
                if (map[i][j] == '.') {
                    dfs ( j,i,width, height);
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
*/

void dfs(int x,int y,char* map,int max_x,int max_y){
    if(map[x+(y-1)*max_x]=='.'){
        map[x+(y-1)*max_x]='#';
    }
    if(x+1<=max_x&&map[x+1+(y-1)*max_x]=='.'){
        dfs(x+1,y,map,max_x,max_y);
    }
    if(x-1>=1&&map[x-1+(y-1)*max_x]=='.'){
        dfs(x-1,y,map,max_x,max_y);
    }
    if(y+1<=max_y&&map[x+(y)*max_x]=='.'){
        dfs(x,y+1,map,max_x,max_y);
    }
    if(y-1>=1&&map[x+(y-2)*max_x]=='.'){
        dfs(x,y-1,map,max_x,max_y);
    }
}
int main() {
    int t;
    cin >> t;
    for(int a=0;a<t;a++) {
        int height, width, i,j;
        cin >> height >> width;
        char* map=new char[height*width+1];
        for (i = 1; i <= height; i++) {
            cin >> (map + (i - 1) * width + 1);
        }
        for (i = 1; i <= height; i++) {
            cout << endl;
            for (j = 1; j <= width; j++) {
                cout << map[(i - 1) * width + j];
            }
            cout << endl;
        }
        int count =0;
        for (i = 1; i <= width * height; i++) {
            if (map[i] == '.') {
                dfs ((i - 1) % width + 1, ((int) (i-1) / 4) + 1, map, width, height);
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}

/*
        for (i = 1; i <= height; i++) {
            cout << endl;
            for (j = 1; j <= width; j++) {
                cout << map[(i - 1) * width + j];
            }
            cout << endl;
        }
*/