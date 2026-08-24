class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); // no. of rows
        int n = matrix[0].size(); // no. of cols
        int low = 0;
        int high = m*n - 1;

        while(low <= high) {
            int guess = (low + high) / 2;
            int row = guess/n;
            int col = guess%n;
            if(matrix[row][col] == target) {
               return true;
            }
            if(matrix[row][col] < target){
                low = guess+1;
            }
            else {
                high = guess - 1;
            }
        }
        return false;
    }
};