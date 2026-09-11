class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0;
        int size = m;
        while (j < n) {
            int i = 0;
            while (i < size && nums1[i] <= nums2[j]) {
                i++;
            }
            nums1.insert(nums1.begin() + i, nums2[j]);
            nums1.pop_back();
            j++;
            size++;
        }
    }
};