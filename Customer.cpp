#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Customer {
    string name;
    string email;
    string phone;
};

vector<Customer> customers;

void displayMenu() {
    cout << "===== Customer Management System =====" << endl;
    cout << "1. Add Customer" << endl;
    cout << "2. View Customers" << endl;
    cout << "3. Update Customer" << endl;
    cout << "4. Delete Customer" << endl;
    cout << "5. Exit" << endl;
    cout << "=====================================" << endl;
    cout << "Enter your choice: ";
}

void addCustomer() {
    Customer customer;
    cout << "Enter customer name: ";
    cin.ignore();
    getline(cin, customer.name);
    cout << "Enter customer email: ";
    getline(cin, customer.email);
    cout << "Enter customer phone: ";
    getline(cin, customer.phone);
    customers.push_back(customer);
    cout << "Customer added successfully!" << endl;
}

void viewCustomers() {
    if (customers.empty()) {
        cout << "No customers found!" << endl;
        return;
    }
    cout << "===== Customer List =====" << endl;
    for (const auto& customer : customers) {
        cout << "Name: " << customer.name << endl;
        cout << "Email: " << customer.email << endl;
        cout << "Phone: " << customer.phone << endl;
        cout << "-------------------------" << endl;
    }
}

void updateCustomer() {
    if (customers.empty()) {
        cout << "No customers found!" << endl;
        return;
    }
    string email;
    cout << "Enter customer email to update: ";
    cin.ignore();
    getline(cin, email);
    for (auto& customer : customers) {
        if (customer.email == email) {
            cout << "Enter new name: ";
            getline(cin, customer.name);
            cout << "Enter new email: ";
            getline(cin, customer.email);
            cout << "Enter new phone: ";
            getline(cin, customer.phone);
            cout << "Customer updated successfully!" << endl;
            return;
        }
    }
    cout << "Customer not found!" << endl;
}

void deleteCustomer() {
    if (customers.empty()) {
        cout << "No customers found!" << endl;
        return;
    }
    string email;
    cout << "Enter customer email to delete: ";
    cin.ignore();
    getline(cin, email);
    for (auto it = customers.begin(); it != customers.end(); ++it) {
        if (it->email == email) {
            customers.erase(it);
            cout << "Customer deleted successfully!" << endl;
            return;
        }
    }
    cout << "Customer not found!" << endl;
}

void saveData() {
    ofstream file("customers.txt");
    if (file.is_open()) {
        for (const auto& customer : customers) {
            file << customer.name << endl;
            file << customer.email << endl;
            file << customer.phone << endl;
        }
        file.close();
        cout << "Data saved successfully!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
}

void loadData() {
    ifstream file("customers.txt");
    if (file.is_open()) {
        customers.clear();
        string line;
        while (getline(file, line)) {
            Customer customer;
            customer.name = line;
            getline(file, customer.email);
            getline(file, customer.phone);
            customers.push_back(customer);
        }
        file.close();
        cout << "Data loaded successfully!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
}

int main() {
    loadData();
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                viewCustomers();
                break;
            case 3:
                updateCustomer();
                break;
            case 4:
                deleteCustomer();
                break;
            case 5:
                saveData();
                break;
            default:
                if (choice != 0) {
                    cout << "Invalid choice! Please try again." << endl;
                }
        }
    } while (choice != 0);

    return 0;
}
