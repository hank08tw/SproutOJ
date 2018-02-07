#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> stack;
    int T,choice,num;
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> choice;
        if(choice==1){
            cin >> num;
            stack.push_back (num);
        }
        else if(choice==2){
            if(stack.empty ()){
                cout << "empty!";
            }
            else{
                cout << stack[stack.size ()-1];
                stack.pop_back ();
            }
            cout << endl;
        }
    }
    return 0;
}