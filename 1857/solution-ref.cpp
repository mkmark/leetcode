// count by color on the first seen basis
// count from end of the path
// remove the dead ends as couting as a recursive approach, using queue
// https://leetcode.com/problems/largest-color-value-in-a-directed-graph/discuss/1672613/C%2B%2B-topological-sort-%2B-memoization

#include <queue>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
       
        vector<int> start_node_count(n, 0);
        vector<int> start_node_count2(n, 0);
        vector<vector<int>> nodes_to(n, vector<int>());
        for(vector<int>& edge : edges) {
            int first_node = edge[0];
            int second_node = edge[1];
            start_node_count[first_node]++;
            nodes_to[second_node].push_back(first_node);
        }
        
        int result = 0;
        // dp is the counter, counting strategy as top
        vector<int> dp(n, 0);
        // vector<int> is faster than vector<bool>, for access to single bits is usually slower than to complete addressable units
        // https://stackoverflow.com/questions/32821113/why-vectorint-is-faster-than-vectorbool-in-the-following-case#:~:text=As%20I%20know%20that%2C%20vector,each%20element%20using%204%20Bytes.
        // vector<int> seen(26, 0);
        // but array is faster
        int seen[26] = {0};
        for(char color : colors) {
            if(seen[color-'a']) continue;
            seen[color-'a'] = 1;
            
            queue<int> q;
            for(int i=0;i<n;++i) {
                // dp is -1 by default
                dp[i] = -1;
                start_node_count2[i] = start_node_count[i];
                if(start_node_count2[i] == 0) {
                    // if i is end of path
                    // dp is set to 1 if i is the end of path, and has the same color as the current
                    // dp is set to 0 if i is the end of path, and has different color as the current
                    // dp is set to -1 if i is not an end of path
                    dp[i] = (color-'a' == colors[i]-'a');
                    // push all end of path to q
                    q.push(i);
                }
            }
            
            for(int i=0;i<n;++i) {
                // no end of path, loop, return -1
                if(q.empty()) return -1;
                

                int some_end_of_path = q.front();
                q.pop();
                // result is set to the max result of all history, i.e. all colors, all paths
                result = max(result, dp[some_end_of_path]);
                
                for(int node_to_some_end_of_path : nodes_to[some_end_of_path]) {
                    // dp is set to the max of 
                    //     original
                    //     and if current color equals the second last node, plus 1 to the last node
                    dp[node_to_some_end_of_path] = max(dp[node_to_some_end_of_path], (color-'a' == colors[node_to_some_end_of_path]-'a')+dp[some_end_of_path]);
                    // for current color, remove the edge just processed
                    start_node_count2[node_to_some_end_of_path]--;
                    if(start_node_count2[node_to_some_end_of_path] == 0) {
                        // if we just made the second last node a new end node, which has no childs
                        // add the new end node to the processing queue
                        q.push(node_to_some_end_of_path);
                    }
                }
            }
        }

        return result;
    }
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);