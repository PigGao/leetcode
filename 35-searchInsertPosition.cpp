static const auto speedup = []() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
		int low = 0;
		int high = nums.size() - 1;
		//使用二分查找
		while (low <= high)
		{
			int mid = low + (high - low) / 2;
			if (nums[mid] < target) low = mid + 1;
            else if (nums[mid] > target) high = mid - 1;
			else return mid;
		}
		return low;
    }
};