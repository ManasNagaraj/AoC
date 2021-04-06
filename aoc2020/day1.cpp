#include <fstream>
#include <iostream>
#include <vector>
#include <string>

int SUM_REQUIRED = 2020;

std ::vector<int> dump_file()
{
    std ::vector<int> numbers;
    std ::fstream input_stream;
    std ::string line;

    input_stream.open("./data/day1.txt", ::std::ios_base::in);
    while (!input_stream.eof())
    {
        getline(input_stream, line);
        numbers.push_back(std::stoi(line));
    }

    return numbers;
}

int star_one(std::vector<int> &numbers)
{

    for (auto val1 : numbers)
    {
        for (auto val2 : numbers)
        {

            if ((val1 + val2) == 2020)
            {
                return val1 * val2;
            }
        }
    }
}

int star_two(std::vector<int> &numbers)
{

    for (auto val1 : numbers)
    {
        for (auto val2 : numbers)
        {
            for (auto val3 : numbers)
            {
                if ((val1 + val2 + val3) == 2020)
                {
                    return val1 * val2 * val3;
                }
            }
        }
    }
}

int main()
{

    std::vector<int> numbers = dump_file();

    int ans1 = star_one(numbers);
    int ans2 = star_two(numbers);
    std::cout << "Answer for the first star :" << ans1;
    std::cout << "\nAnswer for the second star :" << ans2;
    return 0;
}