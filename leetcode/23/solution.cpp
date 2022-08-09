struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
author: mark@mkmark.net
time: O(nlogk)
space: O(k)

Runtime: 23 ms, faster than 94.36% of C++ online submissions for Merge k Sorted Lists.
Memory Usage: 13.4 MB, less than 47.77% of C++ online submissions for Merge k Sorted Lists.
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

auto cmp = [](ListNode * a, ListNode * b){
    return a->val > b->val;
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = nullptr;
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (auto & list : lists){
            if (list){
                /// size(pq) <= k
                pq.push(list);
            }
        }

        if (pq.size()){
            res = pq.top();
            if (res->next) pq.push(res->next);
            pq.pop();
        }

        auto cur = res;
        while (pq.size()){
            cur->next = pq.top();
            if (pq.top()->next) pq.push(pq.top()->next);
            pq.pop();
            cur = cur->next;
        }
        return res;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
