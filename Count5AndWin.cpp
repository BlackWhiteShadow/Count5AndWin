/* 
Count5AndWin.cpp : Find and return number with higher frequency of five.
                   Return 0 if empty.
*/

#include <iostream>
#include <vector>

int getLuckiest(std::vector<int> arr) 
{
    if (arr.empty())
        return 0;
    int fives = 0, highestFives = 0, x = 0, position = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        x = arr[i];
        while (x)
        {
            if (abs(x) % 10 == 5)
                fives++;
            x /= 10;
        }

        if (fives > highestFives)
        {
            highestFives = fives;
            position = i;
        }
        else if (fives == highestFives)
        {
            if (arr[i] > arr[position])
                i = position;
            continue;
        }
        fives = 0;
    }

    int max = 0;
    if (highestFives == 0)
    {
        for(int i = 0; i < arr.size(); i++)
            if (arr[i] > max)
            {
                position = i;
                max = arr[i];
            }
    }

    return arr[position];
}

int main()
{
    std::cout << "Enter numbers (enter 'End' to finish): \n";
    int x;
    std::vector<int> arr;
    while (std::cin >> x)
    {
        if (std::cin.fail())
            break;
        arr.push_back(x);
    }
    std::cout << "Highest fives frequency in number: " << getLuckiest(arr);
}


