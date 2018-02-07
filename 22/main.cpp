#include <iostream>
#include <vector>
#define MAX(a,b) (a>b) ? a : b
using namespace std;
int main() {
    int T,N,tmp,answer;
    cin >> T;
    for(int i=0;i<T;i++){
        vector<int> data;
        cin >> N;
        answer=N-1;
        for(int j=0;j<N;j++){
            cin >> tmp;
            data.push_back (tmp);
        }
        for(int a=0;a<data.size ()-1;a++){
            int max,index;
            if(data[a]<data[a+1]){continue;}
            max=data[a+1];
            index=a+2;
            while(index<data.size ()){
                if(data[index]>=max&&data[a]>=max){
                    answer++;
                }
                max= MAX(max,data[index]);//(max>data[i]) ? max : data[i];
                index++;
            }
        }
        cout << answer << endl;
    }
    return 0;
}