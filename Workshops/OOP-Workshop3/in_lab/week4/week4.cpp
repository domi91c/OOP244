#include <iostream>

using namespace std;
int main() {
    char str[100] = "\0";
    strcpy(str, "hi");
    strcpy(str, "hi");
    cout << str;
}

