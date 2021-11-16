//
// Created by Clément on 15/11/2021.
//

#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

#include <cstdint>
#include <iostream>

using namespace std;

class Block{

public:
    Block(uint32_t nIndexIn, const string &sDataIn);

public:
    string getHash();
    void MineBlock(uint32_t nDifficulty);

    string sPrevHash;
private:
    uint32_t _nIndex;
    int64_t _nNonce;
    string _sData;
    string _sHash;
    time_t _tTime;

    string _CalculateHash() const;
};


#endif //BLOCKCHAIN_BLOCK_H
