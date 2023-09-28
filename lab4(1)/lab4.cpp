
#include <iostream>
#include <vector>

int main()
{
    double factor = 1.247;
    std::vector<int> arr{ 5, 1, 4, 2, 8, 255, 64, 8, 74, 9, 6, 7, 5, 6, 2, 5, 8, 6 };
    //std::vector<int> arr{ 1,-1 };

    double step = arr.size();
    while (step > 1) {
        step /= factor;
        for (int i = 0; i + step < arr.size(); i++) {
            if (arr[i] > arr[i + step]) {
                std::swap(arr[i], arr[i + step]);
            }
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << "\n";
    }
}
