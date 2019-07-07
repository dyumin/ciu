#include <iostream>

static const int N = 5;

// quick find
int main()
{
    int i = 0, p = 0, q = 0, id[N] = {0};

    for (i = 0; i < N; i++)
        id[i] = i;

    while (std::cin >> p >> q)
    {
        const int t = id[p];

        if (t == id[q])
            continue;

        for (i = 0; i < N; i++)
        {
            if (id[i] == t)
                id[i] = id[q];
        }

        std::cout << "\t" << p << "\t" << q << std::endl;
    }

    std::cout << std::endl;

    return 0;
}