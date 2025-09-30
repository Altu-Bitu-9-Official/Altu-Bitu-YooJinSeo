#include <iostream>
#include <vector>

#define MAX_SIZE 10000

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(MAX_SIZE);
    int front = MAX_SIZE/2, back = MAX_SIZE/2;  // 중간에서 시작

    string cmd;
    int x;

    while(n--){
        cin >> cmd;

        if(cmd == "push_front"){
            cin >> x;
            front = (front - 1 + MAX_SIZE) % MAX_SIZE;
            arr[front] = x;
        }
        else if(cmd =="push_back"){
            cin >> x;
            arr[back] = x;
            back = (back + 1) % MAX_SIZE;
        }
        else if(cmd =="pop_front"){
            if(front == back){
                cout << "-1\n";
            }
            else{
                cout << arr[front] << "\n";
                front = (front + 1) % MAX_SIZE;
            }
        }
        else if(cmd =="pop_back"){
            if(front == back){
                cout << "-1\n";
            }
            else{
                back = (back - 1 + MAX_SIZE) % MAX_SIZE;
                cout << arr[back] << "\n";
            }
        }
        else if(cmd=="size"){
            cout << (back - front + MAX_SIZE) % MAX_SIZE << "\n";
        }
        else if(cmd=="empty"){
            cout << (front == back ? 1 : 0) << "\n";
        }
        else if(cmd=="front"){
            if(front == back){
                cout << "-1\n";
            }
            else{
                cout << arr[front] << "\n";
            }
        }
        else if(cmd=="back"){
            if(front == back){
                cout << "-1\n";
            }
            else{
                cout << arr[(back - 1 + MAX_SIZE) % MAX_SIZE] << "\n";
            }
        }
    }

    return 0;
}