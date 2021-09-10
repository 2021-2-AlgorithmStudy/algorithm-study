#include <iostream>
#include <vector>
using namespace std;

int main() {
  int a,b;
  scanf("%d %d", &a, &b);
  string b_str = to_string(b);
  string a_str = to_string(a);
  
  int answer;
  int cnt = 0;
  while(true) {
    if(stoi(a_str) == stoi(b_str)) {
      answer = cnt;
      printf("%d\n", answer+1);
      break;
    }
    if(stoi(a_str) > stoi(b_str)) {
      printf("-1\n");
      break;
    }
    if(b_str[b_str.size()-1] == '1') {
      b_str = b_str.substr(0, b_str.size()-1);
      cnt++;
    }
    else if(stoi(b_str)%2 == 0) {
      b_str = to_string(stoi(b_str)/2);
      cnt++;
    }
    else {
      printf("-1\n");
      break;
    }
  }
}