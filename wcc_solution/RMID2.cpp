// https://www.spoj.com/problems/RMID2/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        // smaller half
        std::priority_queue<int> max_heap;
        // larger_half
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

        int n;
        scanf("%d", &n);

        if (n == 0)
            break;

        while (n != 0)
        {
            if (n == -1)
            {
                int result;
                if (max_heap.size() >= min_heap.size())
                {
                    result = max_heap.top();
                    max_heap.pop();
                }
                else
                {
                    result = min_heap.top();
                    min_heap.pop();
                }
                printf("%d\n", result);
            }
            else
            {
                int max_heap_size = max_heap.size();
                int min_heap_size = min_heap.size();

                if (max_heap_size == 0 && min_heap_size == 0)
                {
                    max_heap.push(n);
                }
                else if (max_heap_size == 0)
                {
                    int min_heap_top = min_heap.top();
                    if (n <= min_heap_top)
                    {
                        max_heap.push(n);
                    }
                    else
                    {
                        max_heap.push(min_heap_top);
                        min_heap.pop();
                        min_heap.push(n);
                    }
                }
                else if (min_heap_size == 0)
                {
                    int max_heap_top = max_heap.top();
                    if (n >= max_heap_top)
                    {
                        min_heap.push(n);
                    }
                    else
                    {
                        min_heap.push(max_heap_top);
                        max_heap.pop();
                        max_heap.push(n);
                    }
                }
                else
                {
                    int larger_half_minimum = min_heap.top();
                    int smaller_half_maximum = max_heap.top();
                    if (max_heap_size == min_heap_size)
                    {
                        if (n <= larger_half_minimum)
                            max_heap.push(n);
                        else
                            min_heap.push(n);
                    }
                    else
                    {
                        if (max_heap_size < min_heap_size)
                        {
                            if (n <= larger_half_minimum)
                                max_heap.push(n);
                            else
                            {
                                max_heap.push(larger_half_minimum);
                                min_heap.pop();
                                min_heap.push(n);
                            }
                        }
                        else
                        {
                            if (n > smaller_half_maximum)
                                min_heap.push(n);
                            else
                            {
                                min_heap.push(smaller_half_maximum);
                                max_heap.pop();
                                max_heap.push(n);
                            }
                        }
                    }
                }
            }
        scanf("%d", &n);
        }

    printf("\n");
    }

    return 0;
}
