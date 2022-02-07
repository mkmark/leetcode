#include <vector>       // std::vector
#include <iostream>     // std::iostream

using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int snr_cnt = 1<<n;
        // all possibilities for 1st line
        for (int k=0; k<snr_cnt; ++k){
            int x = k;
            int p = 0;
            auto local_mat = mat;
            int step = 0;
            while(x!=0){
                if(x%2){
                    flip(local_mat, 0, p);
                    ++step;
                }
                ++p;
                x >>= 1;
            }
            int sda = 0;
            // flip lower lines by previous line
            for (int i=1; i<m; ++i){
                for (int j=0; j<n; ++j){
                    if (local_mat[i-1][j]){
                        flip(local_mat, i, j);
                        ++step;
                    }
                }
            }
            int sum = 0;
            for (int j=0; j<n; ++j){
                sum += local_mat[m-1][j];
            }
            if (sum == 0){
                return step;
            }
        }
        return -1;
    }
    inline void invert(int& x){
        x = 1 - x;
    }
    void flip(vector<vector<int>>& mat, int i, int j){
        invert(mat[i][j]);
        if (i>0)
            invert(mat[i-1][j]);
        if (j>0)
            invert(mat[i][j-1]);
        if (i+1<mat.size())
            invert(mat[i+1][j]);
        if (j+1<mat[0].size())
            invert(mat[i][j+1]);
    }
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);