#include <iostream>
#include <vector>
using namespace std;

vector<int> quickSortSimple(vector<int> arr) {

    if (arr.size() <= 1) {
        return arr;
    }

    int pivot = arr[0];
    vector<int> less, big;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] <= pivot) {
            less.push_back(arr[i]);
        }
        else {
            big.push_back(arr[i]);
        }
    }

    vector<int> result;
    vector<int> sortedLess = quickSortSimple(less);
    vector<int> sortedBig = quickSortSimple(big);

    result.insert(result.end(), sortedLess.begin(), sortedLess.end());
    result.push_back(pivot);
    result.insert(result.end(), sortedBig.begin(), sortedBig.end());

    return result;
}

int main() {

    setlocale(LC_ALL, "Russian");

    int n;
    cout << "¬ведите количество элементов в массиве: ";
    cin >> n;

    vector<int> arr(n);
   
    cout << "¬ведите " << n << " элементов массива:" << endl;
    for (int i = 0; i < n; i++) {
        int item;
        cin >> item;
        arr[i] = item;
    }

    cout << "\n»сходный массив: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    vector<int> sorted = quickSortSimple(arr);

    cout << "ќтсортированный массив: ";
    for (int num : sorted) cout << num << " ";
    cout << endl;

}