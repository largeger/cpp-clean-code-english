# Exercise – Refactoring a long method

## Goal
A long, difficult-to-understand method should be broken down into smaller, clearly named methods.

## Task
The following code contains multiple responsibilities in one function.

1. Identify the logical sections.
2. Extract them into separate methods with meaningful names.
3. Goal: shorter, more readable and testable methods.

```cpp
#include <iostream>
#include <string>

class SalesReport {
public:
    void generate(const std::string& name, int sales, int refunds) {
        std::cout << "Generating report..." << std::endl;
        int netSales = sales - refunds;
        double commission = netSales * 0.1;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Sales: " << sales << ", Refunds: " << refunds << std::endl;
        std::cout << "Net: " << netSales << ", Commission: " << commission << std::endl;
        if (netSales > 1000)
            std::cout << "Excellent performance!" << std::endl;
        else
            std::cout << "Needs improvement." << std::endl;
    }
};

int main() {
    SalesReport().generate("Alice", 1500, 200);
}

```

---

### Notes
- Remember **single responsibility** per method.
- Consider how you can separate calculation and display.
