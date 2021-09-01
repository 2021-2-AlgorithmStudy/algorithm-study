#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);

  for(int i=0;i<t;i++) {
    int m;
    int cnt = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    scanf("%d", &m);
    printf("%d\n", m/2+1);
    for(int j=0;j<m;j++) {
      int num;
      scanf("%d", &num);
      pq.push(num);
      if(j%2 == 0) {       
        vector<int> vt;
        if((cnt+1)%10==0) printf("\n");
        for(int k=0;k<(j+1)/2;k++) {
          vt.push_back(pq.top());
          pq.pop();
        }
        printf("%d ", pq.top());
        for(auto x: vt) {
          pq.push(x);
        }

      }
      cnt++;
    }
    printf("\n");
  }
}

/*


1 2 3 4 5 6 7 8 9

9 8 7 6 5 4 3 2 1

23 41 13 22 -3 24 -41 -11 -8 -7





max heap: 1
min heap: 1

middle: 9 8

*/