class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;
        
        for (char c : expression) {
            if (c == ',' || c == '(') continue;
            
            if (c == ')') {
                vector<char> subExpr;
                
                while (stk.top() != '!' && stk.top() != '&' && stk.top() != '|') {
                    subExpr.push_back(stk.top());
                    stk.pop();
                }
                
                char op = stk.top();
                stk.pop();
                
                stk.push(evaluate(op, subExpr));
            } else {
                stk.push(c);
            }
        }
        
        return stk.top() == 't';
    }
    
private:
    char evaluate(char op, vector<char>& subExpr) {
        if (op == '!') {
            return (subExpr[0] == 't') ? 'f' : 't';
        } else if (op == '&') {
            for (char c : subExpr) {
                if (c == 'f') return 'f';
            }
            return 't';
        } else if (op == '|') {
            for (char c : subExpr) {
                if (c == 't') return 't';
            }
            return 'f';
        }
        return 'f';
    }
};
