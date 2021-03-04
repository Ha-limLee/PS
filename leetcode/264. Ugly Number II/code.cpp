class Solution {
public:
    int nthUglyNumber(int n){
        vector<int> uglyNumbers(1, 1);
        int idxOf2 = 0;
        int idxOf3 = 0;
        int idxOf5 = 0;

        int cnt = 1;
        while (cnt != n){
            int temp = minOfThree(uglyNumbers[idxOf2] * 2, uglyNumbers[idxOf3] * 3, uglyNumbers[idxOf5] * 5);
            if (temp == uglyNumbers[idxOf2] * 2) idxOf2++;
            if (temp == uglyNumbers[idxOf3] * 3) idxOf3++;
            if (temp == uglyNumbers[idxOf5] * 5) idxOf5++;

            uglyNumbers.push_back(temp);
            ++cnt;
        }

        return uglyNumbers.back();
    }

    int minOfThree(int num1, int num2, int num3){
        int res;
        
        if (num1 < num2){
            if (num1 < num3) res = num1;
            else res = num3;
        }
        else
            res = num2 > num3 ? num3 : num2;
        
        return res;
    }
};