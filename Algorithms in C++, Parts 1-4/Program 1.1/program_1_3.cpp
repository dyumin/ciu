#include <array>
#include <iostream>

// weighted quick union
int main()
{
    using Array = std::array<size_t, 5>;
    Array id, sz;
    for (Array::size_type i = 0; i < id.size(); ++i)
    {
        id[i] = i;
        sz[i] = 1;
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

            if (sz[pRoot] > sz[qRoot])
            {
                id[qRoot] = pRoot;
                sz[pRoot] += sz[qRoot];
            }
            else
            {
                id[pRoot] = qRoot;
                sz[qRoot] += sz[pRoot];
            }
        }

        std::cout << p << " - " << q << std::endl;
    }

    return 0;
}