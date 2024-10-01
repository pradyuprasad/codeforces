#include <iostream>
using namespace std;

int main(){
    int count;
    cin >> count;
    int ones, twos;
    for (int i = 0; i < count; i ++){
        cin >> ones >> twos;
        int sum = ones + twos*2;
        if (sum % 2 != 0){
            cout << "NO";
            continue;
        }
        int target = sum/2;
        int new_t = target;
        bool add_one = false;
        if (target % 2 != 0){
            new_t = target-1;
            add_one = true;
        }

        // check if we can make new_t only with 2s
        if (new_t <= twos*2){
            if (add_one) {
            }
        }
    }
}
