#include <bits/stdc++.h>
using namespace std;
 
int main(){
 
    string word;
    cin >> word;
 
    int num;
    cin >> num;
 
    set<string> palavras;
 
    for(int i = 0; i < num; i ++){
        
        string temp;
        cin >> temp;
        palavras.insert(temp);
 
    }
 
    
    int size = word.size();
    
    vector<int> verifica(size + 1, 0);
    
    verifica[0] = true; 
    
    for(int i = 0; i < size; i ++){
        
        if(!verifica[i]) continue;
 
        for(int tam = 6; tam <= 10; tam ++){
            if(i + tam <= size){
 
                string sub = word.substr(i, tam);
 
                if(palavras.count(sub)){
 
                    verifica[i + tam] = true;
 
                }
            }
        }
    }
 
    if(verifica[size]){
 
        cout << "yes" << endl;
 
    }else{
 
        cout << "no" << endl;
 
    }   
 
    return 0;
 
}
