#include <vector>       // std::vector
#include <iostream>     // std::iostream
#include <math.h>
#include <climits>

using namespace std;

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int min_diff = INT_MAX;
        int best_cost;
        for (auto base_cost : baseCosts){
            int snr_cnt = pow(3, toppingCosts.size());
            for (int i=0; i<snr_cnt; ++i){
                int top_sum = 0;
                int n = i;
                int p = 0;
                while(n!=0){
                    int m = n%3;
                    top_sum += m*toppingCosts[p++];
                    n /= 3;
                }
                int cost = top_sum+base_cost;
                if (abs(cost-target) < min_diff){
                    min_diff = abs(cost-target);
                    best_cost = cost;
                }
                if (abs(cost-target) == min_diff){
                    best_cost = min(cost, best_cost);
                }
            }
        }
        return best_cost;
    }
};
// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
