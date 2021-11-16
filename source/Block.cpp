//
// Created by Clément on 15/11/2021.
//

#include "../header/Block.h"
#include "../header/sha256.h"
#include <sstream>

Block::Block(uint32_t nIndexIn, vector<Transaction> transactions) {
    _nNonce = -1;
    _tTime = time(nullptr);
    _transactions = transactions;
}

string Block::getHash() {
    return this->_sHash;
}

void Block::MineBlock(uint32_t nDifficulty) {
    char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';

    string str(cstr);

    do {
        _nNonce++;
        _sHash = _CalculateHash();
    } while (_sHash.substr(0, nDifficulty) != str);

    cout << "Block mined: " << _sHash << endl;
}

inline string Block::_CalculateHash() const {
    stringstream ss;
    ss << _nIndex << _tTime << this->transactionsToString() << _nNonce << sPrevHash;

    return sha256(ss.str());
}

string Block::transactionsToString() const {
    stringstream ss;
    for(auto transaction : _transactions){
        ss << transaction.getSignature();
    }
    return ss.str();
}