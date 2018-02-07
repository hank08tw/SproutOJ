#include <iostream>
#include <vector>
#define NUM 9
using namespace std;
char sudo[NUM][NUM]={'.'};
struct node{
    int x;
    int y;
};
vector<node> data;
bool wintmp=false;
bool losetmp=false;
bool ending=false;
void printout(){
    for(int j=0;j<NUM;j++){
        for(int i=0;i<NUM;i++){
            cout << sudo[j][i];
        }
    }
    cout << endl;
}
void win(){
    printout();
    wintmp=true;
}
void lose() {
    cout << "No solution." << endl;
}
void checklr(int j,bool* flag){
    int count[9]={0};
    for(int i=0;i<9;i++){
        if(sudo[j][i]!='.'){
            count[((int)(sudo[j][i]-48))-1]++;
            if(count[(sudo[j][i]-48)-1]>1){
                *flag=true;
                return;
            }
        }
    }
}
void checkud(int i,bool* flag){
    int count[9]={0};
    for(int j=0;j<9;j++){
        if(sudo[j][i]!='.'){
            count[(int)(sudo[j][i]-48)-1]++;
            if(count[(sudo[j][i]-48)-1]>1){
                *flag=true;
                return;
            }
        }
    }
}
void checksquare(int i,int j,bool* flag){
    int count[9]={0};
    if(i<3&&j<3){
        for(int b=0;b<3;b++){
            for(int a=0;a<3;a++){
                if(sudo[b][a]!='.'){
                    count[(int)(sudo[b][a]-48)-1]++;
                    if(count[(sudo[b][a]-48)-1]>1){
                        *flag=true;
                        return;
                    }
                }
            }
        }
    }
    else if(i>=3&&i<=5&&j<3){
        for(int b=0;b<3;b++){
            for(int a=3;a<6;a++){
                if(sudo[b][a]!='.'){
                    count[(int)(sudo[b][a]-48)-1]++;
                    if(count[(sudo[b][a]-48)-1]>1){
                        *flag=true;
                        return;
                    }
                }
            }
        }
    }
    else if(i>5&&j<3){
        for(int b=0;b<3;b++){
            for(int a=6;a<9;a++){
                if(sudo[b][a]!='.'){
                    count[(int)(sudo[b][a]-48)-1]++;
                    if(count[(sudo[b][a]-48)-1]>1){
                        *flag=true;
                        return;
                    }
                }
            }
        }
    }
    else if(i<3&&j>=3&&j<=5){
        for(int b=3;b<6;b++){
            for(int a=0;a<3;a++){
                if(sudo[b][a]!='.'){
                    count[(int)(sudo[b][a]-48)-1]++;
                    if(count[(sudo[b][a]-48)-1]>1){
                        *flag=true;
                        return;
                    }
                }
            }
        }
    }
    else if(i>=3&&i<=5&&j>=3&&j<=5){
        for(int b=3;b<6;b++){
            for(int a=3;a<6;a++){
                if(sudo[b][a]!='.'){
                    count[(int)(sudo[b][a]-48)-1]++;
                    if(count[(sudo[b][a]-48)-1]>1){
                        *flag=true;
                        return;
                    }
                }
            }
        }
    }
    else if(i>5&&j>=3&&j<=5){
        for(int b=3;b<6;b++){
            for(int a=6;a<9;a++){
                if(sudo[b][a]!='.'){
                    count[(int)(sudo[b][a]-48)-1]++;
                    if(count[(sudo[b][a]-48)-1]>1){
                        *flag=true;
                        return;
                    }
                }
            }
        }
    }
    else if(i<3&&j>5){
        for(int b=6;b<9;b++){
            for(int a=0;a<3;a++){
                if(sudo[b][a]!='.'){
                    count[(int)(sudo[b][a]-48)-1]++;
                    if(count[(sudo[b][a]-48)-1]>1){
                        *flag=true;
                        return;
                    }
                }
            }
        }
    }
    else if(i>=3&&i<=5&&j>5){
        for(int b=6;b<9;b++){
            for(int a=3;a<6;a++){
                if(sudo[b][a]!='.'){
                    count[(int)(sudo[b][a]-48)-1]++;
                    if(count[(sudo[b][a]-48)-1]>1){
                        *flag=true;
                        return;
                    }
                }
            }
        }
    }
    else if(i>5&&j>5){
        for(int b=6;b<9;b++){
            for(int a=6;a<9;a++){
                if(sudo[b][a]!='.'){
                    count[(int)(sudo[b][a]-48)-1]++;
                    if(count[(sudo[b][a]-48)-1]>1){
                        *flag=true;
                        return;
                    }
                }
            }
        }
    }
}
void dfs(int depth){
    if(depth==data.size()){
        win();
        return;
    }
    for(int i=1;i<=9;i++){
        bool flag=false;//0代表沒衝突1代表衝突
        sudo[data[depth].y][data[depth].x]=(char)(i+48);
        checklr (data[depth].y,&flag);
        if(flag){ if(i==9){sudo[data[depth].y][data[depth].x]='.';}continue; }
        checkud (data[depth].x,&flag);
        if(flag){if(i==9){sudo[data[depth].y][data[depth].x]='.';}continue;}
        checksquare (data[depth].x,data[depth].y,&flag);
        if(flag){if(i==9){sudo[data[depth].y][data[depth].x]='.';}continue;}
        dfs(depth+1);
    }
}
int main() {//int=1 char=49;
    while(true){
        for(int j=0;j<NUM;j++){
            if(ending||losetmp){break;}
            for(int i=0;i<NUM;i++){
                cin >> sudo[j][i];
                if(sudo[j][i]=='.'){
                    node tmp;
                    tmp.x=i;
                    tmp.y=j;
                    data.push_back (tmp);
                }
                if(sudo[0][0]=='e'&&sudo[0][1]=='n'&&sudo[0][2]=='d'){
                    ending=true;
                    break;
                }
            }
        }
        if(ending){
            break;
        }
        dfs(0);
        if(!wintmp){
            lose();
        }
        data.clear ();
        wintmp=false;
        losetmp=false;
    }
    return 0;
}