/*
author: mark@mkmark.net
time: O(n)
space: O(count of '(')

Runtime: 31 ms, faster than 100.00% of C++ online submissions for Minimum Cost to Change the Final Value of Expression.
Memory Usage: 44 MB, less than 37.18% of C++ online submissions for Minimum Cost to Change the Final Value of Expression.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution{
public:
    int n;
    int minOperationsToFlip(string expression){
        n = size(expression);
        return evaluate(expression, 0, 1, '+').second;
    }

    int i = 0;

    /**
     * @brief
     *
     * @param expr
     * @param i evaluate position
     * @param val
     * @return pair<int,int> value and cost
     */
    pair<int, int> evaluate(string &expr, int val, int cost, char last_op){
        while (i < n){
            switch (expr[i]){
                case '(':
                    ++i;
                    int rval, rcost;
                    tie(rval, rcost) = evaluate(expr, 0, 1, '+');
                    eval(last_op, val, rval, cost, rcost);
                    break;
                case ')':
                    ++i;
                    return {val, cost};
                case '&':
                    ++i;
                    last_op = '&';
                    break;
                case '|':
                    ++i;
                    last_op = '|';
                    break;
                case '0':
                    ++i;
                    eval(last_op, val, 0, cost, 1);
                    break;
                case '1':
                    ++i;
                    eval(last_op, val, 1, cost, 1);
                    break;
            }
            
        }
        return {val, cost};
    }

    /// 0 & 0, 1 + min(cost(left), cost(right))
    /// 0 & 1, 1
    /// 1 & 0, 1
    /// 1 & 1, min(cost(left), cost(right))
    /// 0 | 0, min(cost(left), cost(right))
    /// 0 | 1, 1
    /// 1 | 0, 1
    /// 1 | 1, 1 + min(cost(left), cost(right))
    inline void eval(char & op, int & lval, const int & rval, int & lcost, const int & rcost){
        switch (op){
            case '+':
                lval = rval;
                lcost = rcost;
                return;
            case '&':
                if (lval == 0){
                    if (rval == 0){
                        lcost = 1 + min(lcost, rcost);
                    } else {
                        lcost = 1;
                    }
                    lval = 0;
                } else {
                    if (rval == 0){
                        lcost = 1;
                    } else {
                        lcost = min(lcost, rcost);
                    }
                    lval = rval;
                }
                return;
            case '|':
                if (lval == 0){
                    if (rval == 0){
                        lcost = min(lcost, rcost);
                    } else {
                        lcost = 1;
                    }
                    lval = rval;
                } else {
                    if (rval == 0){
                        lcost = 1;
                    } else {
                        lcost = 1 + min(lcost, rcost);
                    }
                    lval = 1;
                }
                return;
        }
        throw;
    }
};

const static auto initialize = []
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
