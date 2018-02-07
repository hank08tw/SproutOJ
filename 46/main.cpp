#include <iostream>
#include <vector>
#define LENGTH 1000
using namespace std;
char map[LENGTH][LENGTH]={'0'};
struct point{
    char color;
    int x,y;
};
vector<point> data;
int Y=1,B=1,R=1,O=0,G=0,P=0,D=0;
int BY=1,BB=1,BR=1,BO=0,BG=0,BP=0,BD=0;
void print(char c){
    switch (c){
        case 'Y':cout << BY;
            break;
        case 'B':cout << BB;
            break;
        case 'R':cout << BR;
            break;
        case 'O':cout << BO;
            break;
        case 'G':cout << BG;
            break;
        case 'P':cout << BP;
            break;
        case 'D':cout << BD;
            break;
        default:
            break;
    }
    cout << endl;
}
void compare(){
    if(BY<Y){
        BY=Y;
    }
    if(BB<B){
        BB=B;
    }
    if(BR<R){
        BR=R;
    }
    if(BO<O){
        BO=O;
    }
    if(BG<G){
        BG=G;
    }
    if(BP<P){
        BP=P;
    }
    if(BD<D){
        BD=D;
    }
}
void bfs(char color,int x,int y,int N){
    if(x<0||x>=N||y<0||y>=N){
        return;
    }
    switch(color){
        case 'R':
            if(map[y][x]=='R'||map[y][x]=='O'||map[y][x]=='D'||map[y][x]=='P'){
                return;
            }
            else{
                point tmp;
                tmp.color='R';
                tmp.x=x;
                tmp.y=y;
                if(map[y][x]=='0'){
                    map[y][x]='R';
                    R++;
                }
                else if(map[y][x]=='Y'){
                    map[y][x]='O';
                    Y--;O++;
                }
                else if(map[y][x]=='G'){
                    map[y][x]='D';
                    D++;G--;
                }
                else if(map[y][x]=='B'){
                    map[y][x]='P';
                    B--;P++;
                }
                data.push_back (tmp);
            }
            break;
        case 'Y':
            if(map[y][x]=='Y'||map[y][x]=='O'||map[y][x]=='D'||map[y][x]=='G'){
                return;
            }
            else{
                point tmp;
                tmp.color='Y';
                tmp.x=x;
                tmp.y=y;
                if(map[y][x]=='0'){
                    map[y][x]='Y';
                    Y++;
                }
                else if(map[y][x]=='R'){
                    map[y][x]='O';
                    R--;O++;
                }
                else if(map[y][x]=='P'){
                    map[y][x]='D';
                    D++;P--;
                }
                else if(map[y][x]=='B'){
                    map[y][x]='G';
                    B--;G++;
                }
                data.push_back (tmp);
            }
            break;
        case 'B':
            if(map[y][x]=='B'||map[y][x]=='P'||map[y][x]=='D'||map[y][x]=='G'){
                return;
            }
            else{
                point tmp;
                tmp.color='B';
                tmp.x=x;
                tmp.y=y;
                if(map[y][x]=='0'){
                    map[y][x]='B';
                    B++;
                }
                else if(map[y][x]=='R'){
                    map[y][x]='P';
                    R--;P++;
                }
                else if(map[y][x]=='O'){
                    map[y][x]='D';
                    D++;O--;
                }
                else if(map[y][x]=='Y'){
                    map[y][x]='G';
                    Y--;G++;
                }
                data.push_back (tmp);
            }
            break;
        default:
            break;
    }
}
int main() {
    int T,N,x,y;
    char c;
    cin >> T;
    for(int i=0;i<T;i++){
        Y=1,B=1,R=1,O=0,G=0,P=0,D=0;
        BY=1,BB=1,BR=1,BO=0,BG=0,BP=0,BD=0;
        data.clear();
        cin >> N;
        for(int a=0;a<N;a++){
            for(int b=0;b<N;b++){
                map[a][b]='0';
            }
        }
        for(int j=0;j<3;j++){
            cin >> c >> x >> y;
            point tmp;
            tmp.color=c;
            tmp.x=x;
            tmp.y=y;
            map[y][x]=c;
            data.push_back (tmp);
        }
        while(!data.empty ()){
            int size=(int)data.size ();
            for(int j=0;j<size;j++){
                bfs (data[j].color,data[j].x+1,data[j].y,N);
                bfs (data[j].color,data[j].x+1,data[j].y+1,N);
                bfs (data[j].color,data[j].x,data[j].y+1,N);
                bfs (data[j].color,data[j].x-1,data[j].y+1,N);
                bfs (data[j].color,data[j].x-1,data[j].y,N);
                bfs (data[j].color,data[j].x-1,data[j].y-1,N);
                bfs (data[j].color,data[j].x,data[j].y-1,N);
                bfs (data[j].color,data[j].x+1,data[j].y-1,N);
            }
            compare();
            //cout << Y << " " << B << " " << R << " " <<  " " << P << " " << O << " " << G << " " << D << endl;
            data.erase(data.begin (),data.begin ()+size);
        }
        cin >> c;
        print(c);
    }
    return 0;
}