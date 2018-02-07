#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> queue;
    int T,choice,num;
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> choice;
        if(choice==1){
            cin >> num;
            queue.push_back (num);
        }
        else if(choice==2){
            if(queue.empty ()){
                cout << "empty!";
            }
            else{
                cout << queue[0];
                queue.erase(queue.begin (),queue.begin ()+1);
            }
            cout << endl;
        }
    }
    return 0;
}
