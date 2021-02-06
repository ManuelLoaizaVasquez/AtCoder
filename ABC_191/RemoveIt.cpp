//https://atcoder.jp/contests/abc191/tasks/abc191_b
#include <bits/stdc++.h>
#include <unistd.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;

const int N = 1e6;
const Long INF = 1e18;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

void Solve(void) {
  Long n, x;
  cin >> n >> x;
  vector<Long> a;
  for (int i = 0; i < n; i++) {
    Long aux;
    cin >> aux;
    if (aux != x) a.push_back(aux);
  }
  for (auto v : a) cout << v << " ";
  cout << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}

