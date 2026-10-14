#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 哈希表，一次遍历
vector<int> twosum(vector<int> & nums, int target){
    unordered_map<int, int> map; // 存的就是下标
    for(int i = 0; i < nums.size(); i++){
        int need = target - nums[i];
        if(map.count(need)){//计算该值存在的次数
            return {map[need], i};
        }
        map[nums[i]] = i;//构造键值对
    }
    return {};
}

int main(){
    int n;
    int target;
    vector<int> nums(n);
    
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cin >> target;
    

    vector<int> res = twosum(nums, target);
    cout << res[0] << res[1];
    return 0;
}

