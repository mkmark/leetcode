/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 22 ms, faster than 100.00% of C++ online submissions for Parallel Courses II.
Memory Usage: 8.4 MB, less than 88.21% of C++ online submissions for Parallel Courses II.

reference: leetcoe 26ms solution

dfs
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
	int N , K;
	
	vector<vector<int>> graph;
	int indegree[15];
	int finalBitMask;
	int dp[(1 << 15) + 1];

	int solve(int bitMask) {
		if (bitMask == finalBitMask) return 0;
		if (dp[bitMask] != -1) return dp[bitMask];

		memset(indegree, 0, sizeof(indegree));

		for (int i = 0; i < N; i++) {
            if (!(bitMask & (1 << i))) {
                for (int v : graph[i]) {
                    indegree[v]++;
                }
            }
        }

        int availMask = 0;

        for (int i = 0; i < N; i++) {
            if (!(bitMask & (1 << i)) && indegree[i] == 0) availMask |= (1 << i);
        }

        // before doing this check for the case where number of available courses are  <= K
        int curAns = N + 1;
        if (__builtin_popcount(availMask) < K) {
            curAns = min(curAns, 1 + solve(bitMask | availMask));
        }

        // else if the number of available courses are greater than k, do this
        else {
            // generating the submasks of a given bitMask 
            for (int subMask = availMask; subMask > 0; subMask = (subMask - 1) & availMask) {
                if (__builtin_popcount(subMask) == K) {
                    curAns = min(curAns, 1 + solve(bitMask | subMask));
                }
            }
        }
        return dp[bitMask] = curAns;
    }

    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        N = n;
        K = k;
        graph.resize(N);

        for (auto &e : relations) {
            graph[--e[0]].push_back(--e[1]);
        }

        memset(dp, -1, sizeof(dp));
        finalBitMask = ((1 << N) - 1);
        return solve(0);
	}
};