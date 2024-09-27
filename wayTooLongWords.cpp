#include <iostream>
#include <string>

using namespace std;

int main(){
    int w;
    cin >> w;
    string s;
    for (int i = 0; i < w; i++){
        cin >> s;
        if (s.length() > 10){
            cout << s[0] << s.length()-2 << s[s.length() - 1]  << endl;
        } else {
            cout << s << endl;
        }

    }

    return 0;
}
