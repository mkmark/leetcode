/*
author: mark@mkmark.net
time: O(mlogm)
space: O(m)

Runtime: 1059 ms, faster than 99.00% of C++ online submissions for Design Movie Rental System.
Memory Usage: 396.7 MB, less than 82.00% of C++ online submissions for Design Movie Rental System.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class MovieRentingSystem {
public:

    struct pairHash {
        size_t operator()(const pair<int, int>& p) const {
        return ((long long) p.first <<14) + p.second;
        }
    };

    /// https://stackoverflow.com/a/55734733/18672686
    /// rendted[i] = {price, shop, movie}
    set<array<int, 3>> rented;
    /// price_by_shop_movie[shop][movie] = price
    unordered_map<pair<int,int>, int, pairHash> price_by_shop_movie;
    /// unrented[movie] = {price, shop}
    unordered_map<int, set<pair<int, int>>> unrented;

    /// table: shop, movie, price, rented
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        /// [shop, movie, price]
        for (auto & entry : entries){
            price_by_shop_movie.insert({{entry[0], entry[1]}, entry[2]});
            unrented[entry[1]].insert({entry[2], entry[0]});
        }
    }

    /// SELECT shop
    /// WHERE movie=movie, rented=false
    /// ORDER BY price, shop ASC
    /// LIMIT 5
    vector<int> search(int movie) {
        vi res;
        auto it = unrented[movie].begin();
        int i = 0;
        while (i<5 && it != unrented[movie].end()){
            res.push_back((*it).second);
            ++it;
            ++i;
        }
        return res;
    }
    
    /// SET rented=true
    /// WHERE shop=shop, movie=movie
    void rent(int shop, int movie) {
        auto price = price_by_shop_movie[{shop, movie}];
        auto it = unrented.find(movie);
        (*it).second.erase((*it).second.find({price, shop}));
        rented.insert({price, shop, movie});
    }
    
    /// SET rented=false
    /// WHERE shop=shop, movie=movie
    void drop(int shop, int movie) {
        auto price = price_by_shop_movie[{shop, movie}];
        unrented[movie].insert({price, shop});
        rented.erase(rented.find({price, shop, movie}));
    }
    
    /// SELECT shop, movie 
    /// WHERE rented=true
    /// ORDER BY price, shop, movie ASC
    /// LIMIT 5
    vector<vector<int>> report() {
        vvi res;
        auto it = rented.begin();
        int i = 0;
        while (i<5 && it != rented.end()){
            res.push_back({(*it)[1], (*it)[2]});
            ++it;
            ++i;
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
