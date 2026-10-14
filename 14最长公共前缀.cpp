#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestcommon(vector<string>& strs){
    if(strs.empty()) return "";

    string ans;// 默认赋值为空字符串
    for(int i = 0; i < strs[0].size(); i++){
        char c = strs[0][i];//第一串的每个作为基准
        for(int j = 1; j < strs.size(); j++){
            if(i >= strs[j].size() || strs[j][i] != c){
                return ans;
            }
        }
        ans.push_back(c);
    }
    return ans;
}

int main(){
    vector<string> strs; //不知道数量
    string s;
    while(cin >> s){
        strs.push_back(s);
        if(cin.peek() == '\n') break;
    }
    string res = longestcommon(strs);
    if(res.empty()){
        cout <<"\" \" "<<endl;
    }else{
        cout <<"\"" + res + "\" "<<endl;  
    }
}