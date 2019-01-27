#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<string, int> dict{ { "one", 0 }, { "two", 2 }, { "three", 3 } };
    cout << dict["two"] << endl;
    cout << dict["four"] << endl;

    for (const auto& v : dict) {
        cout << v.first << ": " << v.second << endl;
    }
}

