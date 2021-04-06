#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "parse.hpp"

std ::vector<std::string> dump_file()
{
    std ::vector<std::string> data;
    std ::fstream input_stream;
    std ::string line;

    input_stream.open("./data/day2.txt", ::std::ios_base::in);
    while (!input_stream.eof())

    {
        getline(input_stream, line);
        data.push_back(line);
    }

    return data;
}

int check_valid(std::vector<std::string> &data)
{

    for (auto val : data)
    {
        std::cout << val << "\n";
    }
    return 0;
}

int main()
{

    std::vector<std::string> data = dump_file();
    check_valid(data);
    return 0;
}