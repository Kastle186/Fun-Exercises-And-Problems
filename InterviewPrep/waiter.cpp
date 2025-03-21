#include <iostream>
#include <algorithm>
#include <vector>
#include "tools/hackerrank.hpp"

std::vector<int> waiter(std::vector<int>, int);
std::vector<int> init_sieve(int);

void print_vec(std::vector<int> vec, std::string label)
{
    std::cout << label << ":";
    for (int elem : vec)
    {
        std::cout << " " << elem;
    }
    std::cout << std::endl;
}

int main(void)
{
    std::string first_multiple_input_temp;
    getline(std::cin, first_multiple_input_temp);

    std::vector<std::string> first_multiple_input =
        split(rtrim(first_multiple_input_temp));

    int n = std::stoi(first_multiple_input[0]);
    int q = std::stoi(first_multiple_input[1]);

    std::string number_temp_temp;
    std::getline(std::cin, number_temp_temp);

    std::vector<std::string> number_temp = split(rtrim(number_temp_temp));
    std::vector<int> number(n);

    for (int i = 0; i < n; i++)
    {
        int number_item = std::stoi(number_temp[i]);
        number[i] = number_item;
    }

    std::vector<int> result = waiter(number, q);

    for (size_t i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << std::endl;
    }

    return 0;
}

std::vector<int> waiter(std::vector<int> plates, int q)
{
    // To solve this problem, we iterate through the first q prime numbers from
    // our sieve. Then, iterate the plates list to check which ones are evenly
    // divisible by each of these primes. I tried deleting them as we added them
    // to the answers list to be more memory efficient, but stupid Hackerrank
    // trick explanation had a hidden detail that invalidated this optimization.
    //
    // So instead, we have to end up using an auxiliary list to move the plates
    // that are not divisible by the given prime, in a stack-like fashion.

    std::vector<int> sieve_of_erastothenes = init_sieve(q);
    std::vector<int> answers;
    std::vector<int> helper;

    for (int i = 0; i < q; i++)
    {
        int prime = sieve_of_erastothenes[i];

        for (int j = 0; j < plates.size(); j++)
        {
            int plate = plates[j];

            if (plate % prime == 0)
                answers.push_back(plate);
            else
            {
                // Another Hackerrank cheating detail. The last iteration has to
                // keep the remaining untouched plates in the same order, rather
                // than inverting them in a stack-like fashion...
                if (i == q - 1)
                    helper.push_back(plate);
                else
                    helper.emplace(helper.begin(), plate);
            }
        }

        plates = helper;
        helper.clear();
    }

    answers.insert(answers.end(), plates.begin(), plates.end());
    return answers;
}

std::vector<int> init_sieve(int num_primes)
{
    std::vector<int> sieve_of_erastothenes {2};

    // No need to try to go through the whole algorithm if we only need one prime.
    if (num_primes == 1)
        return sieve_of_erastothenes;

    // First, we create a list of flags to go crossing out the numbers we discover
    // are not prime. We can potentially be asked up to the 1200th prime number,
    // which is 9733. However, we will keep a counter to only process the amount
    // of primes we are requested for the sake of efficiency.

    int limit = 9733;
    std::vector<bool> prime(limit + 1, true);

    // We can do a small optimization here. We know that by definition, all even
    // numbers are not prime, as they are divisible by 2. So, we can skip them
    // entirely when creating our sieve.

    for (int i = 3, primes_count = 1; primes_count <= num_primes; i += 2)
    {
        if (!prime[i])
            continue;

        // For each prime number we find, we set all its multiples equal or greater
        // than its square as non-prime. Starting at its square is another small
        // optimization we can make, as by definition, all numbers less than this
        // square have already been passed and marked in previous iterations.

        for (int j = i * i; j <= limit; j += i)
            prime[j] = false;

        primes_count++;
    }

    // And finally, we transfer the results to our final sieve object.

    for (int k = 3, primes_count = 1; primes_count <= num_primes; k += 2)
    {
        if (!prime[k])
            continue;

        sieve_of_erastothenes.push_back(k);
        primes_count++;
    }

    return sieve_of_erastothenes;
}
