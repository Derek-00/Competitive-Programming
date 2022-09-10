/**
 *    author:  willy
 *    created: Sat, 14 Aug 2021 13:30:54 GMT
**/
#include <cstdio>
#include <vector>

using namespace std;

inline char readchar() {
	const int S = 1<<20; // buffer size
	static char buf[S], *p = buf, *q = buf;
	if(p == q && (q = (p=buf)+fread(buf,1,S,stdin)) == buf) return EOF;
	return *p++;
}

inline int nextInt() {
	int x = 0, c = readchar(), neg = false;
	while(('0' > c || c > '9') && c!='-' && c!=EOF) c = readchar();
	if(c == '-') neg = true, c = readchar();
	while('0' <= c && c <= '9') x = x*10 + (c^'0'), c = readchar();
	if(neg) x = -x;
	return x; // returns 0 if EOF
}

int main() {
  int tt = nextInt();
  while (tt--) {
    int n = nextInt();
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      a[i] = nextInt();
    }
    vector<bool> match(n);
    int mx = a[0], mn = a.back();
    for (int i = 1; i < n - 1; i++) {
      if (a[i] > mx) {
        mx = a[i];
        match[i] = true;
      }
    }
    int ans = 0;
    for (int i = n - 2; i >= 1; i--) {
      if (a[i] < mn) {
        mn = a[i];
        match[i] && (++ans);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
