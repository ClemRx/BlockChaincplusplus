cmake_minimum_required(VERSION 3.0)
project(BlockChain)

set(CMAKE_CXX_STANDARD 14)

add_executable(BlockChain main.cpp source/BlockChain.cpp header/BlockChain.h source/Block.cpp header/Block.h header/sha256.h source/sha256.cpp)
