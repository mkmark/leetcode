# hack

[significance-of-ios-basesync-with-stdiofalse-cin-tienull](https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull)

```cpp
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
```

[kth-competitive-programming/kactl/content/contest/template.cpp](https://github.com/kth-competitive-programming/kactl/blob/main/content/contest/template.cpp)

```cpp
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
}
```

[dacin21/dacin21_codebook/utility/pragma_speedup.cpp](https://github.com/dacin21/dacin21_codebook/blob/master/utility/pragma_speedup.cpp)
```cpp
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") // codeforces
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native") // yandex
```
