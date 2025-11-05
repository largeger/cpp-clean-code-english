#include <iostream>
#include <vector>
#include <memory>

/*
Explanation
Base Class (Animal):

The speak() method is declared virtual, making it polymorphic. This allows derived classes to provide their specific implementation.
The virtual destructor ~Animal() ensures that when an Animal pointer is deleted, the correct destructor for derived objects is called.
Derived Classes (Dog and Cat):

Both Dog and Cat override the speak() method to provide specific implementations.
Polymorphism in Action:

We create a std::vector of std::unique_ptr<Animal> to hold different Animal types.
Using animal->speak(), the correct overridden method is called based on the actual object type (Dog or Cat), demonstrating polymorphism.
*/

class Animal {
public:
    virtual void speak() const {
        std::cout << "Some generic animal sound!" << std::endl;
    }
    
    virtual ~Animal() = default;  // Virtual destructor for proper cleanup of derived objects
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Woof Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    // Using polymorphism: a vector of pointers to Animal, holding different derived types
    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back(std::make_unique<Dog>());
    animals.push_back(std::make_unique<Cat>());

    for (const auto& animal : animals) {
        animal->speak();  // Calls the appropriate speak() method based on the actual object type
    }

    return 0;
}
