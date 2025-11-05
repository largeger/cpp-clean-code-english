# Exercise – Recognising code smells

## Objective
In this exercise, you will learn to recognise and describe typical code smells.

## Task
Analyse the following C++ code.
It contains several code smells (e.g. overly long method, duplicated logic, magic numbers).

1. Describe the smells you find.
2. Suggest improvements.
3. Refactor the code to make it cleaner and more maintainable.

```cpp
#include <iostream>
#include <string>

void processOrder(std::string type, int quantity) {
    if (type == "A") {
        double price = 10.0 * quantity;
        if (quantity > 100) price *= 0.9;
        std::cout << "Order type A, total: " << price << std::endl;
    } else if (type == "B") {
        double price = 20.0 * quantity;
        if (quantity > 100) price *= 0.9;
        std::cout << "Order type B, total: " << price << std::endl;
    } else if (type == "C") {
        double price = 30.0 * quantity;
        if (quantity > 100) price *= 0.9;
        std::cout << "Order type C, total: " << price << std::endl;
    }
}

int main() {
    processOrder("A", 120);
}
```

---

### Notes
- Think about how you can improve structure, readability and expandability.
