#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

stack<int> st;
vector<int> preorder;
map<int, pair<int, int> > tree;

void visit() {
  int curr = preorder[0];
  preorder.erase(preorder.begin());
  if(st.empty()) st.push(curr);
  else {
    int top = st.top();
    if(top > curr) {
      st.push(curr);
      tree[top].first = curr;
    } else {
      int parent;
      while(!st.empty() && st.top() < curr) {
        parent = st.top();
        st.pop();
      }
      st.push(curr);
      tree[parent].second = curr;
    }
  }
}

void postorder(int node) {
  if(tree[node].first != 0) {
    postorder(tree[node].first);
  }
  if(tree[node].second != 0) {
    postorder(tree[node].second);
  }
  printf("%d\n", node);
}


int main() {
  int num;
  while (cin >> num) {
	  preorder.push_back(num);
  }
  int start = preorder[0];
  while(!preorder.empty()) visit();
  postorder(start);
}