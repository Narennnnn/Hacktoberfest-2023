#include <iostream>
#include <algorithm>

void generatePermutations(std::string str)
{
    // Sort the string in lexicographic order
    std::sort(str.begin(), str.end());

    // Print the first permutation
    std::cout << str << std::endl;

    // Generate the remaining permutations
    while (std::next_permutation(str.begin(), str.end()))
    {
        std::cout << str << std::endl;
    }
}

int main()
{
    std::string input;
    std::cin >> input;

    std::cout << "Permutations in lexicographic order:" << std::endl;
    generatePermutations(input);

    return 0;
}
