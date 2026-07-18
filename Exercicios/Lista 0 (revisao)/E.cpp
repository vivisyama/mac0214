#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases;
    cin >> cases;
    for (int i = 0; i< cases; i++){
        int len;
        cin >> len;
        string s;
        cin >> s;
        string alf = "abcdefghijklmnopqrstuvwxyz";
        int maior=0, atual=0;

        for (int i = 0; i <len ; i++){
            for(int j= 0; j<26; j++){
                if (s[i]==alf[j]){
                    atual = j;
                }
            }
            maior = max(maior,atual);
        }
        cout<< maior+1 << endl;
    }
    
}
