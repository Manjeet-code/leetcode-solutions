class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pair<char,int>>st;
        for(int i=0;i<n;i++){
            char c = s[i];
            if(st.empty()){
                st.push({c,1});
                continue;
            }
            if(st.top().first!=c){
                st.push({c,1});
                continue;
            }
            if(st.top().second<(k-1)){
                pair<char,int>P = st.top();
                st.pop();
                st.push({P.first,P.second+1});
                continue;
            }
            st.pop();
        }
        string res = "";
        while(!st.empty()){
            pair<char,int>P = st.top();
            st.pop();
            while(P.second--){
                res.push_back(P.first);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};