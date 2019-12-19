#include <array>
#include <iostream>

// quick find
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

        const Array::value_type pValue = id[p];
        const Array::value_type qValue = id[q];

        if (pValue == qValue)
        {
            std::cout << "already connected" << std::endl;
            continue;
        }

        for (auto& setId : id)
        {
            if (setId == pValue)
            {
                setId = qValue;
            }
        }

        std::cout << p << " - " << q << std::endl;
    }

    return 0;
}