#include <iostream>
#include <vector>
using namespace std;
void mergesort(vector<int>& num){
    if(num.size ()==1){
        return;
    }
	#begin end傳的是iterator位址
    vector<int> left(num.begin (),num.begin ()+(num.size()/2));
    vector<int> right(num.begin ()+(num.size()/2),num.end ());

    mergesort (left);
    mergesort (right);

    for(int i=0,j=0,k=0;i<num.size ();i++){
        if((left[j]<right[k]&&j!=left.size ())||(k==right.size ())){
            num[i]=left[j++];
        }
        else{//else if(right[k]<left[j]&&k!=right.size ()||j==left.size()){
            num[i]=right[k++];
        }
    }
}
int main() {
    int num;
    vector<int> array;
    cin >> num;
    for(int i=0;i<num;i++){
        int tmp;
        cin >> tmp;
        array.push_back (tmp);
    }
    mergesort(array);
    for(int i=0;i<array.size ();i++){
        cout << array[i] << " ";
    }
    return 0;
}