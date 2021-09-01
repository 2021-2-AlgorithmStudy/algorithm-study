#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> tree[100001];
int answer[100001];
bool check[100001];
queue<int> q;

void bfs(int start){
  q.push(start);
  while(!q.empty()) {
    int curr = q.front();
    check[curr] = true;
    q.pop();
    for(int i=0;i<tree[curr].size();i++) {
      int next = tree[curr][i];
      if(check[next]) continue;
      answer[next] = curr;
      q.push(next);
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i=0;i<n-1;i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  fill(check, check+n, false);

  bfs(1);

  for(int i=2;i<=n;i++) {
    printf("%d\n", answer[i]);
  }
}