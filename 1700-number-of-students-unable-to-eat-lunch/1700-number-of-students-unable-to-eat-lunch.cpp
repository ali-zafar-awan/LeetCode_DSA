#include <stack>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> st;
        for (int i = sandwiches.size() - 1; i >= 0; i--){
            st.push(sandwiches[i]);
            }

        int r = 0;
        while (!students.empty() && r < students.size()) {
            int f = students[0];
            students.erase(students.begin());
            if (f == st.top()) {
                st.pop();
                r = 0;
            } else {
                students.push_back(f);
                r++;
            }
        }
        return students.size();
    }
};