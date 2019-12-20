#include <array>
#include <iostream>

// quick union (well, not so quick actually, because first we need to do 'find')
// find  - O(1) best case
//       - O(n) worst case
// union - O(1)
int main()
{
    using Array = std::array<size_t, 5>;
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

        Array::value_type pRoot = 0, qRoot = 0;
        // find scope
        {
            for (pRoot = id[p]; pRoot != id[pRoot]; pRoot = id[pRoot]);
            for (qRoot = id[q]; qRoot != id[qRoot]; qRoot = id[qRoot]);

            if (pRoot == qRoot)
            {
                std::cout << "already connected" << std::endl;
                continue;
            }
        }

        // union scope
        {
            id[pRoot] = qRoot;
        }

        std::cout << p << " - " << q << std::endl;
    }

    return 0;
}