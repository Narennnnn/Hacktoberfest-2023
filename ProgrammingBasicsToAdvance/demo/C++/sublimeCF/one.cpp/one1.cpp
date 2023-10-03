/*
2
3
1 1 1
5
4 2 3 3 6*/
#include <iostream
#include <vector>
#include <stack>

using namespace std;

vector<int> findSpans(vector<int> &price)
{
    int n = price.size();
    vector<int> spans(n + 1, 1);
    stack<int> st;

    for (int i = 1; i < n + 1; i++)
    {
        while (!st.empty() && price[i] < price[st.top()] || st.empty())
        {
            spans[i] = i - st.top() + 1;
            st.pop();
        }
        st.push(i);
    }

    return spans;
}

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        std::vector<int> price(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> price[i];
        }

        std::vector<int> spans = findSpans(price);

        // Print the spans
        for (int i = 0; i < n; i++)
        {
            std::cout << spans[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
