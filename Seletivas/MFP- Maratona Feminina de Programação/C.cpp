#include <bits/stdc++.h>
using namespace std;

int main(){
  int x, y, m_1, m_2, ans;
  cin >> x >> y;
  m_1= x*(y/7);
  m_2= y*(x/7);

  ans = max(m_1, m_2);
  cout << ans << endl;
