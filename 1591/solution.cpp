#include <vector>       // std::vector
#include <iostream>     // std::iostream

using namespace std;

class Solution {
public:
    bool isPrintable(vector<vector<int>>& target_grid) {
        // 60 color and 4 rect params
        const int color_count_max = 61;
        int n = target_grid.size();
        int m = target_grid[0].size();

        int is_color_there[color_count_max] = {0};
        int rects[color_count_max][4] = {0,0,0,0};
        int color_count = 0;
        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                int color = target_grid[i][j];
                if (!is_color_there[color]){
                    is_color_there[color] = 1;
                    rects[color][0] = i;
                    rects[color][1] = j;
                    ++color_count;
                } else {
                    // rects[color][0] = min(i, rects[color][0]);
                    rects[color][1] = min(j, rects[color][1]);
                    rects[color][2] = max(i, rects[color][2]);
                    rects[color][3] = max(j, rects[color][3]);
                }
            }
        }

        int colors_over_color[color_count_max][color_count_max] = {0};
        for (int color=1;color<color_count_max;++color){
            if (!is_color_there[color]){
                continue;
            }
            for (int i=rects[color][0];i<=rects[color][2];++i){
                for (int j=rects[color][1];j<=rects[color][3];++j){
                    auto another_color = target_grid[i][j];
                    colors_over_color[color][another_color] = 1;
                }
            }
            colors_over_color[color][color] = 0;
        }

        vector<vector<int>> graph(color_count_max);
        for (int color=0;color<color_count_max;++color){
            if (!is_color_there[color]){
                continue;
            }else{
                vector<int> empty;
                graph.push_back(empty);
            }
            for (int another_color=0;another_color<color_count_max;++another_color){
                if (colors_over_color[color][another_color] == 1){
                    graph[color].push_back(another_color);
                }
            }
        }

        return eventualSafeNodes(graph);
    }

    // 802

    const int IS_UNKNOWN = 0;
    const int IS_SAFE = 1;
    const int IS_DANGEROUS = 2;

    bool eventualSafeNodes(vector<vector<int>>& graph) {
        int graph_size = graph.size();
        vector<int> status(graph_size);
        vector<int> seen(graph_size);

        vector<int> eventual_safe_nodes;

        for (int i=0; i<graph.size(); ++i){
            if (get_status(i, graph, status, seen) != IS_SAFE){
                return false;
            }
        }

        return true;
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