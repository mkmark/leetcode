#include <algorithm>    // std::max min
#include <vector>
#include <functional>

using namespace std;

namespace segment_tree {
    class segment_tree {
        private : vector<long> covered;
        private : vector<long> values;
            
        /* a tree with index
            1
            2         3
            4   5     6   7
            8 9 10 11
        */
        public : segment_tree(int n)
        {
            int count = 0;
            while( n != 0)
            {
                n >>= 1;
                count += 1;
            }
            int tree_size = 2 << count;

            // special indicator because we care only if a range is covered
            covered = vector<long>(tree_size, 0);
            // value store in tree
            values = vector<long>(tree_size, 0);
        }
        
        // m: middle of range [l,r)
        // o_l: left node index
        // o_r: right node index
        #define m ((l+r)>>1)
        #define o_l (o<<1)
        #define o_r (o<<1|1)

        /**
         *  @brief range add
         *  @param i range add [i,j)
         *  @param j range add [i,j)
         *  @param to_add value to add
         *  @param o current node index in tree
         *  @param l current node is in charge of area [l,r)
         *  @param r current node is in charge of area [l,r)
         *  @param calc_value function to calc val in intrerst
         */
        public : void range_add(int i, int j, int to_add, int o, int l, int r, function<long(int &l, int &r)> calc_value) {
            if (i >= j){
                return;
            }

            // recursive tree update
            if (l == i && r == j) {
                covered[o] += to_add;
            } else {
                if (o_r<values.size()){
                    range_add(i, min(m, j), to_add, o_l, l, m, calc_value);
                    range_add(max(m, i), j, to_add, o_r, m, r, calc_value);
                }
            }

            if (covered[o] > 0) {
                values[o] = calc_value(l, r);
            }
            else if (o_r<values.size()){
                push_down(o);
            } else {
                values[o] = 0;
            }
        }

        private : inline void push_down(int o){
            values[o] = values[o_l] + values[o_r];
        }

        public : long top() {
            return values[1];
        }
    };
}