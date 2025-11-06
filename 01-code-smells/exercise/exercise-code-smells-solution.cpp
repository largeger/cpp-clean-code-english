#include <iostream>
#include <string>
#include <unordered_map>

class OrderProcessor {
public:
    void process(const std::string& type, int quantity) {
        double price = getBasePrice(type) * quantity;
        price = applyDiscount(price, quantity);
        std::cout << "Order type " << type << ", total: " << price << std::endl;
    }

private:
    double getBasePrice(const std::string& type) {
        static std::unordered_map<std::string, double> prices = {{"A", 10.0}, {"B", 20.0}, {"C", 30.0}};
        return prices[type];
    }

    double applyDiscount(double price, int quantity) {
        const int DISCOUNT_THRESHOLD = 100;
        const double DISCOUNT_RATE = 0.9;
        return quantity > DISCOUNT_THRESHOLD ? price * DISCOUNT_RATE : price;
    }
};

int main() {
    OrderProcessor().process("A", 120);
}
