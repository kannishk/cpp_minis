#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    

    return 0;
}

/* //Native, brute force solution
for (int i = 0; i < m; i++) {
  for (int j = 0; j < n; j++) {
    for (int p = 0; p < k; p++) {
      C(i, j) += A(i, p) * B(p, j);
    }
  }
}
*/