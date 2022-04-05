//220331
//leetcode #36 Valid Sudoku /Medium
//https://leetcode.com/problems/valid-sudoku/

#define MAX 9

class Solution {
public:
    static bool compare(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<pair<int,int>> nums[MAX];
      
        //collect placement information for each number
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[i].size(); j++){
                if(board[i][j] !='.'){
                    int num = board[i][j]-'0';
                    nums[num-1].push_back(make_pair(i,j));
                }
            }
        }

        //validation based on sorted rows
        for(auto num : nums){
            for(int i = 1; i<num.size(); i++){
                auto pre = num[i-1];
                auto nxt = num[i];
                
                if((pre.first == nxt.first) || ((pre.first/3 == nxt.first/3) && (pre.second/3 == nxt.second/3))){
                    return false;
                }
            }
        }
        
        //sort by columns
        for(int i = 0; i<MAX; i++){
            sort(nums[i].begin(),nums[i].end(),compare);
        }
        
        //validation based on sorted columns
        for(auto num : nums){
            for(int i = 1; i<num.size(); i++){
                auto pre = num[i-1];
                auto nxt = num[i];
                
                //also have to check the third rule again.
                if((pre.second == nxt.second) || ((pre.first/3 == nxt.first/3) && (pre.second/3 == nxt.second/3))){
                    return false;
                }
            }
        }
        
        return true;
    }
};
