//
// Created by Clément on 16/11/2021.
//

#ifndef BLOCKCHAIN_TRANSACTION_H
#define BLOCKCHAIN_TRANSACTION_H

#include <cstdint>
#include <iostream>

using namespace std;

class Transaction {

public:
    Transaction(string fromAdress, string toAddress, int amount);

public:
    string calculateHash() const;

    void signTransaction(string publicSigningKey);

    bool isValid();

    string getSignature();

private:
    string _fromAddress;
    string _toAddress;
    int _amount;

    string _signature;
};


#endif //BLOCKCHAIN_TRANSACTION_H
