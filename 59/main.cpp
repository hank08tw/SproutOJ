#include <stdio.h>
#include <iostream>
#include <vector>
#define SWAP(a,b) a=a+b,b=a-b,a=a-b
using namespace std;
void push(vector<int>* minheap,int data){
    minheap->push_back (data);
    int i=(int)(minheap->size ());
    while(i>1){
        if((*minheap)[i-1]<(*minheap)[i/2-1]){
            SWAP((*minheap)[i-1],(*minheap)[i/2-1]);
        }
        else{break;}
        i/=2;
    }
}
//如果有左右子樹且兩個元素的值都比上面的元素小 選更小的那個下沉，如果只有一個較小，選那個下沉，如果沒有更小的就停止．如果只有左子樹且元素更小的話下沉，如果沒子樹就不下沉
void pop(vector<int>* minheap){
    if(minheap->empty ()){
        cout << "empty!" << endl;
    }
    else{
        cout << minheap->front() << endl;
        minheap->front ()=minheap->back ();
        minheap->pop_back ();
        int i=1;
        while(true){
            if(i*2<minheap->size ()) {//有兩左右子樹
                if((*minheap)[i*2-1]<(*minheap)[i-1]&&(*minheap)[i*2+1-1]<(*minheap)[i-1]){//兩個元素都比上面的元素小
                    if((*minheap)[i*2-1]<=(*minheap)[i*2+1-1]){//左邊的元素更小
                        SWAP ((*minheap)[i-1],(*minheap)[i*2-1]);
                        i*=2;
                    }
                    else{
                        SWAP ((*minheap)[i-1],(*minheap)[i*2+1-1]);//右邊的元素更小
                        i=i*2+1;
                    }
                }
                else if((*minheap)[i*2-1]<(*minheap)[i-1]&&(*minheap)[i*2+1-1]>=(*minheap)[i-1]){//只有左邊的元素較小
                    SWAP ((*minheap)[i-1],(*minheap)[i*2-1]);
                    i*=2;
                }
                else if((*minheap)[i*2-1]>=(*minheap)[i-1]&&(*minheap)[i*2+1-1]<(*minheap)[i-1]){//只有右邊的元素較小
                    SWAP ((*minheap)[i-1],(*minheap)[i*2+1-1]);
                    i=i*2+1;
                }
                else{break;}
            }
            else if(i*2==minheap->size ()&&(*minheap)[i*2-1]<(*minheap)[i-1]){//只有左子樹且下面元素小於上面
                SWAP ((*minheap)[i-1],(*minheap)[i*2-1]);
                i*=2;
            }
            else{
                break;
            }
        }
    }
}
int main() {
    vector<int> minheap;
    int time,a,b;
    scanf("%d",&time);
    for(int i=0;i<time;i++){
        scanf("%d",&a);
        if(a==2){
            pop(&minheap);
        }
        else{
            scanf("%d",&b);
            push(&minheap,b);
        }
    }
    return 0;
}




/*
#include <iostream>
#include <vector>
#define SWAP(a,b) a=a+b,b=a-b,a=a-b
using namespace std;
vector<int> minheap;
void push(int data){
    minheap.push_back (data);
    int i=(int)(minheap.size ());
    while(i>1){
        if((minheap)[i-1]<(minheap)[i/2-1]){
            SWAP((minheap)[i-1],(minheap)[i/2-1]);
        }
        else{break;}
        i/=2;
    }
}
//如果有左右子樹且兩個元素的值都比上面的元素小 選更小的那個下沉，如果只有一個較小，選那個下沉，如果沒有更小的就停止．如果只有左子樹且元素更小的話下沉，如果沒子樹就不下沉
void pop(){
    if(minheap.empty ()){
        cout << "empty!" << endl;
    }
    else{
        cout << minheap.front() << endl;
        minheap.front ()=minheap.back ();
        minheap.pop_back ();
        int i=1;
        while(true){
            if(i*2<minheap.size ()) {//有兩左右子樹
                if((minheap)[i*2-1]<(minheap)[i-1]&&(minheap)[i*2+1-1]<(minheap)[i-1]){//兩個元素都比上面的元素小
                    if((minheap)[i*2-1]<=(minheap)[i*2+1-1]){//左邊的元素更小
                        SWAP ((minheap)[i-1],(minheap)[i*2-1]);
                        i*=2;
                    }
                    else{
                        SWAP ((minheap)[i-1],(minheap)[i*2+1-1]);//右邊的元素更小
                        i=i*2+1;
                    }
                }
                else if((minheap)[i*2-1]<(minheap)[i-1]&&(minheap)[i*2+1-1]>=(minheap)[i-1]){//只有左邊的元素較小
                    SWAP ((minheap)[i-1],(minheap)[i*2-1]);
                    i*=2;
                }
                else if((minheap)[i*2-1]>=(minheap)[i-1]&&(minheap)[i*2+1-1]<(minheap)[i-1]){//只有右邊的元素較小
                    SWAP ((minheap)[i-1],(minheap)[i*2+1-1]);
                    i=i*2+1;
                }
                else{break;}
            }
            else if(i*2==minheap.size ()&&(minheap)[i*2-1]<(minheap)[i-1]){//只有左子樹且下面元素小於上面
                SWAP ((minheap)[i-1],(minheap)[i*2-1]);
                i*=2;
            }
            else{
                break;
            }
        }
    }
}
int main() {
    //vector<int> minheap;
    minheap.clear ();
    int time,a,b;
    cin >> time;
    for(int i=0;i<time;i++){
        cin >> a;
        if(a==2){
            pop();
        }
        else{
            cin >> b;
            push(b);
        }
    }
    return 0;
}
 */