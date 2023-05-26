#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to perform Selection Sort using Greedy search
void selectionSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        // Find the index of the minimum element in the unsorted part of the array
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap the minimum element with the first element of the unsorted part
        swap(arr[i], arr[minIndex]);

        // Print the current step
        cout << "Step " << i + 1 << ": ";
        for (int num : arr)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> arr = {9, 5, 2, 7, 1, 8, 3};

    cout << "Original array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    // Perform Selection Sort
    selectionSort(arr);

    cout << "Sorted array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
