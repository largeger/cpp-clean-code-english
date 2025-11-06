#include <iostream>
#include <string>

class SalesReport {
public:
    void generate(const std::string& name, int sales, int refunds) {
        std::cout << "Generating report..." << std::endl;
        int net = calculateNetSales(sales, refunds);
        double commission = calculateCommission(net);
        printSummary(name, sales, refunds, net, commission);
        printPerformance(net);
    }

private:
    int calculateNetSales(int sales, int refunds) {
        return sales - refunds;
    }

    double calculateCommission(int netSales) {
        return netSales * 0.1;
    }

    void printSummary(const std::string& name, int sales, int refunds, int net, double commission) {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Sales: " << sales << ", Refunds: " << refunds << std::endl;
        std::cout << "Net: " << net << ", Commission: " << commission << std::endl;
    }

    void printPerformance(int netSales) {
        if (netSales > 1000)
            std::cout << "Excellent performance!" << std::endl;
        else
            std::cout << "Needs improvement." << std::endl;
    }
};

int main() {
    SalesReport().generate("Alice", 1500, 200);
}
