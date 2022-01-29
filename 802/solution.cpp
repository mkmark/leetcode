#include <vector>       // std::vector
#include <iostream>     // std::iostream

using namespace std;

class Solution {
public:
    const int IS_UNKNOWN = 0;
    const int IS_SAFE = 1;
    const int IS_DANGEROUS = 2;

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int graph_size = graph.size();
        vector<int> status(graph_size);
        vector<int> seen(graph_size);

        vector<int> eventual_safe_nodes;

        for (int i=0; i<graph.size(); ++i){
            if (get_status(i, graph, status, seen) == IS_SAFE){
                eventual_safe_nodes.push_back(i);
            }
        }

        return eventual_safe_nodes;
    }

    int get_status(
        int i,
        vector<vector<int>>& graph,
        vector<int>& status,
        // seen can be reserved because seen[i] of previous cycle has been marked on status[i], and is no longer interested. whatever remains is in current cycle.
        vector<int>& seen
    ){
        if (status[i] == IS_UNKNOWN){
            if (seen[i] == 1){
                status[i] = IS_DANGEROUS;
                return IS_DANGEROUS;
            }
            seen[i] = 1;
            for (auto j : graph[i]){
                auto temp_status_j = get_status(j, graph, status, seen);
                if (temp_status_j == IS_DANGEROUS){
                    status[i] = IS_DANGEROUS;
                    return IS_DANGEROUS;
                }
            }
            status[i] = IS_SAFE;
            return IS_SAFE;
        } else {
            return status[i];
        }
    }
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);