#include <array>
#include <iostream>

// weighted quick union with path compression by halving
// https://www.youtube.com/watch?v=DZKzDebT4gU - this dude says that you don't need 'weighted' version for good performance as long as you have path compression
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
            for (pRoot = id[p]; pRoot != id[pRoot]; pRoot = id[pRoot])
            {
                id[pRoot] = id[id[pRoot]]; // path compression
            }
            for (qRoot = id[q]; qRoot != id[qRoot]; qRoot = id[qRoot])
            {
                id[qRoot] = id[id[qRoot]]; // path compression
            }

            if (pRoot == qRoot)
            {
                std::cout << "already connected" << std::endl;
                continue;
            }

            // union scope
            {
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
        }

        std::cout << p << " - " << q << std::endl;
    }

    return 0;
}