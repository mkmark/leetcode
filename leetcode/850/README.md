---
tags: ['segment tree', 'line sweep']
---

# 850

This is a graph problem that can be optimized by multiprocessing.

# segment tree leetcode

implemented according to leetcode JAVA solution

count and value are stored in each node, linked by node pointers, i.e. tree as linked nodes

range_add optimized because we don't care about the exact status (i.e. how many rectangles are there) at a single point, we only care if it has rectangle over it or not, so a special method of top-to-bottom update is adopted. comparatively a traditional segment tree (for range_sum query) is updated bottom-to-top
