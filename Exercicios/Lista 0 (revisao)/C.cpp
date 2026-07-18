#include <iostream>
using namespace std;

int main(){
    long long n = 0;
    cin >> n;
    bool complete = false;
    cout << n << " ";

    while (n!= 1 && complete == false){
        int par= n%2;
        if (par == 0){
            n=n/2;
            if (n == 1)
            {
                complete = true;
                cout << n;
            }
            else cout << n << " ";
            
        }
        else{
            n = (3*n)+1;
            cout << n << " ";
        }
    }

}
