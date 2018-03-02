#include <iostream>
using namespace std;
int main() {
    int array[20][20];
    for(int i=0;i<20;i++){
        array[i][0]=1;
        array[i][i]=1;
        for(int j=1;j<i;j++){
            array[i][j]=array[i-1][j]+array[i-1][j-1];
        }
    }
    int t,n,m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        cout << array[n-1][m-1] << endl;
    }
    return 0;
}