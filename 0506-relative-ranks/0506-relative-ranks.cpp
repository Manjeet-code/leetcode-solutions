class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        int n = score.size();

        vector<pair<int, int>> v;

        // {score, original index}
        for(int i = 0; i < n; i++) {
            v.push_back({score[i], i});
        }

        // Sort by score in decreasing order
        sort(v.begin(), v.end(), greater<pair<int, int>>());

        vector<string> res(n);

        for(int i = 0; i < n; i++) {

            int idx = v[i].second;

            if(i == 0) {
                res[idx] = "Gold Medal";
            }
            else if(i == 1) {
                res[idx] = "Silver Medal";
            }
            else if(i == 2) {
                res[idx] = "Bronze Medal";
            }
            else {
                res[idx] = to_string(i + 1);
            }
        }

        return res;
    }
};