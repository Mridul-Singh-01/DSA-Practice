#include <string>
#include <vector>
#include<algorithm> 
#include <iostream>
class Solution {
public:
    static bool myCompare(const std::string& X, const std::string& Y)
    {
        std::string XY = X + Y;
        std::string YX = Y + X;
        return XY > YX;
    }
    std::string largestNumber(std::vector<int>& nums) {
        std::vector<std::string> str;
        for(int i = 0; i < nums.size(); i++){
            str.push_back(std::to_string(nums[i]));
        }
        std::sort(str.begin(), str.end(), myCompare);
        if (str[0] == "0") {
            return "0";
        }
        std::string ans;
        for(int i = 0; i < str.size(); i++){
            ans += str[i];
        }
        return ans;
    }
};

int main(){
    Solution solution;
    std::vector<int> arr = {10, 30, 20, 4};
    std::cout << "Largest Number formed is :";
    std::cout << solution.largestNumber(arr);
    return 0;
}