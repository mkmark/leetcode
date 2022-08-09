/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 381 ms, faster than 100.00% of C++ online submissions for Minimum Interval to Include Each Query.
Memory Usage: 116.3 MB, less than 78.66% of C++ online submissions for Minimum Interval to Include Each Query.

reference: leetcode fastest solution
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int startLimit = 1, endLimit = 10000007;
struct SegTreeNode
{
    int value=INT_MAX;
    SegTreeNode* left=NULL;
    SegTreeNode* right=NULL;
};

class Solution
{
public:
    SegTreeNode* rootNode = NULL;
    void update(SegTreeNode* &curNode,int st,int ed, int l,int r,int v)
    {
        if(curNode==NULL) curNode = new SegTreeNode();
        if(curNode->value<=v) return;
        if(st>=l && ed<=r)
        {
            curNode->value = min(curNode->value,v);
            return;
        }
        int mid = (st+ed)/2;
        if(r<=mid)  update(curNode->left,st,mid,l,r,v);
        else if(l>mid)  update(curNode->right,mid+1,ed,l,r,v);
        else update(curNode->left,st,mid,l,r,v) , update(curNode->right,mid+1,ed,l,r,v);
    }
    int read(SegTreeNode* curNode,int st,int ed,int point,int curResult=INT_MAX)
    {
        curResult = min(curResult,curNode->value);
        if(st == ed) return curResult;
        int mid = (st+ed)/2;
        if(point<=mid && curNode->left!=NULL) return read(curNode->left,st,mid,point,curResult);
        else if(point>mid && curNode->right!=NULL) return read(curNode->right,mid+1,ed,point,curResult);
        return curResult;
    }

    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries)
    {
        rootNode = new SegTreeNode();
        for(int i=0; i<intervals.size(); i++)
        {
            update(rootNode,startLimit,endLimit,intervals[i][0],intervals[i][1],intervals[i][1]-intervals[i][0] + 1);
        }
        vector<int>result;
        for(int i=0; i<queries.size(); i++)
        {
            int ans = read(rootNode,startLimit,endLimit,queries[i]);
            result.push_back(ans==INT_MAX?-1:ans);
        }
        return result;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
