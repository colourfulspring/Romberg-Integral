#include <bits/stdc++.h>
#define M 100

using namespace std;

long double f(long double x) { return log(x); }

int main() {
    long double a, b, e;
    vector<vector<long double>> R;
    vector<long double> h(1, 0.0);
    R.resize(M);
    for (auto &c : R) {
        c.resize(M, 0.0);
    }
    cin >> a >> b >> e;
    h.emplace_back(b - a);
    R[1][1] = (f(a) + f(b)) * h[1] / (long double)2.0;
    int k;
    for (k = 2; k < 100; ++k) {
        h.emplace_back(h.back() / (long double)2.0);
        long double sum = 0.0;
        for (int i = 1; i <= (1 << (k - 2)); ++i) {
            sum += f(a + (2 * i - 1) * h[k]);
        }
        R[k][1] = (R[k - 1][1] + h[k - 1] * sum) / (long double)2.0;
        for (int j = 2; j <= k; ++j) {
            R[k][j] = R[k][j - 1] + (R[k][j - 1] - R[k - 1][j - 1]) /
                                        (long double)((1 << (2 * j - 2)) - 1);
        }
        if (abs(R[k][k] - R[k - 1][k - 1]) < e) {
            break;
        }
    }
    cout.precision(15);
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << R[i][j] << ' ';
        }
        cout << endl;
    }
    cout << 2 * log((long double)2) - 1 << endl;
}