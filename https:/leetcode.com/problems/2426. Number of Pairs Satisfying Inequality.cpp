class Solution
{
    public:
        long long numberOfPairs(vector<int> &firstNums, vector<int> &secondNums, int diff)
        {
            for (int i = 0; i < firstNums.size(); i++)
                firstNums[i] -= secondNums[i];

            long long result = 0;
            mergeSort(firstNums, 0, firstNums.size() - 1, result, diff);
            return result;
        }

    void mergeSort(vector<int> &nums, int startIdx, int endIdx, long long &result, int diff)
    {
        if (startIdx >= endIdx) return;

        int midIdx = (startIdx + endIdx) / 2;
        mergeSort(nums, startIdx, midIdx, result, diff);
        mergeSort(nums, midIdx + 1, endIdx, result, diff);

        int index = startIdx;
        for (int k = midIdx + 1; k <= endIdx; k++)
        {
            while (index <= midIdx && nums[index] <= nums[k] + diff)
            {
                index++;
            }
            result += (index - startIdx);
        }

        inplace_merge(nums.begin() + startIdx, nums.begin() + midIdx + 1, nums.begin() + endIdx + 1);
    }
};