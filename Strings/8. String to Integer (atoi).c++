class Solution {
public:
    int myAtoi(string s) {
        if (s.empty()) {
            return 0;
        }

        int i = 0;
        while (s[i] == ' ') {
            i++;
        }

        bool flag = true;
        if (s[i] == '-' || s[i] == '+') {
            flag = (s[i] == '+');
            i++;
        }

        long long num = 0;
        while (i < s.size() && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');

            if ((num > INT_MAX && flag) || (num > INT_MAX + 1LL && !flag)) {
                return (flag) ? INT_MAX : INT_MIN;
            }

            i++;
        }

        return (flag) ? num : -num;
    }
};
