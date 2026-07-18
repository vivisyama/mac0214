#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<long long> arr(n);

    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }

    long long l = *max_element(arr.begin(), arr.end());
    long long soma_max = accumulate(arr.begin(), arr.end(), arr[0]);
    long long ans = soma_max;

    while (l <= soma_max){
        long long mid = (l + soma_max) / 2;

        int subarr = 1;
        long long sum = 0;

        for (int i = 0; i < n; i++){
            if (sum +arr[i] <= mid){
                sum+=arr[i];
            } else{
                subarr++;
                sum =arr[i];
            }
        }
        if (subarr <= k){
            ans = mid;
            soma_max = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}
