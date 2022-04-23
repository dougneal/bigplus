#include <iostream>
#include <string>
#include <vector>
#include <math.h>

auto main(int argc, char** argv) -> int {
    // std::cout << "int64_t max: " << std::numeric_limits<int64_t>::max() << std::endl;

    std::vector<int64_t> stack;
    stack.push_back(0);

    while (true) {
        // Print
        for (int item : stack) {
            std::cout << item << std::endl;
        }

        // Read
        std::cout << "pancalc> ";
        std::string buffer;
        std::getline(std::cin, buffer);
        
        // Evaluate
        if (buffer == "exit") {
            break;
        }
        if (buffer == "clear") {
            stack.clear();
            stack.push_back(0);
            continue;
        }
        if (buffer == "pop") {
            stack.pop_back();
            if (stack.size() == 0) {
                stack.push_back(0);
            }
            continue;
        }
        if (buffer == "+") {
            if (stack.size() < 2) {
                std::cout << "Insufficient operands" << std::endl;
                continue;
            }
            int64_t op2 = stack.back();
            stack.pop_back();
            int64_t op1 = stack.back();
            stack.pop_back();
            int64_t result = op1 + op2;
            stack.push_back(result);
            continue;
        }
        
        if (buffer == "-") {
            if (stack.size() < 2) {
                std::cout << "Insufficient operands" << std::endl;
                continue;
            }
            int64_t op2 = stack.back();
            stack.pop_back();
            int64_t op1 = stack.back();
            stack.pop_back();
            int64_t result = op1 - op2;
            stack.push_back(result);
            continue;
        }

        if (buffer == "*") {
            if (stack.size() < 2) {
                std::cout << "Insufficient operands" << std::endl;
                continue;
            }
            int64_t op2 = stack.back();
            stack.pop_back();
            int64_t op1 = stack.back();
            stack.pop_back();
            int64_t result = op1 * op2;
            stack.push_back(result);
            continue;
        }

        if (buffer == "/") {
            if (stack.size() < 2) {
                std::cout << "Insufficient operands" << std::endl;
                continue;
            }
            int64_t op2 = stack.back();
            stack.pop_back();
            int64_t op1 = stack.back();
            stack.pop_back();
            int64_t result = op1 / op2;
            stack.push_back(result);
            continue;
        }

        if (buffer == "%") {
            if (stack.size() < 2) {
                std::cout << "Insufficient operands" << std::endl;
                continue;
            }
            int64_t op2 = stack.back();
            stack.pop_back();
            int64_t op1 = stack.back();
            stack.pop_back();
            int64_t result = op1 % op2;
            stack.push_back(result);
            continue;
        }

        if (buffer == "^") {
            if (stack.size() < 2) {
                std::cout << "Insufficient operands" << std::endl;
                continue;
            }
            int64_t op2 = stack.back();
            stack.pop_back();
            int64_t op1 = stack.back();
            stack.pop_back();
            int64_t result = pow(op1, op2);
            stack.push_back(result);
            continue;
        }

        try {
            int64_t operand = std::stoll(buffer);
            stack.push_back(operand);
        } catch (std::invalid_argument ex) {
            std::cout << "Bad input: " << ex.what() << std::endl;
        }
    }
}