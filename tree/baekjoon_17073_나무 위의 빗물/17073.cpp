#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> node[500001];
bool check[500001];
double w;
double answer;
int leaf_num;

void make_tree(int start, double per) {
  check[start] = true;
  int len = node[start].size();
  double child = 0;
  for(int i=0;i<len;i++) {
    if(!check[node[start][i]]) child++;
  }
  if(child==0) {
    leaf_num++;
    answer += w * per;
    return;
  }
  for(int i=0;i<len;i++) {
    if(!check[node[start][i]]){
      make_tree(node[start][i], per/child);
    }
  }
}

int main() {
  int n;
  scanf("%d %lf", &n, &w);
  for(int i=0;i<n-1;i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    node[u].push_back(v);
    node[v].push_back(u);
  }
  make_tree(1, 1.0);
  printf("%.10lf\n", answer/leaf_num);
}