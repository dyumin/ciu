#include <iostream>

static const int N = 5;

// quick union
int main()
{
    int i = 0, p = 0, q = 0, id[N] = {0};

    for (i = 0; i < N; i++)
        id[i] = i;

    while (std::cin >> p >> q)
    {
        for (i = p; i != id[i]; i = id[i])
            continue;

        int j = 0;
        for (j = q; j != id[j]; j = id[j])
            continue;

        if (i == j)
            continue;

        id[i] = j;

        std::cout << "\t" << p << "\t" << q << std::endl;
    }

    std::cout << std::endl;

    return 0;
}