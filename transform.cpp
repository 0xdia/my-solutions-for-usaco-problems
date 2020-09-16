/*
TASK: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
ifstream fin("transform.in");
ofstream fout("transform.out");

int N;

bool same(vector<string>& a, vector<string>& b) {
  for (int i=0; i<N; i++)
    if (a[i] != b[i])
      return false;
  return true;
}

vector<string> rotate90(vector<string>& v) {
  vector<string> ans(N, string(N, ' '));
  int M = N-1;
  for (int i=0; i<N; i++, M--) {
    for (int j=0; j<N; j++) {
      ans[j][M] = v[i][j];
    }
  }
  return ans;
}

vector<string> reflection(vector<string>& v) {
  vector<string> ans(N);
  for (int i=0; i<N; i++)
    ans[i].assign(rall(v[i]));
  return ans;
}

int answer(vector<string>& before, vector<string>& after) {
  vector<string> t = rotate90(before);
  if (same(t, after)) return 1;
  t = rotate90(t); // 180 rotation
  if (same(t, after)) return 2;
  t = rotate90(t); // 270 rotation
  if (same(t, after)) return 3;
  t = reflection(before);
  if (same(t, after)) return 4;

  t = rotate90(t);
  if (same(t, after)) return 5;
  t = rotate90(t);
  if (same(t, after)) return 5;
  t = rotate90(t);
  if (same(t, after)) return 5;

  if (same(before, after)) return 6;
  return 7;
}

int main(void) {
  fin >> N;
  vector<string> before(N), after(N);
  for (int i=0; i<N; i++)
    fin >> before[i];
  for (int i=0; i<N; i++)
    fin >> after[i];

  fout << answer(before, after) << endl;
  return 0;
}
