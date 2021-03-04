class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int nums_size = nums.size();
        int* stack_begin = new int[k];
        int* stack_end = stack_begin;
        int stack_size = 0;
        
        for (int i = 0; i < nums_size; ++i){
            int remain = nums_size-i;
            while (stack_size != 0 && *(stack_end-1) > nums[i]){
                if (k-stack_size == remain)
                    break;
                --stack_end;
                --stack_size;
            }
            if (stack_size != k){
                *stack_end++ = nums[i];
                ++stack_size;
            }
        }
        return vector<int>(stack_begin, stack_end);
    }
};