//
// Created by Clément on 15/11/2021.
//

#include "../header/BlockChain.h"

Blockchain::Blockchain() {
    vector<Transaction> transactions;
    _vChain.emplace_back(Block(0, transactions));
    _nDifficulty = 7;
}

void Blockchain::addBlock(Block bNew) {
    bNew.sPrevHash = _getLastBlock().getHash();
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

Block Blockchain::_getLastBlock() const {
    return _vChain.back();
}

void Blockchain::minePendingTransaction(string miningRewardAddress) {
    Transaction rewardTx("", miningRewardAddress, miningReward);
    _pendingTransactions.push_back(rewardTx);

    Block block(_vChain.size(), _pendingTransactions);
    block.MineBlock(_nDifficulty);

    cout << "Block successfully mined ! " << endl;

    _vChain.push_back(block);

    _pendingTransactions.clear();
}

void Blockchain::addTransaction(Transaction transaction) {
    
}