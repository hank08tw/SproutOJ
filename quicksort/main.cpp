#include <iostream>
#include <vector>
#define SWAP(a,b,tmp) tmp=a; a=b; b=tmp;
using namespace std;
void quicksort(int left,int right,vector<int>& array){
    int i=left,j=right,tmp;
    while(i!=j){
        while(array[j]>=array[left]&&i!=j){
            j--;
        }
        while(array[i]<=array[left]&&i!=j){
            i++;
        }
        if(i!=j){
            SWAP(array[i],array[j],tmp);
        }
    }
    SWAP (array[left], array[i],tmp);
   
    for(int i=0;i<array.size ();i++){
        cout << array[i] << ' ';
    }
    cout << endl;
    if(left<i-1) {//不可用!= 兩個數 1 2 次i-1<left 也是不等於
        quicksort (left, i-1, array);
    }
    if(i+1<right) {
        quicksort (i+1, right, array);
    }
}
int main() {
    vector<int> array;
    int num;
    cin >> num;
    for(int i=0;i<num;i++) {
        int tmp;
        cin >> tmp;
        array.push_back (tmp);
    }
    quicksort(0,(int)array.size ()-1,array);
    for(int i=0;i<array.size ();i++){
        cout << array[i] << ' ';
    }
    return 0;
}