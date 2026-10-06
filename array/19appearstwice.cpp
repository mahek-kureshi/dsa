//Brute force solution to find the number that appears once and the others twice

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 1, 2, 3, 3, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = -1;

    for (int i = 0; i < n; i++) {
        int counter = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                counter++;
            }
        }
        if (counter == 1) {
            ans = arr[i];
            break;
        }
    }

    if (ans != -1)
        cout << "Element appearing once: " << ans << endl;
    else
        cout << "No unique element found" << endl;

    return 0;
}
