/*
TASK: palsquare
LANG: C++
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream fin("palsquare.in");
ofstream fout("palsquare.out");

string to_base(int S, int base) {
  string answer = "";
  while (S) {
    if (S%base < 10) answer = to_string(S%base) + answer;
    else answer = char('A' + S%base - 10) + answer;
    S /= base;
  }
  return answer;
}

bool palindrome(string s) {
  return s == string(s.rbegin(), s.rend());
}

int main() {
  int B;
  fin >> B;
  for (int i=1; i<=300; i++) {
    if (palindrome(to_base(i*i, B)))
      fout << to_base(i, B) << ' ' << to_base(i*i, B) << endl;
  }
  return 0;
}
