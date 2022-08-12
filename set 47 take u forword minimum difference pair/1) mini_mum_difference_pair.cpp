

#include <bits/stdc++.h>

using namespace std;

int gDiff(vector<int> v) {
    int n = v.size();
    int diff = INT_MAX;
    sort(v.begin(), v.end());

    for (int i = 1; i < n; i++) {
        diff = min(diff, v[i] - v[i - 1]);
    }

    return diff;

}

int main()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];

    }

    cout << gDiff(v);

    return 0;
}
