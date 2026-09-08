class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return "0";

        bool negative = num < 0;
        num = abs(num);

        string ans = "";

        while(num > 0) {
            int rem = num % 7;
            ans += char('0' + rem);
            num = num / 7;
        }

        if(negative)
            ans += '-';

        reverse(ans.begin(), ans.end());

        return ans;
    }
};