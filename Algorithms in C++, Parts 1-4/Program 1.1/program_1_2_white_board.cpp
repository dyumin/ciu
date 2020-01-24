#include <array>
#include <iostream>

int main()
{
    using arT = std::array<int, 19>;
    arT conn;
    using vT = arT::value_type;
    using sT = arT::size_type;
    for (sT i = 0; i < conn.size(); i++)
        conn[i] = i;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (1)
    {
        sT f = 0, t = 0;
        std::cin >> f >> t;

        auto fEnd = conn[f];
        for (; fEnd != conn[fEnd]; fEnd = conn[fEnd]);
        auto tEnd = conn[t];
        for (; tEnd != conn[tEnd]; tEnd = conn[tEnd]);

        if (fEnd == tEnd)
        {
            std::cout << "already connected" << std::endl;
            continue;
        }

        conn[fEnd] = tEnd;
        std::cout << f << " - " << t << std::endl;
    }
#pragma clang diagnostic pop
    return 0;
}