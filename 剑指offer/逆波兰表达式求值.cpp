class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i++) {
            if (!isdigit(tokens[i][0]) && tokens[i].length() == 1) {
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                switch(tokens[i][0]) {
                    case '+':
                        stk.push(num1 + num2);
                        break;
                    case '-':
                        stk.push(num2 - num1);
                        break;
                    case '*':
                        stk.push(num1 * num2);
                        break;
                    case '/':
                        stk.push(num2 / num1);
                        break; 
                }
            } else {
                stk.push(stoi(tokens[i]));      
            }
        }
        return stk.top();
    }
};
