#include <iostream>
using namespace std;
int size=0;//現在minheap的大小
long long ans=0;//return的答案
int cur=-1;//pop掉元素中的最大值
bool inqueue[110][110]={false};//紀錄現在哪些位置在queue裡
int count=0;//所有曾經進入minheap的數量
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
struct pos{
    int x;
    int y;
    int h;
}minheap[109*109+1];
void insert(int x,int y,int h){
    pos tmp;
    tmp.x=x;
    tmp.y=y;
    tmp.h=h;
    minheap[++size]=tmp;
    int id=size;
    while(id>1&&minheap[id].h<minheap[id/2].h){
        pos ch;
        ch=minheap[id];
        minheap[id]=minheap[id/2];
        minheap[id/2]=ch;
        id/=2;
    }
}
pos deque(){
    pos ch;
    ch=minheap[size];
    minheap[size]=minheap[1];
    minheap[1]=ch;
    size--;
    int id=1;
    while(true){
        int lr=0;//0代表左邊的child比較小或一樣大 1代表右邊的child比較小
        if(id*2<size){
            if(minheap[id*2].h>minheap[id*2+1].h){
                lr=1;
            }
            if(minheap[id].h>minheap[id*2+lr].h){
                pos ch2;
                ch=minheap[id*2+lr];
                minheap[id*2+lr]=minheap[id];
                minheap[id]=ch;
            }
            else{break;}
        }
        else if(id*2==size){
            if(minheap[id].h>minheap[id*2].h){
                pos ch2;
                ch=minheap[id*2];
                minheap[id*2]=minheap[id];
                minheap[id]=ch;
            }
            else{break;}
        }
        else{
            break;
        }
        id=id*2+lr;
    }
    return minheap[size+1];
}
int main() {
    insert(1,1,5);
    insert(1,1,4);
    insert(1,1,7);
    insert(1,1,6);
    insert(1,1,8);
    insert(1,1,9);
    insert(1,1,2);
    insert(1,1,1);
    insert(1,1,3);
    //cout << size << endl;
    pos tmp[10];
    for(int i=1;i<=9;i++){
        tmp[i]=deque ();
        cout << tmp[i].h << endl;
    }
    cout << size << endl;
    insert(1,1,5);
    insert(1,1,4);
    insert(1,1,7);
    insert(1,1,6);
    insert(1,1,8);
    insert(1,1,9);
    insert(1,1,2);
    insert(1,1,1);
    insert(1,1,3);
    //cout << size << endl;
    for(int i=1;i<=9;i++){
        tmp[i]=deque ();
        cout << tmp[i].h << endl;
    }
    cout << size << endl;
    return 0;
}