#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<char, pair<char, char> > tree;

void preorder(char start) {
  printf("%c", start);
  char left = tree[start].first;
  char right = tree[start].second;
  if(left != '.') preorder(left);
  if(right != '.') preorder(right);
}

void inorder(char start) {
  char left = tree[start].first;
  char right = tree[start].second;
  if(left != '.') inorder(left);
  printf("%c", start);
  if(right != '.') inorder(right);
}

void postorder(char start) {
  char left = tree[start].first;
  char right = tree[start].second;
  if(left != '.') postorder(left);
  if(right != '.') postorder(right);
  printf("%c", start);
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i=0;i<n;i++) {
    char node, left, right;
    cin >> node >> left >> right;
    tree[node] = make_pair(left, right);
  }

  preorder('A');
  printf("\n");
  inorder('A');
  printf("\n");
  postorder('A');
  printf("\n");
}