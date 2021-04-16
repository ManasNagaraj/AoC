#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>

const std::string expressions = "(\\d*)-(\\d*) ([a-z]): (\\w*)";

std::vector<std::string> get_params(const std::string input, const std::string expression)
{
    const std::regex reg_exp(expression);
    std::smatch matchex;

    std::regex_search(input, matchex, reg_exp);
    std::vector<std::string> params;
    for (auto param : matchex)
    {
        params.push_back(param);
        //std::cout << param << std::endl;
    }
    return params;
}

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

int check_valid_star_one(std::vector<std::string> data)
{
    unsigned int correctpass = 0;

    for (auto val : data)
    {

        const std::vector<std::string> params = get_params(val, expressions);

        const int low = std::stoi(params[1]);

        const int up = std::stoi(params[2]);
        const char symbol = params[3].at(0);
        int count = 0;
        const std::string passphrase = params[4];
        for (auto val : passphrase)
        {
            if (val == symbol)
            {
                count++;
            }
        }

        if (count <= up && count >= low)
        {
            correctpass++;
        }
    }
    return correctpass;
}

int check_valid_star_two(std::vector<std::string> data)
{
    unsigned int correctpass = 0;

    for (auto val : data)
    {

        const std::vector<std::string> params = get_params(val, expressions);

        const int low = std::stoi(params[1]) - 1;

        const int up = std::stoi(params[2]) - 1;
        const char symbol = params[3].at(0);

        const std::string passphrase = params[4];

        if (passphrase[low] == symbol || passphrase[up] == symbol)
        {
            if (passphrase[low] != passphrase[up])
            {
                correctpass++;
            }
        }
    }

    return correctpass;
}

int main()
{

    std::vector<std::string> data = dump_file();
    int correctpass = check_valid_star_one(data);
    int correctpass2 = check_valid_star_two(data);
    std::cout << "Answer for the First Star" << correctpass << std::endl;
    std::cout << "Answer for the Second Star" << correctpass2 << std::endl;
    return 0;
}