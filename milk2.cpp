/*
TASK: milk2
LANG: C++
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream fin("milk2.in");
ofstream fout("milk2.out");

constexpr int SZ = 1e6 + 10;
vector<int> t(SZ);

int main() {
  int N;
  fin >> N;
  int s, e;
  int Max=-1, Min=1e7;
  for (int i=0; i<N; i++) {
    fin >> s >> e;
    Min = min(Min, s);
    Max = max(Max, e);
    ++t[s];
    --t[e];
  }

  int m, r, Milk=0, Rest=0;
  m = 1;
  r = 0;
  for (int i=Min+1; i<=Max; i++) {
    t[i] += t[i-1];
    if (t[i]) {
      if (t[i-1]) ++m;
      else {
        Rest = max(Rest, r);
        r = 0;
        m = 1;
      }
    } else {
      if (t[i-1] == 0) ++r;  
      else {
        Milk = max(Milk, m);
        r = 1;
        m = 0;
      }
    }
  }

  fout << Milk << ' ' << Rest << endl;
  return 0;
}
