#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

class User {
protected:
    std::string name;
    std::string contact;

public:
    User(std::string n, std::string c): name(n), contact(c) {}
    virtual void displayInfo() = 0; // Abstract method
};

class Customer : public User {
public:
    Customer(std::string n, std::string c): User(n, c) {}

    void displayInfo() override {
        std::cout << "Customer Name: " << name << ", Contact: " << contact << std::endl;
    }
};

class Organizer : public User {
public:
    Organizer(std::string n, std::string c): User(n, c) {}

    void displayInfo() override {
        std::cout << "Organizer Name: " << name << ", Contact: " << contact << std::endl;
    }
};

class Event {
private:
    std::string eventName;
    std::string date;
    std::string location;

public:
    Event(std::string name, std::string d, std::string loc) : eventName(name), date(d), location(loc) {}

    void displayEvent() {
        std::cout << "Event: " << eventName << ", Date: " << date << ", Location: " << location << std::endl;
    }
};

class Ticket {
private:
    Event event;
    double price;
    bool available;

public:
    Ticket(Event e, double p) : event(e), price(p), available(true) {}

    void sellTicket() {
        if (available) {
            available = false;
            std::cout << "Ticket sold for event: " << std::endl;
            event.displayEvent();
        }
        else {
            std::cout << "Ticket not available!" << std::endl;
        }
    }

    void returnTicket() {
        available = true;
        std::cout << "Ticket returned!" << std::endl;
    }
};

class FileManager {
public:
    static void saveCustomerData(const std::vector<Customer>& customers) {
        std::ofstream outFile("customers.txt");
        if (!outFile) {
            throw std::runtime_error("Unable to open file for writing.");
        }

        for (const auto& cust : customers) {

        }

        outFile.close();
    }

    static void loadCustomerData(std::vector<Customer>& customers) {
        std::ifstream inFile("customers.txt");
        if (!inFile) {
            throw std::runtime_error("Unable to open file for reading.");
        }

        std::string line;
        while (std::getline(inFile, line)) {
            size_t pos = line.find(',');
            std::string name = line.substr(0, pos);
            std::string contact = line.substr(pos + 1);
            customers.push_back(Customer(name, contact));
        }

        inFile.close();
    }
};

int main() {
    std::vector<Customer> customers;
    try {
        FileManager::loadCustomerData(customers);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    Organizer org("Alice", "123-456-7890");
    Event event("C++, OOP Workshop", "2023-10-15", "Conference Hall");
    Ticket ticket(event, 20.0);

    org.displayInfo();
    event.displayEvent();

    ticket.sellTicket();
    ticket.returnTicket();

    try {
        FileManager::saveCustomerData(customers);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}