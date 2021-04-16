#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std ::vector<std::string> dump_file()
{
    std ::vector<std::string> data;
    std ::fstream input_stream;
    std ::string line;

    input_stream.open("./data/day3.txt", ::std::ios_base::in);
    while (!input_stream.eof())

    {
        getline(input_stream, line);

        data.push_back(line);
    }

    return data;
}

int slope(std::vector<std::string> data, int right_speed, int down_speed)
{
    unsigned int count = 0;

    int width = data[0].length() - 1;
    int column_counter = 0;
    for (int row = 0; row < data.size(); row += down_speed)
    {

        if (data[row][column_counter % width] == '#')
        {

            count++;
        }

        column_counter += right_speed;
    }

    return count;
}

unsigned int solve_second_star(std::vector<std::string> data, const int speed_set[5][2])
{
    unsigned int multiple = 1;
    for (int i = 0; i < 5; i++)
    {

        multiple *= slope(data, speed_set[i][0], speed_set[i][1]);
    }
    return multiple;
}

int main()
{
    std::vector<std::string> data = dump_file();
    int ans = slope(data, 1, 2);
    int speed_set[5][2] = {{1, 1}, {3, 1}, {5, 1}, {7, 1}, {1, 2}};
    unsigned int ans2 = solve_second_star(data, speed_set);
    std::cout << "Answer to the First Star :" << ans << std::endl;

    std::cout << "Answer to the Second Star :" << ans2 << std::endl;
    return 0;
}
