#include <iostream>
#include <vector>

using namespace std;

long long mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    long long inversionCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversionCount += mid - i + 1; // Count inversions
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; ++i) {
        arr[i] = temp[i];
    }

    return inversionCount;
}

long long mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
    long long inversionCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        inversionCount += mergeSortAndCount(arr, temp, left, mid);
        inversionCount += mergeSortAndCount(arr, temp, mid + 1, right);

        inversionCount += mergeAndCount(arr, temp, left, mid, right);
    }
    return inversionCount;
}

long long inversionCount(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp(n);
    return mergeSortAndCount(arr, temp, 0, n - 1);
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long result = inversionCount(arr);
    cout << "Inversion Count: " << result << endl;

    return 0;
}
