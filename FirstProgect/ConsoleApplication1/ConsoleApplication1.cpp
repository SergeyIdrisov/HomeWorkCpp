#include <iostream>

using namespace std;

void decod(int n)
{
    int binary[32];
    int i = 0;
    while (n > 0) {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }
    string answer = "";
    for (int j = i - 1; j >= 0; j--) {
        if (binary[j] == 1) {
            answer += "1";
        }
    }
    for (int j = i - 1; j >= 0; j--) {
        if (binary[j] == 0) {
            answer += "0";
        }
    }
    cout << answer;
}
int main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << n << endl;
        return 0;
    }
    else {
        decod(n);
    }
}