class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
    unordered_map<char,int>f;
    for(int i=0;i<n;i++){
      f[s[i]]++;
        }
    priority_queue<pair<int,char>>pq;
    for(auto i:f){
        pq.push({i.second,i.first});
    }
    string res = "";
    int seat = 0;
    while(!pq.empty()){
     auto   p1 = pq.top();
        pq.pop();
        if(seat==0 or res[seat-1]!=p1.second){
            res.push_back(p1.second);
            seat++;
            p1.first--;
            if(p1.first>0)
            pq.push(p1);
        }
        else{
            if(pq.empty())
            return "";
          auto  p2 = pq.top();
            pq.pop();
            res.push_back(p2.second);
            seat++;
            p2.first--;
            if(p2.first>0)
            pq.push(p2);
            pq.push(p1);
        }
    }
    return res;
    }
};