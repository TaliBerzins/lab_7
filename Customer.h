/**
 * @file Customer.h
 * @author Tali Berzins
 * @date 2026-11-17
 * @brief The header file for the customer class.
*/
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer {
private:
    string customerID;
    string email;

public:
    Customer();
    Customer(const string& id, const string& email);

    string getCustomerID() const;
    string getEmail() const;

    void printCustomerInfo() const;
};

#endif
