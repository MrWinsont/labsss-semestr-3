#include <iostream>
#include <vector>
#include <string> 

//Radix sort
int main()

{
    std::vector<int> arr = { 1371051570, 395739293, 290561035, 5, 276, 42 ,313,10340,1,401440,0};
    std::vector<std::vector<int>> bins(10);
    
    int max_num = 0;
    int tmp;

    for (int i = 0; i < arr.size(); i++) {
        tmp = (std::to_string(arr[i])).length();
        if (max_num < tmp)
        max_num = (std::to_string(arr[i])).length();
    }

    int base = 10;
    
    for (int i = 0; i < max_num; i++) {
        for (int j = 0; j < arr.size(); j++) {
           int digit = static_cast<int>(arr[j] / pow(base, i)) % base;

           bins[digit].push_back(arr[j]);
        }
        int d = 0;
        for (int k = 0; k < bins.size(); k++) {
            for (int l = 0; l < bins[k].size(); l++) {

                if (!bins[k].empty()) {
                    arr[d] = bins[k][l];
                    d++;
                }
            }
        }

        for (int i = 0; i < 10; i++) {
            bins[i] = {};
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << "\n";
    }

}



