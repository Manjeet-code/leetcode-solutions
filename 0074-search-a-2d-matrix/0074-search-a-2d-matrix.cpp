class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();

        int low = 0;
        int high = n - 1;
        int row = -1;

        // Find the possible row
        while(low <= high) {
            int guess = (low + high) / 2;

            if(matrix[guess][0] <= target) {
                row = guess;
                low = guess + 1;
            }
            else {
                high = guess - 1;
            }
        }

        // Target is smaller than first element
        if(row == -1) {
            return false;
        }

        int m = matrix[0].size();

        low = 0;
        high = m - 1;

        // Binary search in selected row
        while(low <= high) {
            int guess = (low + high) / 2;

            if(matrix[row][guess] == target) {
                return true;
            }
            else if(matrix[row][guess] < target) {
                low = guess + 1;
            }
            else {
                high = guess - 1;
            }
        }

        return false;
    }
};