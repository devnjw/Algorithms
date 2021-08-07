#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, int> hsmap;

int solution(vector<int> nums)
{
    for(auto num : nums)
        hsmap.insert({num, 1});
    if(nums.size()/2 < hsmap.size()) return nums.size()/2;
    else return hsmap.size();
}
