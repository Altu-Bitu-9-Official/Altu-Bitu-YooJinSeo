#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n;

    // 최대힙
    priority_queue<int> pq;

    // 최소힙
    priority_queue<int, vector<int>, greater<int>> min_heap;
    //             type   container    compare
    //혹은 pq.push(-x) -> -붙여서 출력

    while(n--){
        cin >> x;
        switch (x)
        {
        case 0:
            //삭제
            if(!pq.empty()){
                cout << pq.top() << "\n";
                pq.pop();
            } else{
                cout << 0 << "\n";
            }
            break;
        
        default:
            //삽입
            pq.push(x);
            break;
        }
    }
    return 0;
}