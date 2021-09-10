#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  int answer = 0;
  scanf("%d", &n);
  vector<int> vt;
  for(int i=0;i<n;i++) {
    int num;
    scanf("%d", &num);
    vt.push_back(num);
  }
  sort(vt.begin(), vt.end(), greater<int>());

  for(int i=0;i<n;i+=3) {
    if(n-i >= 3) {
      answer += vt[i];
      answer += vt[i+1];
    }
    else {
      int k = n-i;
      for(int j=0;j<k;j++) {
        answer += vt[i+j];
      }
    }
  }
  printf("%d\n", answer);
}