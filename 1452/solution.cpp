// Runtime: 328 ms, faster than 85.48% of C++ online submissions for People Whose List of Favorite Companies Is Not a Subset of Another List.
// Memory Usage: 89.7 MB, less than 38.17% of C++ online submissions for People Whose List of Favorite Companies Is Not a Subset of Another List.

#include <vector>       // std::vector
#include <iostream>     // std::iostream
#include <map>
#include <bitset>

using namespace std;

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int n = favoriteCompanies.size();
        // index of fav_comps
        map<string, int> mp;
        int mp_idx = 0;
        for (auto &fav_comps : favoriteCompanies){
            for (auto &fav_comp : fav_comps){
                if (mp.find(fav_comp)==mp.end()){
                    mp.insert(make_pair(fav_comp, mp_idx++));
                }
            }
        }

        vector<bitset<50000>> bs;
        for (auto &fav_comps: favoriteCompanies) {
            bitset<50000> b;
            for (auto &fav_comp: fav_comps) {
                b[mp[fav_comp]] = 1;
            }
            bs.push_back(b);
        }

        vector<int> res;
        for (int i=0; i<n; ++i) {
            bool is_i_not_subset = true;
            for (int j=0; j<n; ++j) {
                if (i==j) continue;
                if (bs[i] == (bs[i] & bs[j])){
                    is_i_not_subset = false;
                    break;
                }
            }
            if (is_i_not_subset) res.push_back(i);
        }

        return res;
    }
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
