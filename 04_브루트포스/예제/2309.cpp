#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int CNT = 9; //총 난쟁이의 수

void select(vector<int>& arr){
    int sum = 0;
    for(int i=0; i<CNT; i++){ //난쟁이 9명의 키 전체 합
        sum+=arr[i];
    }

    for(int i=0; i<CNT-1; i++){ //1번째 난쟁이
        for(int k=i+1; k<CNT; k++){ //2번째 난쟁이
            if(sum-(arr[i]+arr[k])==100){
                arr.erase(arr.begin()+k); //k번째 난쟁이부터 지워주기(큰쪽부터)
                arr.erase(arr.begin()+i);
                return; // 찾았으면 즉시 종료!
            }
        } 
        
    }

    return;
}

int main(){

    //입력
    vector<int> arr(CNT);
    for(int i=0; i<CNT; i++){
        cin >> arr[i];
    }

    //연산
    select(arr);
    sort(arr.begin(), arr.end());

    //출력
    for(auto it : arr){ //auto: 변수의 타입 자동으로 추론
        cout << it << "\n";
    }

    return 0;
}