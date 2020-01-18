#include <array>
#include <iostream>

int main()
{
    using arrayType = std::array<int, 9>;
    arrayType connId;

    for (arrayType::size_type i = 0; i < connId.size(); i++)
    {
        connId[i] = i;
    }

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (1)
    {
        arrayType::value_type f = 0, t = 0;
        std::cin >> f >> t; // should check for bounds

        if (connId[f] == connId[t]) // find O(1)
        {
            std::cout << "already connected" << std::endl;
            continue;
        }

        using valT = arrayType::value_type;
        using sizeT = arrayType::size_type;

        const valT tId = connId[t];
        const valT fId = connId[f];

        { // union scope, O(n)
            for (sizeT i = 0; i < connId.size(); i++)
            {
                if (connId[i] == fId)
                    connId[i] = tId;
            }
        }

        std::cout << f << " - " << t << "\n";

    }
#pragma clang diagnostic pop
    return 0;
}