#include <iostream>
#include <stack>

using namespace std;

int sumStack(stack<int>& A, stack<int>& B){
    int carry = 0;
    stack<int> result;
    
    while(!A.empty() || !B.empty() || carry){
        int sum = carry;
        
        if(!A.empty()){
            sum += A.top();
            A.pop();
        }
        if(!B.empty()){
            sum += B.top();
            B.pop();
        }
        
        result.push(sum % 10);
        carry = sum / 10;
    }
    
    while(!result.empty()){
        cout << result.top();
        result.pop();
    }
    
    return 0;
}

int main(){
    stack<int> A, B;
    string a, b;
    cin >> a;
    cin >> b;
    
    for(char c: a){
        A.push(c-'0');
    }

    for(char c: b){
        B.push(c-'0');
    }

    sumStack(A,B);

    return 0;
}