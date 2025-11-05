# Exercise – Applying SOLID principles

## Objective
In this exercise, you will fix a violation of the **Open/Closed Principle (OCP)**.

## Task
The following code violates the OCP because each new payment method changes the existing code.

1. Identify why the OCP is being violated.
2. Refactor the code so that new payment methods can be added **without** changing the existing logic.

```cpp
#include <iostream>
#include <string>

class PaymentProcessor {
public:
    void process(const std::string& type) {
        if (type == "creditcard") {
            std::cout << "Processing credit card payment" << std::endl;
        } else if (type == "paypal") {
            std::cout << "Processing PayPal payment" << std::endl;
        } else if (type == "bank") {
            std::cout << "Processing bank transfer" << std::endl;
        }
    }
};

int main() {
    PaymentProcessor p;
    p.process("paypal");
}
```

---

### Notes
- Consider how you can make the behaviour extensible using **polymorphism** or **interfaces**.
- Goal: The PaymentProcessor should be open for extensions but closed for modifications.
