// RayBruteFroce.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>
#include <tuple>

using binaryop_t = std::function<int(int, int)>;
using strbinaryop_t = std::pair<binaryop_t, std::string>;

using unaryop_t = std::function<int(int)>;
using strunaryop_t = std::tuple<unaryop_t, std::string, std::string>;

std::string findOpCombination(
    const std::vector<int> &nums,
    size_t i,
    const std::vector<strbinaryop_t> &ops,
    const std::vector<strunaryop_t> &uops,
    int current,
    int goal
)
{
    if (i == 0)
    {
        for (const strunaryop_t &strUOp1 : uops)
        {
            const unaryop_t &uop1 = std::get<0>(strUOp1);
            for (const strunaryop_t &strUOp2 : uops)
            {
                try
                {
                    const unaryop_t &uop2 = std::get<0>(strUOp2);
                    const std::string successStr = findOpCombination(
                        nums,
                        i + 1,
                        ops,
                        uops,
                        uop1(uop2(nums[i])),
                        goal
                    );
                    if (successStr != "") {
                        return std::get<1>(strUOp1) + std::get<1>(strUOp2) + std::to_string(nums[i]) + std::get<2>(strUOp2) + std::get<2>(strUOp1) + " " + successStr;
                    }
                }
                catch (const std::runtime_error &)
                {
                    // pass
                }
            }
        }
    }
    else
    {
        for (const strbinaryop_t &strOp : ops)
        {
            const binaryop_t &op = strOp.first;
            for (const strunaryop_t &strUOp1 : uops)
            {
                const unaryop_t &uop1 = std::get<0>(strUOp1);
                for (const strunaryop_t &strUOp2 : uops)
                {
                    const unaryop_t &uop2 = std::get<0>(strUOp2);
                    if (i == nums.size() - 1)
                    {
                        try
                        {
                            if (op(current, uop1(uop2(nums[i]))) == goal)
                            {
                                return strOp.second
                                    + " "
                                    + std::get<1>(strUOp1)
                                    + std::get<1>(strUOp2)
                                    + std::to_string(nums[i])
                                    + std::get<2>(strUOp2)
                                    + std::get<2>(strUOp1);
                            }
                        }
                        catch (const std::runtime_error &)
                        {
                            // pass
                        }
                    }
                    else
                    {
                        try
                        {
                            const std::string successStr = findOpCombination(
                                nums,
                                i + 1,
                                ops,
                                uops,
                                op(current, uop1(uop2(nums[i]))),
                                goal
                            );
                            if (successStr != "")
                            {
                                return strOp.second
                                    + " "
                                    + std::get<1>(strUOp1)
                                    + std::get<1>(strUOp2)
                                    + std::to_string(nums[i])
                                    + std::get<2>(strUOp2)
                                    + std::get<2>(strUOp1)
                                    + " "
                                    + successStr;
                            }
                        }
                        catch (const std::runtime_error &)
                        {
                            // pass
                        }
                    }
                }
            }
        }
    }
    return "";
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cerr << "Requires min and max numbers as arguments!" << '\n';
        return 1;
    }
    size_t min = std::stoi(argv[1]);
    size_t max = std::stoi(argv[2]);
    std::vector<strbinaryop_t> binaryOps = {
        { [](int a, int b) { return a + b; }, "+" }, // add
        { [](int a, int b) { return a - b; }, "-" }, // subtract
        { [](int a, int b) { return a * b; }, "*" }, // multiply
        // divide (enforced integer division)
        {
            [](int a, int b)
            {
                if (b == 0 || a % b != 0)
                {
                    throw std::runtime_error("integer division error");
                }
                return a / b;
            },
            "/"
        },
        // integer power
        {
            [](int base, int exp) {
                if (exp < 0) {
                    throw std::runtime_error("exp must be positive for integer power!");
                }
                int result = 1;
                while (exp)
                {
                    if (exp & 1)
                        result *= base;
                    exp >>= 1;
                    base *= base;
                }
                return result;
            },
            "**"
        }
    };
    std::vector<strunaryop_t> unaryOps = {
        { [](int n) { return n; }, "", "" }, // identity function
        // factorial
        {
            [](int n)
            {
                if (n < 0)
                {
                    throw std::runtime_error("cannot take factorial of a negative number");
                }
                else if (n > 12)
                {
                    throw std::runtime_error("to prevent overflow, 12 is the max factorial");
                }
                int ans = 1;
                for (int i = 2; i <= n; ++i)
                {
                    ans *= i;
                }
                return ans;
            },
            "",
            "!"
        },
        { [](int n) { return n * n; }, "", "^2" },  // square
        { [](int n) { return -n; }, "(-", ")" }       // negative
    };
    std::vector<int> numbers = { 3, 7, 5 };
    std::vector<int> oldNumbers = { 0, 3, 0 };

    for (size_t n = min; n <= max; ++n)
    {
        const std::string operationsStr = findOpCombination(numbers, 0, binaryOps, unaryOps, 0, static_cast<int>(n));
        if (operationsStr != "") {
            std::cout << operationsStr << " = " << n << '\n';
        }
    }
    return 0;
}