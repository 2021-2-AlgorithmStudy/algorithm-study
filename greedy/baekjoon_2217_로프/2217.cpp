#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  vector<int> lopes;
  scanf("%d", &n);
  for(int i=0;i<n;i++) {
    int l;
    scanf("%d", &l);
    lopes.push_back(l);
  }
  sort(lopes.begin(), lopes.end(), greater<int>());
  int max_val = -1;
  for(int i=0;i<lopes.size();i++) {
    if((i+1)*lopes[i] > max_val) max_val = (i+1)*lopes[i];
  }
  printf("%d\n", max_val);
}