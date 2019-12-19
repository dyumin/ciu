#include <array>
#include <iostream>

// quick find
// find  - O(1) (compare sets id's)
// union - O(n) for each pair
int main()
{
    using Array = std::array<size_t, 100>;
    Array id;
    for (Array::size_type i = 0; i < id.size(); ++i)
    {
        id[i] = i;
    }

    Array::value_type p = 0, q = 0;
    for (Array::size_type i = 0; i < id.size(); ++i)
    {
        std::cin >> p >> q;

        if (p >= id.size() || q >= id.size())
        {
            std::cout << "incorrect input" << std::endl;
            continue;
        }

        const Array::value_type pSetId = id[p];
        const Array::value_type qSetId = id[q];

        if (pSetId == qSetId)
        {
            std::cout << "already connected" << std::endl;
            continue;
        }

        for (auto& setId : id)
        {
            if (setId == pSetId)
            {
                setId = qSetId;
            }
        }

        std::cout << p << " - " << q << std::endl;
    }

    return 0;
}