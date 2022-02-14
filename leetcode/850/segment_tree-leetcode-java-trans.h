/*
author: mark@mkmark.net

implemented according to leetcode JAVA solution
count and value are stored in each node, linked by node pointers, i.e. tree as linked nodes
range_add optimized because we dont care about the exact status (i.e. how many rectangles are there) at a single point, we only care if it has rectangle over it or not, so a special method of top-to-bottom update is adopted instead of a traditional bottom-to-top one
comparatively a traditional segment tree (for range_sum query) is updated bottom-to-top
generally there should be a so-called push_up and push_down method defined for such situations

a direct translation that use pointer to record left and right child node will NOT work because the newly constructed object will be deconstructed after each call of "range_add". A solution would be store the newly constructed node in a static vector, which would require a tree-vector index map to avoid mutiple reconstruction, thus no longer require the left and right pointer.
for unkown reason, updating a class static object (line 56) messes up all the property of current object... not working , abandon
*/

#include <algorithm>    // std::max min
#include <vector>

namespace segment_tree{
    class node {
    public:  
        inline static std::vector<node> tree;
        // marks the range this node covers
        int start, end;
        // index to the two childs
        int self, left, right;
        int value;
        long count;

        node(int start, int end, int self) : 
            start(start), 
            end(end),
            self(self)
        {
            left = -1;
            right = -1;
            value = 0;
            count = 0;
        }

        node(int n)
        {
            start = 0, 
            end = n, 
            self = 0;
            left = -1;
            right = -1;
            value = 0;
            count = 0;
        }

        int get_range_mid() {
            return start + (end - start) / 2;
        }

        int get_left() {
            int tmp;
            if (tree[self].left == -1){
                tree[self].left = tree.size();
                tmp = tree.size();
                auto obj = node(start, get_range_mid(), tree[self].left);
                tree.push_back(obj);
                int dummy = 1;
            }
            return tmp;
        }

        int get_right() {
            int tmp;
            if (tree[self].right == -1){
                tree[self].right = tree.size();
                tmp = tree.size();
                auto obj = node(get_range_mid(), end, tree[self].right);
                tree.push_back(obj);
            }
            return tmp;
        }

        long range_add(int i, int j, int to_add, auto&& calc_count) {
            if (i >= j) return 0;

            // recursive tree update
            if (start == i && end == j) {
                value += to_add;
            } else {
                tree[get_left()].range_add(i, std::min(get_range_mid(), j), to_add, calc_count);
                tree[get_right()].range_add(std::max(get_range_mid(), i), j, to_add, calc_count);
            }

            // we care only if value>0 here
            if (value > 0) count = calc_count(start, end);
            else count = tree[get_left()].count + tree[get_right()].count;

            return count;
        }
    };
}

// maps the compressed index to actual position
// calc_count = x_pos[end] - x_pos[start];