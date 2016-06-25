class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    // Since x1 + x2 = target, we can in one loop 
    // mark both x1 and x2 in some additional array where we'll keep indices
    // Though to build that array we'd need another loop

    int min = nums[0], max = min;
    // first loop to find max and min integers
    for (int i = 0;i < nums.size();i++)
    {
        if (nums[i] < min)
            min = nums[i];
        if (nums[i] > max)
            max = nums[i];
    }
    // valid range for input integers relative to target
    int sMin;
    int sMax;
    if(min < target - max)
        sMin = min;
    else
        sMin = target - max;

    if(max > target - min)
        sMax = max;
    else
        sMax = target - min;

    // array to keep indices of valid input integers
    // initialize with -1
    int size = 1 + sMax - sMin;
    int arr[size];
    // for (int i = 0; i < arr.length;i++)
    //     arr[i] = -1;
    fill(arr,arr+size,-1);
    // second loop
    int offset = -sMin;
    for (int i = 0;i < nums.size();i++)
    {
        // Skip if integer is not from a valid range
        if (nums[i] > sMax || nums[i] < sMin)
            continue;
        // if found valid X1 and corresponding element of indices array is still -1
        // then mark its pair X2 = target - X1 in indices array
        if (arr[nums[i] + offset] == -1)
            arr[target-nums[i] + offset] = i;
        else
            return {arr[nums[i] + offset],i};
    }
    return {0,0};
}
};