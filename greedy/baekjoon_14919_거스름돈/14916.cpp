#include <iostream>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  if(n%2==1 && n<5) printf("-1\n");
  else {
    int q = n/5;
    int mod = n%5;
    int sum;
    if(mod%2==1 && q>0) {
      sum = q-1 + (n-(q-1)*5)/2;
    }
    else sum = q + ((n-q*5)/2);
    printf("%d\n", sum);
  }
}