#include <iostream>
#include <string>
#include <iomanip>

// --- ABSTRACTION & ENCAPSULATION BASE ---
class PaymentProcessor {
protected:
    std::string merchantId; // Accessible by child classes, hidden from outside

public:
    PaymentProcessor(std::string id) : merchantId(id) {}
    
    // Virtual destructor is mandatory for base classes to prevent memory leaks
    virtual ~PaymentProcessor() {}

    // Pure virtual function makes this an Abstract Class (Interface contract)
    virtual bool processPayment(double amount) = 0; 
};


// --- POLYMORPHISM: Form 1 (Credit Card) ---
class CreditCardProcessor : public PaymentProcessor {
private:
    // Encapsulation: Strict private access. Completely hidden from client code.
    std::string apiKey;

    bool connectToBank() {
        // Encapsulation: Internal helper method hidden from outside world
        std::cout << "Connecting securely to Credit Card Gateway..." << std::endl;
        return true;
    }

public:
    CreditCardProcessor(std::string id) 
        : PaymentProcessor(id), apiKey("secret_cc_gateway_key_123") {}

    // Polymorphic overriding of the base class method
    bool processPayment(double amount) override {
        if (connectToBank()) {
            std::cout << "Successfully charged $" << std::fixed << std::setprecision(2) 
                      << amount << " via Credit Card." << std::endl;
            return true;
        }
        return false;
    }
};


// --- POLYMORPHISM: Form 2 (PayPal) ---
class PayPalProcessor : public PaymentProcessor {
private:
    std::string paypalEmail; // Encapsulated private attribute

public:
    PayPalProcessor(std::string id, std::string email) 
        : PaymentProcessor(id), paypalEmail(email) {}

    // Polymorphic implementation with completely unique internal logic
    bool processPayment(double amount) override {
        std::cout << "Redirecting user to PayPal login for " << paypalEmail << "..." << std::endl;
        std::cout << "Successfully processed $" << std::fixed << std::setprecision(2) 
                  << amount << " via PayPal Express Checkout." << std::endl;
        return true;
    }
};


// --- DEMONSTRATION OF POLYMORPHISM ---
// This function relies strictly on the abstract base class pointer. 
// It doesn't know (or care) which specific processor is passed in.
void executeTransaction(PaymentProcessor* processor, double billAmount) {
    std::cout << "\n--- Initializing Transaction ---" << std::endl;
    
    // Runtime Polymorphism: Resolves to the correct method based on object type
    bool success = processor->processPayment(billAmount);
    
    if (success) {
        std::cout << "Transaction Complete. Receipt Sent." << std::endl;
    } else {
        std::cout << "Transaction Failed." << std::endl;
    }
}


// --- CLIENT CODE ---
int main() {
    // Instantiate specific polymorphic objects dynamically
    PaymentProcessor* ccProcessor = new CreditCardProcessor("M101");
    PaymentProcessor* paypalProcessor = new PayPalProcessor("M101", "shop@store.com");

    // Polymorphism in action: Passing different objects to the exact same routine
    executeTransaction(ccProcessor, 99.99);
    executeTransaction(paypalProcessor, 45.50);

    // Proof of Encapsulation:
    // Compiling the line below will throw a hard compilation error: "apiKey is private within this context"
    // ccProcessor->apiKey = "hacked_key"; 

    // Clean up dynamic memory
    delete ccProcessor;
    delete paypalProcessor;

    return 0;
}