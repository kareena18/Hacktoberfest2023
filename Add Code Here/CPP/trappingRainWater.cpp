#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int left_max = 0, right_max = 0;
    int trapped_water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] > left_max) {
                left_max = height[left];
            } else {
                trapped_water += left_max - height[left];
            }
            left++;
        } else {
            if (height[right] > right_max) {
                right_max = height[right];
            } else {
                trapped_water += right_max - height[right];
            }
            right--;
        }
    }

    return trapped_water;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = trap(height);
    cout << "Trapped water: " << result << endl;
    return 0;
}
