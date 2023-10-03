#include <iostream>
#include <vector>
#include <algorithm>

struct Item
{
    int weight;
    int value;
};

bool compare(Item item1, Item item2)
{
    double ratio1 = static_cast<double>(item1.value) / item1.weight;
    double ratio2 = static_cast<double>(item2.value) / item2.weight;
    return ratio1 > ratio2;
}

void fractionalKnapsack(std::vector<Item> &items, int capacity)
{
    std::sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    std::vector<double> fractions(items.size(), 0.0);

    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].weight <= capacity)
        {
            fractions[i] = 1.0;
            totalValue += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            fractions[i] = static_cast<double>(capacity) / items[i].weight;
            totalValue += fractions[i] * items[i].value;
            capacity = 0;
            break;
        }
    }

    std::cout << "Maximum value that can be achieved: " << totalValue << std::endl;
    std::cout << "List of selected items with their fractions: " << std::endl;
    for (int i = 0; i < items.size(); i++)
    {
        std::cout << "Item " << (i + 1) << ": Fraction = " << fractions[i] << std::endl;
    }
}

int main()
{
    int N;
    std::cin >> N;

    std::vector<Item> items(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> items[i].weight;
    }

    for (int i = 0; i < N; i++)
    {
        std::cin >> items[i].value;
    }

    int capacity;
    std::cin >> capacity;

    fractionalKnapsack(items, capacity);

    return 0;
}
