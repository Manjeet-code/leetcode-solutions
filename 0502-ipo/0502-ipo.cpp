class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>>Proj;
        for(int i=0;i<n;i++){
            Proj.push_back({capital[i],profits[i]});
        }
        sort(Proj.begin(),Proj.end());
        priority_queue<int>pq;
        int idx = 0;
        while(k--){
            while(idx<n){
                if(Proj[idx].first>w)
                break;
                pq.push(Proj[idx].second);
                idx++;
            }
            if(pq.empty())
                return w;
                w = w + pq.top();
                pq.pop();
        }
        return w;
    }
};