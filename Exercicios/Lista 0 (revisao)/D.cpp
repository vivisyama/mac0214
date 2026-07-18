
#include <iostream>
#include <string>
using namespace std;

int main(){
    string seq;
    cin >> seq;
    long long n = seq.size();
    int atual = 1;
    int maior = 1;
    int j = 1;
    for (int i= 0; i< n; i++){
        if (seq[j] == seq [i]){
            atual += 1;
            if (atual > maior) maior = atual;
        }
        else atual = 1;
        j+=1;
    }
    
    cout << maior;
}

