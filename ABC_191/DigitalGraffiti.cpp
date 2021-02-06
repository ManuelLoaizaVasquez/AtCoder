//https://atcoder.jp/contests/abc191/tasks/abc191_c
#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;

const int N = 10;
const Long INF = 1e18;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

string s[N];
int h, w;

int CountHorizontal(char up, char down) {
  int ans = 0;
  for (int i = 0; i < h - 1; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == up && s[i + 1][j] == down) {
        ans++;
        int k = j;
        while (k < w && s[i][k] == up && s[i + 1][k] == down) k++;
        j = k - 1;
      }
    }
  }
  return ans;
}

int CountVertical(char left, char right) {
  int ans = 0;
  for (int i = 0; i < w - 1; i++) {
    for (int j = 0; j < h; j++) {
      if (s[j][i] == left && s[j][i + 1] == right) {
        ans++;
        int k = j;
        while (k < h && s[k][i] == left && s[k][i + 1] == right) k++;
        j = k - 1;
      }
    }
  }
  return ans;
}

void Solve(void) {
  cin >> h >> w;
  for (int i = 0; i < h; i++) cin >> s[i];
  int ans = CountHorizontal('.', '#') + CountHorizontal('#', '.')
    + CountVertical('.', '#') + CountVertical('#', '.');
  cout << ans << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}

