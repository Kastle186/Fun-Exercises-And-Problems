// Name: 1352. Product of the Last K Numbers
// Topics: Array, Math, Design, Data Stream, Prefix Sum, Dynamic Programming

#include <iostream>
#include <vector>

class ProductOfNumbers
{
private:
    std::vector<int> products_dp;

public:
    ProductOfNumbers()
    {
        // Initialize the dynamic programming prefix product vector with 1, as that
        // is the product identity, or product of zero numbers.

        this->products_dp.push_back(1);
    }

    void add(int num)
    {
        // If we receive a zero, then all the previous products get invalidated,
        // as any number multiplied by zero is zero. So, we reset our prefix
        // vector back to the product identity.

        if (num == 0)
        {
            this->products_dp.clear();
            this->products_dp.push_back(1);
            return ;
        }

        // If the number is not zero, then add its product with the product of
        // the last obtained number.

        int last_prod = num * this->products_dp.back();
        this->products_dp.push_back(last_prod);
    }

    int get_product(int k)
    {
        // If our dynamic programming prefix product vector is smaller than the
        // last k products, then that means there was a zero at some point, and
        // therefore the answer is 0.

        if (this->products_dp.size() <= k)
            return 0;

        // Otherwise, we need to divide two numbers. Our dynamic programming
        // vector has the cumulative products. So to get the product of the
        // last k numbers, we have to take the product of all, and divide it
        // by the kth+1 number.

        size_t dp_len = this->products_dp.size();
        return this->products_dp.back() / this->products_dp.at(dp_len - 1 - k);
    }
};

// Tests Cases!

int main(void)
{
    ProductOfNumbers *prod_obj = new ProductOfNumbers();

    prod_obj->add(3);
    prod_obj->add(0);
    prod_obj->add(2);
    prod_obj->add(5);
    prod_obj->add(4);

    // Return 20. The product of the last 2 numbers is 5 * 4 = 20
    std::cout << prod_obj->get_product(2) << std::endl;

    // Return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
    std::cout << prod_obj->get_product(3) << std::endl;

    // Return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
    std::cout << prod_obj->get_product(4) << std::endl;

    prod_obj->add(8); // [3,0,2,5,4,8]

    // Return 32. The product of the last 2 numbers is 4 * 8 = 32
    std::cout << prod_obj->get_product(2) << std::endl;

    delete prod_obj;
    return 0;
}
