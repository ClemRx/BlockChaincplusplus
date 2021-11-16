//
// Created by Clément on 16/11/2021.
//

#include "../header/Transaction.h"
#include "../header/sha256.h"
#include <sstream>

Transaction::Transaction(string fromAdress, string toAddress, int amount) {
    _fromAddress = fromAdress;
    _toAddress = toAddress;
    _amount = amount;

    _signature = "";
}

string Transaction::calculateHash() const {
    stringstream ss;
    ss << _fromAddress << _toAddress << _amount;

    return sha256(ss.str());
}

void Transaction::signTransaction(string publicSigningKey) {
    if(sha256(_fromAddress) != publicSigningKey){
        throw std::runtime_error("Error : wrong public key");
    }

    string hashTx = this->calculateHash();
    _signature = hashTx;
}

bool Transaction::isValid() {
    if(_fromAddress == "") return true;

    if(_signature == "") throw std::runtime_error("Error : the transaction is not signed");

    return (this->calculateHash() == _signature);
}

string Transaction::getSignature() {
    return _signature;
}