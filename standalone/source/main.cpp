#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <fmt/format.h>

#include "bigplus/BPScalar.hpp"
#include "bigplus/BPOperator.hpp"

auto main(int argc, char** argv) -> int {
    std::vector<bigplus::BPScalar> stack;

    while (true) {
        // Print
        for (auto& scalar : stack) {
            std::cout << scalar.to_string() << std::endl;
        }

        // Read
        std::cout << "bigplus> ";
        std::string buffer;
        std::getline(std::cin, buffer);
        
        // Evaluate
        if (std::cin.eof() || buffer == "exit") {
            break;
        }
        if (buffer == "") {
            continue;
        }
        if (buffer == "clear") {
            stack.clear();
            continue;
        }
        if (buffer == "pop") {
            stack.pop_back();
            continue;
        }
        
        if (bigplus::BPOperator::binaries.contains(buffer)) {
            if (stack.size() < 2) {
                std::cout << "Insufficient operands" << std::endl;
                continue;
            }
            bigplus::BPScalar op2 = stack.back();
            stack.pop_back();
            bigplus::BPScalar op1 = stack.back();
            stack.pop_back();
            try {
                stack.push_back(
                    bigplus::BPOperator::binaries.at(buffer)
                        (op1, op2));
            } catch (std::runtime_error ex) {
                std::cout << "Operation error: " << ex.what() << std::endl;
            }
            continue;
        }

        try {
            int64_t operand = std::stoll(buffer);
            stack.push_back(bigplus::BPScalar(operand));
        } catch (std::invalid_argument ex) {
            std::cout << "Bad input: " << ex.what() << std::endl;
        }
    }
}