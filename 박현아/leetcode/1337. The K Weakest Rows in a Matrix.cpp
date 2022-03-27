//220327
//leetcode #1337 The K Weakest Rows in a Matrix /Easy
//https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> sums;
        vector<int> results;
        
        for (int i = 0; i<mat.size(); i++){
            int sum_row = accumulate(mat[i].begin(), mat[i].end(), 0)
            sums.push_back(make_pair(sum_row, i));
        }
        
        //sort it by weakest to strongest, ascending sort
        sort(sums.begin(), sums.end());
        
        for (int i = 0; i<k; i++){
            results.push_back(sums[i].second);
        }
        
        return results;
    }
};
