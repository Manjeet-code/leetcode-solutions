class Solution {
public:
    bool res = true;
    void dfs(vector<vector<int>>& graph,int node,int c,vector<int>& colours){
        colours[node]=c;
        for(int j=0;j<graph[node].size();j++){
            int neigh = graph[node][j];
            if(colours[neigh]!=-1 && colours[neigh]==c)
                    res = false;
            if(colours[neigh]==-1)
                dfs(graph,neigh,1-c,colours);        
        }
        return;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>colours(n,-1);
        for(int i=0;i<n;i++){
            if(colours[i]==-1)
                   dfs(graph,i,0,colours); 
        }
        return res;
    }
};