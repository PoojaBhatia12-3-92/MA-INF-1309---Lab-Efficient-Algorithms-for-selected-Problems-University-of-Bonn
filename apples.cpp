#include <iostream>
#include <cmath>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;


pair<long long, pair<long long, long long>> extendedEuclideanAlgorithm(long long a, long long b) {
    long long aa = 1, ab = 0, ba = 0, bb = 1;
    while (true){
        int q = a / b;
        if (a == b * q) {
            return make_pair(b, make_pair(ba, bb));
        }
        long long tmp_a = a;
        long long tmp_aa = aa;
        long long tmp_ab = ab;
        a = b;
        b = tmp_a - b * q;
        aa = ba;
        ab = bb;
        ba = tmp_aa - ba * q;
        bb = tmp_ab - bb * q;
    }
}

bool solveEquation(long long a, long long b, long long c, pair<long long, pair<long long, long long>> &sol){
    pair<long long, pair<long long, long long>> solution = extendedEuclideanAlgorithm(a, b);
    long long gcd = solution.first;
    if (c % gcd != 0 || a + b > c) {
        return false;
    } else {
        c /= gcd;

        long long x = solution.second.first * c;
        long long y = solution.second.second * c;
        sol = make_pair(gcd, make_pair(x, y));
        return true;
    }
}


void solve(long long ca, long long cb, long long a, long long b, long long c){
    pair<long long, pair<long long, long long>> solution_total;

    if (!solveEquation(a, b, c, solution_total)) {
        cout << "failed" << endl;
    } else {

        long long x = solution_total.second.first;
        long long y = solution_total.second.second;
        long long gcd = solution_total.first;

        a = lround(a/gcd);
        b = lround(b/gcd);

        long long check = ca * b - cb * a;

        double t_1 = 0.0;
        long long y_a = floor(y / (a * 1.00));
        long long x_b = ceil(x / (b * 1.00)) * (-1);

        if (check < 0) {
            t_1 = y_a;
        } else {
            t_1 = x_b;
        }

        long long final_x = (x + b * t_1);
        long long final_y = (y - a * t_1);
        int curr_result = final_x * ca + final_y * cb;


        if (final_x < 0 || final_y < 0) {
            if (t_1 == y_a){
                final_x = (x + b * (t_1 - 1));
                final_y = (y - a * (t_1 - 1));
                curr_result = final_x * ca + final_y * cb;
            } else {
                final_x = (x + b * (t_1 + 1));
                final_y = (y - a * (t_1 + 1));
                curr_result = final_x * ca + final_y * cb;
            }
        }

        if (final_x < 0 || final_y < 0){
            cout << "failed" << endl;
            return;
        }
        cout << final_x << " " << final_y << endl;

    }
}


int main() {

    int flag=1;
    while (flag != 0) {
        cin >> flag;
        if (flag != 0) {
            long long c = flag;
            long long ca, a, cb, b;
            cin >> ca >> a >> cb >> b;
            solve(ca, cb, a, b, c);
        }
    }
    return 0;
}
