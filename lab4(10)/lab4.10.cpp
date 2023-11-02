﻿#include <iostream>
#include <vector>
//MergeSort
void MergeSort(std::vector<int> &a, size_t start, size_t end) {
	if (end - start <2) {
		return;
	}
	if (end - start == 2) {
		if (a[start] > a[start+1]) {
			std::swap(a[start], a[start + 1]);
		}
		return;
	}
	MergeSort(a, start, start + (end-start)/2);
	MergeSort(a, start + ((end-start) / 2), end);

	std::vector <int> temp;

	size_t b1 = start;
	size_t e1 = start + (end - start) / 2;
	size_t b2 = e1;

	
	for( ; temp.size() < (end - start) ; ){
		if ((b1 >= e1) || ((b2 < end)  && (a[b2] < a[b1]))) {
			temp.push_back(a[b2]);
			++b2;
		}

		else {
			temp.push_back(a[b1]);
			++b1;
		}
	}

	for (size_t i = start; i < end; i++) {
		a[i] = temp[i - start];
	}
}

int main()
{
	std::vector<int> arr = { 1,532,13,6,13,414,53,98,800,1000,-800 };

	MergeSort(arr, 0, arr.size());

	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << "\n";
	}
}


//nlog(n)
