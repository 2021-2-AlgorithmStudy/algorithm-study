#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;

map<int, pair<int, int> > tree;
int check[1024];
queue<int> q;

void visit(int start) {
  int temp;
  if(tree[start].first == 0) {
    temp = q.front();
    check[start] = temp;
    q.pop();
    return;
  }
  visit(tree[start].first);
  temp = q.front();
  check[start] = temp; 
  q.pop();
  visit(tree[start].second);
}


int main() {
  int k;
  scanf("%d", &k);
  int node_num = pow(2, k)-1;
  int leaf_num = pow(2, k-1);
  for(int i=1;i<=node_num-leaf_num;i++) {
    tree[i] = make_pair(i*2, i*2+1);
  }
  for(int i=node_num-leaf_num+1;i<=node_num;i++) {
    tree[i] = make_pair(0, 0);
  }

  for(int i=0;i<node_num;i++) {
    int num;
    scanf("%d", &num);
    q.push(num);
  }
  visit(1);

  for(int i=1;i<=node_num;i*=2) {
    for(int j=i;j<i*2;j++) {
      printf("%d ", check[j]);
    }
    printf("\n");
  }
}
