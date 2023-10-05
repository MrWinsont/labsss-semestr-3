#include <iostream>
#include <vector>

// сортировка вставками
int main()
{
	std::vector<int> arr = { 3,6,5,7,1,9,4,400,100,1000,-5,1354,1,34,1,45,51,5,1,5,135,31,5 };
	for (int i = 1; i < arr.size(); i++) {
		for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
			std::swap(arr[j], arr[j - 1]);
		}
	}

	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i]<<"\n";
	}
}
//n^2
