#include <stack>
class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int max =0, count=0;
        for(int i=0;i<s.size();i++){
            if (s[i]=='('){
                st.push(s[i]);
                count++;
            } else if (s[i]==')'){
                st.pop();
                if(count>max){
                    max=count;
                }
                count--;
            }
        }
        return max;
    }
};