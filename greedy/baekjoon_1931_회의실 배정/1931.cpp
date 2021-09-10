#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > vt;
int answer = 1;

bool comp(pair<int, int> &a, pair<int, int> &b) {
  if(a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i=0;i<n;i++) {
    int start, end;
    scanf("%d %d", &start, &end);
    vt.push_back(make_pair(start, end));
  }

  sort(vt.begin(), vt.end(), comp);
  int end = vt[0].second;
  vt.erase(vt.begin());
  for(auto x: vt) {
    if(x.first >= end){
      answer++;
      end = x.second;
    }
  }
  printf("%d\n", answer);
}