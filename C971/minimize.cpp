#include <iostream>

using namespace std;

int main() {
    int count;
    cin >> count;
    int x, y;
    while (count--) {
        cin >> x >> y;
        cout << y - x << endl;
    }
    return 0;
}
