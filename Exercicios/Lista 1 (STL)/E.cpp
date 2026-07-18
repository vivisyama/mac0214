#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++){
        int N;
        cin >> N;
        vector<long long> height(N);

        for(int i = 0; i < N; i++)
        {
            cin >> height[i];
        }

        stack<int> s;
        long long max_area = 0;

        for(int i = 0; i <= N; i++){
            long long atual;

            if(i == N) atual = 0;
            else atual = height[i];

            while(!s.empty() && height[s.top()] >= atual){
                long long alt = height[s.top()];
                s.pop();

                long long larg;

                if(s.empty()) larg = i;
                else larg = i - s.top() - 1;
                max_area = max(max_area, alt * larg);
            }

            s.push(i);
        }

        cout << "Case " << t << ": " << max_area << "\n";
    }
}
