//
// Created by Clément on 15/11/2021.
//

#include "../header/BlockChain.h"

Blockchain::Blockchain() {
    _vChain.emplace_back(Block(0, "Genesis Block"));
    _nDifficulty = 6;
}

void Blockchain::addBlock(Block bNew) {
    bNew.sPrevHash = _getLastBlock().getHash();
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

Block Blockchain::_getLastBlock() const {
    return _vChain.back();
}