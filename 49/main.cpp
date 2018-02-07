#include <iostream>
#include <vector>
#define N 100001
using namespace std;
vector<int> boxes[N];
int answer[N];
bool inside[N];
int check(int n){
    int sum=1;
    for(int i=0;i<boxes[n].size ();i++){
        sum+=check(boxes[n][i]);
    }
    answer[n]=sum;
    return sum;
}
int main() {
    int T,time,box,a,b,choice;
    cin >> T;
    for(int j=1;j<=T;j++){
        cin >> box >> time;
        for(int i=0;i<N;i++){
            boxes[i].clear ();
            inside[i]=false;
            answer[i]=0;
        }
        for(int i=1;i<=time;i++){
            cin >> a >> b;
            boxes[a].push_back (b);
            inside[b]=true;
        }
        for(int i=1;i<=box;i++){
            if(!inside[i]){
                check(i);
            }
        }
/*
        for(int i=1;i<=box;i++){
            cout << answer[i] << " ";
        }
        cout << endl;
*/
        cin >> time;
        for(int i=1;i<=time;i++){
            cin >> choice;
            cout << answer[choice] << endl;
        }

    }
    return 0;
}
