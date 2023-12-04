﻿#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void HashFunc(std::string str, std::vector<std::string>& table) {
    int sum = 0;
    for (int i = 0; i < str.size(); ++i) {
        sum += (int)(char)str[i];
    }
    int j = sum % table.size();
    if (table[j] == "") {
        table[j] = str;
    }
    else {
        while (table[j] != "") {
            ++j;
        }
        table[j] = str;
    }
}

int main()
{
    std::string path = "file1.txt";
    std::ifstream in;
    in.open(path);
    std::string tmp;
    std::vector <std::string> splited_text;
    if (in.is_open()) {
        
        while (!in.eof()) {
            in >> tmp;
            splited_text.push_back(tmp);
        }
    }
    int n = splited_text.size();

    std::vector <std::string> table(2 * n);

    for (int i = 0; i < splited_text.size(); ++i) {
        HashFunc(splited_text[i], table);
    }
    
    in.close();

    std::ofstream out;
    out.open(path, std::ios_base::app);

    if (out.is_open()) {
        for (int i = 0; i < table.size(); ++i) {
            out << "\n" << i << ": " << table[i];
        }
    }
    out.close();


}

