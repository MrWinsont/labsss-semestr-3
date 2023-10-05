
#include <iostream>
#include <vector>
//сортировка посредством выбора
int main()
{
    std::vector <int> arr = { 1,3,1,3,34,4,31,4,0,4,1,4,1,4,56,5,32,25,424,13,1,3,43532,141,78 };

    int min_pos;

    for (int i = 0; i < arr.size(); i++) {
        min_pos = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[min_pos]) {
                min_pos = j;
            }
        }
        std::swap(arr[i], arr[min_pos]);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << "\n";
    }
}
//n^2
