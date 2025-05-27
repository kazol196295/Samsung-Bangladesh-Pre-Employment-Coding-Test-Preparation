#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minTransportCost(vector<int>& camels) {
    sort(camels.begin(), camels.end());
    int totalCost = 0;
    int n = camels.size();

    while (n > 3) {
        int costWithLightest = camels[0] + 2 * camels[1] + camels[n - 1]; // 2nd lightest shuttles
        int costWithTwoLightest = 2 * camels[0] + camels[n - 2] + camels[n - 1]; // lightest shuttles

        totalCost += min(costWithLightest, costWithTwoLightest);
        n -= 2;
    }

    if (n == 3)
        totalCost += camels[0] + camels[1] + camels[2];
    else if (n == 2)
        totalCost += camels[1];
    else if (n == 1)
        totalCost += camels[0];

    return totalCost;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> camels(n);
        for (int i = 0; i < n; ++i) {
            cin >> camels[i];
        }
        cout << minTransportCost(camels) << endl;
    }
    return 0;
}
