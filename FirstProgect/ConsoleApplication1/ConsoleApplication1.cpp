#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
string to_ternary(unsigned int num) {
    string ternary;
    while (num > 0) {
        ternary += ((num % 3) + '0');
        num /= 3;
    }
    return ternary;
}

unsigned int sum_ternary(unsigned int num) {
    string ternary = to_ternary(num);
    return accumulate(ternary.begin(), ternary.end(), 0, [](int acc, char c) { return acc + (c - '0'); });
}

int main()
{
    unsigned int n, s = 0, tmp;
    cin >> n;
    for (unsigned int i = 0; i < n; i++)
    {
        cin >> tmp;
        s += sum_ternary(tmp);
    }
    cout << sum_ternary(s) << endl;
    return 0;
}