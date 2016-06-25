class NumArray {
private:
    vector<int> data;

public:
    NumArray(vector<int> &nums) : data(nums) {
        for(int i = 1; i < nums.size(); i++)
            data[i] = data[i-1] + nums[i];
    }

    int sumRange(int i, int j) {
        if(i == 0)
            return data[j];
        
        return data[j]-data[i-1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);