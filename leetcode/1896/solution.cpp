/*
author: mark@mkmark.net
time: O(n)
space: O(n)

Runtime: 68 ms, faster than 88.46% of C++ online submissions for Minimum Cost to Change the Final Value of Expression.
Memory Usage: 51 MB, less than 35.90% of C++ online submissions for Minimum Cost to Change the Final Value of Expression.
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
                    int rval, rcost;
                    ++i;
                    tie(rval, rcost) = evaluate(expr, 0, 1, '+');
                    tie(val, cost) = eval(last_op, val, rval, cost, rcost);
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
                    tie(val, cost) = eval(last_op, val, 0, cost, 1);
                    break;
                case '1':
                    ++i;
                    tie(val, cost) = eval(last_op, val, 1, cost, 1);
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
    pair<int, int> eval(char op, int lval, int rval, int lcost, int rcost){
        int val, cost;
        switch (op){
            case '+':
                return {rval, rcost};
            case '&':
                if (lval == 0){
                    val = 0;
                    if (rval == 0){
                        cost = 1 + min(lcost, rcost);
                    } else {
                        cost = 1;
                    }
                } else {
                    val = rval;
                    if (rval == 0){
                        cost = 1;
                    } else {
                        cost = min(lcost, rcost);
                    }
                }
                return {val, cost};
            case '|':
                if (lval == 0){
                    val = rval;
                    if (rval == 0){
                        cost = min(lcost, rcost);
                    } else {
                        cost = 1;
                    }
                } else {
                    val = 1;
                    if (rval == 0){
                        cost = 1;
                    } else {
                        cost = 1 + min(lcost, rcost);
                    }
                }
                return {val, cost};
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
