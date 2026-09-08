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
        while (!students.empty() && r < (int)students.size()) {
            int front = students[0];
            students.erase(students.begin());
            if (front == st.top()) {
                st.pop();
                r = 0;
            } else {
                students.push_back(front);
                r++;
            }
        }
        return students.size();
    }
};