#include <iostream>
#include <memory>
#include <vector>

class PaymentMethod {
public:
    virtual ~PaymentMethod() = default;
    virtual void process() const = 0;
};

class CreditCardPayment : public PaymentMethod {
public:
    void process() const override {
        std::cout << "Processing credit card payment" << std::endl;
    }
};

class PayPalPayment : public PaymentMethod {
public:
    void process() const override {
        std::cout << "Processing PayPal payment" << std::endl;
    }
};

class BankTransferPayment : public PaymentMethod {
public:
    void process() const override {
        std::cout << "Processing bank transfer" << std::endl;
    }
};

class PaymentProcessor {
public:
    void addPayment(std::unique_ptr<PaymentMethod> method) {
        methods.push_back(std::move(method));
    }

    void processAll() const {
        for (const auto& m : methods) m->process();
    }

private:
    std::vector<std::unique_ptr<PaymentMethod>> methods;
};

int main() {
    PaymentProcessor processor;
    processor.addPayment(std::make_unique<CreditCardPayment>());
    processor.addPayment(std::make_unique<PayPalPayment>());
    processor.processAll();
}
