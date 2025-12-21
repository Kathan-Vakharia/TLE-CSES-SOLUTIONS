#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

//> Matrix Structure
template <int N>
struct Matrix {
    ll m[N][N];

    //> Identity Matrix
    static Matrix<N> identity() {
        Matrix<N> I{};
        for (int i = 0; i < N; i++)
            I.m[i][i] = 1;

        return I;
    }

    //> Matrix Multiplication: overload * operator
    Matrix<N> operator*(Matrix<N> b) {
        Matrix<N> r{};
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // Calculate r[i][j] = ith row * jth col
                for (int k = 0; k < N; k++) {
                    r.m[i][j] += m[i][k] * b.m[k][j];
                    r.m[i][j] %= M;
                }
            }
        }
        return r;
    }

    //> Matrix Exponentiation
    Matrix<N> power(ll b) {
        Matrix<N> r = identity();
        auto a = *this;
        while (b > 0) {
            if (b & 1)
                r = r * a;

            a = a * a;
            b >>= 1;
        }
        return r;
    }
};

int main() {
    ll n;
    cin >> n;

    Matrix<6> X{{{0, 1, 0, 0, 0, 0},
                 {0, 0, 1, 0, 0, 0},
                 {0, 0, 0, 1, 0, 0},
                 {0, 0, 0, 0, 1, 0},
                 {0, 0, 0, 0, 0, 1},
                 {1, 1, 1, 1, 1, 1}

    }};
    X = X.power(n);
    vector<ll> iv = {1, 1, 2, 4, 8, 16};
    ll res = 0;
    for (int i = 0; i < 6; i++) {
        res += X.m[0][i] * iv[i];
        res %= M;
    }
    cout << res << "\n";
    // Alternatively,
    // cout << X.power(n + 6).m[0][0] << "\n";
}  //* T: O(216*log(n)), S: O(1)