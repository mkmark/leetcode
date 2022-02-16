# hack

[significance-of-ios-basesync-with-stdiofalse-cin-tienull](https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull)

```cpp
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
```

[kth-competitive-programming/kactl](https://github.com/kth-competitive-programming/kactl/blob/main/content/contest/template.cpp)

```cpp
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
}
```
