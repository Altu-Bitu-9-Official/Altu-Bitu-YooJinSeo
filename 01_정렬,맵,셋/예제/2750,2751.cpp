#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> merged;

void merge(vector<int>& arr, int left, int mid, int right){
    int pl=left, pr=mid+1, idx=left;

    //merge
    while(pl <= mid && pr <= right){
        if(arr[pl]<arr[pr]){
            merged[idx++]=arr[pl++];
        } else{
            merged[idx++]=arr[pr++];
        }
    }

    //남은 원소 처리
    while(pl<=mid){
        merged[idx++]=arr[pl++];
    }
    while(pr<=right){
        merged[idx++]=arr[pr++];
    }

    //arr 배열로 옮기기
    for(int i=left; i<=right; i++){
        arr[i]=merged[i];
    }
}

void mergeSort(vector<int>& arr, int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

void bubbleSort(vector<int>& arr){ //vector<int>& arr: 주소를 불러옴
    int len = arr.size();

    for(int i=0; i<len-1; i++){ //len-1: 정렬되지 않은 원소 마지막 하나 남았을 경우 뺌(정렬완료)
        for(int j=0; j<len-1-i; j++){ //len-1-i: 정렬된 원소 수(i개) 뺌
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    merged.assign(n, 0);

    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    //bubbleSort(arr);
    //mergeSort(arr, 0, n-1);

    sort(arr.begin(), arr.end());


    for(int i=0; i<n; i++){
        cout << arr[i] << ' ';
    }

    return 0;
}