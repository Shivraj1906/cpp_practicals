#include<iostream>

using namespace std;

long long int factorial(int n) {
    long long int answer = 1;

    for(int i = 1; i <= n; i++)
        answer *= i;

    return answer;
}

int main() {
    int n;

    cout << "Enter the number: ";
    cin >> n;

    cout << "FACTORIAL: " << factorial(n) << endl;
    return 0;
}