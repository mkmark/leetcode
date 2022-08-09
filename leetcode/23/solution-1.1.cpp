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

Runtime: 18 ms, faster than 98.99% of C++ online submissions for Merge k Sorted Lists.
Memory Usage: 13.4 MB, less than 60.31% of C++ online submissions for Merge k Sorted Lists.
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

        ListNode* nxt;
        if (pq.size()){
            res = pq.top();
            nxt = res->next;
            pq.pop();
            if (nxt) pq.push(nxt);
        }

        auto cur = res;
        while (pq.size()){
            cur->next = pq.top();
            nxt = pq.top()->next;
            pq.pop();
            if (nxt) pq.push(nxt);
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
