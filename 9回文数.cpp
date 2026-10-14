#include <iostream>
using namespace std;

// 12321, 134431
bool isPalindrome(int x){
    if(x < 0) return false;
    if(x % 10 == 0 && x != 0) return false;

    int rev = 0;
    while(x > rev){
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return x == rev || x == rev /10;
}

int main(){
    int x;
    cin >> x;
    if(isPalindrome(x)){
        cout << "true";
    }else{
        cout << "false";
    }
    return 0;
}