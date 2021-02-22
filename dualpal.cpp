/*
TASK: dualpal
LANG: C++
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream fin("dualpal.in");
ofstream fout("dualpal.out");

string to_base(int S, int base) {
  string answer = "";
  while (S) {
    answer = to_string(S%base) + answer;
    S /= base;
  }
  return answer;
}

bool palindrome(string s) {
  return s == string(s.rbegin(), s.rend());
}

bool palindrome_in_more_than_two_bases(int S) {
  bool pal = palindrome(to_string(S));
  for (int base=2; base<10; base++)
    if (palindrome(to_base(S, base))) {
      if (pal)
        return true;
      else pal = true;
    }
  return false;
}

int main() {
  int N, S;
  fin >> N >> S;
  for (++S; N != 0; S++) {
    if (palindrome_in_more_than_two_bases(S)) {
      fout << S << endl;
      --N;
    }
  }
  return 0;
}
