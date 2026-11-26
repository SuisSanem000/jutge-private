#include <vector>
using namespace std;

int number_of_rotations(const vector<int>& arr)
{
    int low = 0;
    int high = arr.size() - 1;
    while (arr[low] > arr[high]) {
        // find mid.
        int mid = (low + high) / 2;
        // decide which sub-array to continue with.
        if (arr[mid] > arr[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}
