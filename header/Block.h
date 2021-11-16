//
// Created by Clément on 15/11/2021.
//

#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

#include <cstdint>
#include <iostream>
#include <vector>

#include "../header/Transaction.h"

using namespace std;

class Block{

public:
    Block(uint32_t nIndexIn, const vector<Transaction> transactions);

public:
    string getHash();
    void MineBlock(uint32_t nDifficulty);


    string sPrevHash;
private:
    uint32_t _nIndex;
    int64_t _nNonce;
    string _sHash;
    time_t _tTime;

    vector<Transaction> _transactions;

private:
    string _CalculateHash() const;
    string transactionsToString() const;
};


#endif //BLOCKCHAIN_BLOCK_H
