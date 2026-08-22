class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;
        int idx = -1;

        // Find starting index of part 1
        while (low <= high) {
            int guess = (low + high) / 2;

            if (nums[guess] > nums[n - 1]) {  // part 2
                low = guess + 1;
            }
            else {  // part 1
                idx = guess;
                high = guess - 1;
            }
        }

        // Binary search in part 1
        int low1 = idx;
        int high1 = n - 1;

        while (low1 <= high1) {
            int guess1 = (low1 + high1) / 2;

            if (nums[guess1] == target) {
                return guess1;
            }
            else if (nums[guess1] > target) {
                high1 = guess1 - 1;
            }
            else {
                low1 = guess1 + 1;
            }
        }

        // Binary search in part 2
        int low2 = 0;
        int high2 = idx - 1;

        while (low2 <= high2) {
            int guess2 = (low2 + high2) / 2;

            if (nums[guess2] == target) {
                return guess2;
            }
            else if (nums[guess2] > target) {
                high2 = guess2 - 1;
            }
            else {
                low2 = guess2 + 1;
            }
        }

        return -1;
    }
};