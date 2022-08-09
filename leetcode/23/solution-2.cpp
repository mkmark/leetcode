struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 26 ms, faster than 88.81% of C++ online submissions for Merge k Sorted Lists.
Memory Usage: 13.9 MB, less than 24.76% of C++ online submissions for Merge k Sorted Lists.

reference: leetcode 8ms solution
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        // figure out empty lists cases
        ListNode* ans = NULL;
        vector<int> vals;
        // add all nodes to vector
        for(auto node : lists)
        {
            while(node != NULL)
            {
                vals.push_back(node->val);
                node = node->next;
            }
        }
        // all empty linkedlists
        if(vals.size() == 0)
        {
            return ans;
        }
        // sort vals
        sort(vals.begin(), vals.end());
        // store vals in ans
        ans = new ListNode(vals.at(0));
        ListNode* it = ans;
        int len = vals.size();
        for(int i = 1; i < len; i++)
        {
            it->next = new ListNode(vals.at(i));
            it = it->next;
        }
        return ans;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
