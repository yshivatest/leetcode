class Solution {
public:
    int myAtoi(string str) {
        int i;
        for(i = 0; i < str.size() && str[i] == ' '; i++) 
            ;
        if (i == str.size())
            return 0;
        int val = 0, sign = 0, mul = 10;//sign = 0 (pos), 1 (neg)
        if (str[i] == '+') {
            i++;
        } else if (str[i] == '-') {
            i++;
            sign = 1;
        }
        for (; i < str.size() && isdigit(str[i]); i++) {
            if (sign) {
                int temp = val;
                if (temp < INT_MIN/10) {
                    return INT_MIN;
                } else if (temp == INT_MIN/10 && str[i] == '9') {
                    return INT_MIN;
                }
                val  = mul*val - (str[i]-'0');
            } else {
                int temp = val;
                if (temp > INT_MAX/10) {
                    return INT_MAX;
                } else if (temp == INT_MAX/10 && 7 < str[i] - '0') {
                    return INT_MAX;
                }
                val  = mul*val + str[i]-'0';
            }
        }
        return val;
    }
};
