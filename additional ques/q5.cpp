#include <bits/stdc++.h>
using namespace std;

bool canFit(long long S, long long N, long long W, long long H) {
    return (S / W) * (S / H) >= N;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        long long N, H, W;
        cin >> N >> H >> W;

        long long low = 0, high = max(W, H) * N;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canFit(mid, N, W, H)) {
                ans = mid;
                high = mid - 1;  // try smaller square
            } else {
                low = mid + 1;   // need bigger square
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
