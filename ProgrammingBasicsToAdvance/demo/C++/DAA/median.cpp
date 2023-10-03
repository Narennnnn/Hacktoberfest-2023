#include <iostream>
#include <vector>
#include <algorithm>

std::string findMajorityElement(const std::vector<int> &arr)
{
    int count = 1;
    int majorityElement = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == majorityElement)
        {
            count++;
        }
        else
        {
            count--;
            if (count == 0)
            {
                majorityElement = arr[i];
                count = 1;
            }
        }
    }

    count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == majorityElement)
        {
            count++;
        }
    }

    if (count > arr.size() / 2)
    {
        return "yes";
    }
    else
    {
        return "no";
    }
}

double findMedian(const std::vector<int> &arr)
{
    int n = arr.size();
    if (n % 2 == 0)
    {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
    else
    {
        return arr[n / 2];
    }
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    std::sort(arr.begin(), arr.end());

    std::string majorityElementExist = findMajorityElement(arr);
    double median = findMedian(arr);

    std::cout << majorityElementExist << std::endl;
    std::cout << median << std::endl;

    return 0;
}
