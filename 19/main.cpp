#include <iostream>
#include <vector>
using namespace std;
int main() {
    int T,N,n;
    cin >> T;
    vector<int> output;
    vector<int> middle;
    vector<int> input;
    for(int i=0;i<T;i++){
        output.clear ();
        middle.clear ();
        input.clear ();
        cin >> N;
        for(int j=1;j<=N;j++){
            cin >> n;
            output.push_back (n);
            input.push_back (j);
        }
        int output_flag=0,input_flag=0;
        while(output_flag!=N){
            /*
            cout << "middle:";
            for(int a=0;a<middle.size ();a++){
                cout << middle[a]  << " ";
            }
            cout << endl;
             */
            bool go=true;
            if(input_flag!=N){
                if(input[input_flag]==output[output_flag]){
                    input_flag++;
                    output_flag++;
                    go=false;
                }
            }
            if((!middle.empty ())&&go){
                if(output[output_flag]==middle.back ()){
                    middle.pop_back ();
                    output_flag++;
                    go=false;
                }
            }
            if(input_flag<N&&go){
                middle.push_back(input[input_flag]);
                input_flag++;
                go=false;
            }
            if(go){
                cout << "No" << endl;
                break;
            }
            if(output_flag==N){
                cout << "Yes" << endl;
                break;
            }
        }
    }
    return 0;
}
