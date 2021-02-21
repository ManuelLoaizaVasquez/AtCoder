//https://atcoder.jp/contests/arc113/tasks/arc113_a
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
  Long k;
  cin >> k;
  vector<Long> dos(k + 1, 0);
  for (Long i = 1; i <= k; i++) {
    Long j = 1;
    while (i * j <= k) {
      dos[i * j]++;
      j++;
    }
  }
  vector<Long> acc(k + 1);
  acc[0] = dos[0];
  for (Long i = 1; i <= k; i++) acc[i] = acc[i - 1] + dos[i];
  Long ans = 0;
  for (Long i = 1; i <= k; i++) {
    Long needed = k / i;
    ans += acc[needed];
  }
  cout << ans << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}

