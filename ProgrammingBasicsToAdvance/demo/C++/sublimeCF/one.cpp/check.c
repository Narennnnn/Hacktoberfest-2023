#include <stdio.h>

int main()
{
    int n, i, price;
    scanf("%d", &n);
    int spans[n + 1];
    for (i = 0; i <= n; i++)
    {
        spans[i] = 1;
    }
    stack<int> st;
    for (i = 1; i <= n; i++)
    {
        while (!st.empty() && price[i] < price[st.top()] || st.empty())
        {
            spans[i] = i - st.top() + 1;
            st.pop();
        }
        st.push(i);
    }
    for (i = 1; i <= n; i++)
    {
        printf("%d ", spans[i]);
    }
    printf("\n");
    return 0;
}
