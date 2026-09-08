class Solution {
public:
    int countCommas(int n) {
        if(n<=999) return 0;
        else return 1+(n-1000);
    }
};