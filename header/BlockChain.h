//
// Created by Clément on 15/11/2021.
//

#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.h"
#include "../header/Transaction.h"

using namespace std;

class Blockchain {
public:
    Blockchain();

public:
    void addBlock(Block bNew);

    void minePendingTransaction(string miningRewardAddress);

    void addTransaction(Transaction transaction);

private:
    uint32_t _nDifficulty;
    vector<Block> _vChain;

    Block _getLastBlock() const;
    vector<Transaction> _pendingTransactions;
    const int miningReward=100;
};


#endif //BLOCKCHAIN_BLOCKCHAIN_H
