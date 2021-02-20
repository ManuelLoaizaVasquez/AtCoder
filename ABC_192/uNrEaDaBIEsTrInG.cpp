//https://atcoder.jp/contests/abc192/tasks/abc192_b
#include <bits/stdc++.h>
#include <unistd.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
#define all(v) (v).begin(),(v).end()
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
  string s;
  cin >> s;
  int n = s.size();
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (i & 1) {
      if ('a' <= s[i] && s[i] <= 'z') {
        ok = false;
        break;
      }
    } else {
      if ('A' <= s[i] && s[i] <= 'Z') {
        ok = false;
        break;
      }
    }
  }
  if (ok) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}

