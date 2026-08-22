class Solution {
public:
    long long fun(vector<int>& piles,int n, int speed){
        long long h=0;
        for(int i=0;i<n;i++){
            h = h + piles[i]/speed;
            if(piles[i]%speed!=0) h++;
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        int high = maxi;
       int res = -1;
        while(low<=high){
            int guess = (low+high)/2;
            long long hour = fun(piles,n,guess);
            if(hour>h){
                low = guess+1;
            }
            else{
                res = guess;
                high = guess-1;
            }
        }
        return res;
    }
};