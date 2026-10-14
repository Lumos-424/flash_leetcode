#include <iostream>
#include <vector>
using namespace std;

//同向快慢双指针
void movezero(vector<int> &nums){
    int j = 0;//下一个非零元素该放的位置
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != 0){
            swap(nums[i], nums[j]);
            ++j;
        }
    }
}

int main(){
    int n;
    while(cin >> n){
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        
        movezero(nums);
        cout << "[";
        for(int i = 0; i < n; i++){
            cout << nums[i];
        }
        cout << "]";
    }
    return 0;
}