#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i =0; i<t; i++){
        int q;
        cin >> q;
        deque<long long> b;

        long long soma = 0;
        long long sum = 0;

        bool rev = false;
        for(int j =0; j<q; j++){
            int s;
            cin >> s;

            if (s == 1){
                long long aux;
                if (!rev){
                    aux = b.back();
                    b.pop_back();
                    b.push_front(aux);
                }

                else{
                    aux = b.front();
                    b.pop_front();
                    b.push_back(aux);
                }

                soma = soma + sum - aux * b.size();
            }

            if (s == 2){
                rev = !rev;
                soma = (b.size()+1)*sum - soma;
            }

            if (s == 3){
                long long k;
                cin >> k;
                if (!rev)
                    b.push_back(k);
                else
                    b.push_front(k);

                sum += k;
                soma += k * b.size();
            }

            cout << soma << endl;
        }
    }
}
