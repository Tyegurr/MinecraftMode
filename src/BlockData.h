#pragma once

#include <string>

#define SharedBlockMetadata std::make_shared<BlockMetadata>

class BlockMetadata {
public:
    int id;
    std::string name;
    const char* spriteName;
    BlockMetadata(int id, std::string name, const char* spriteName) {
        this->id = id;
        this->name = name;
        this->spriteName = spriteName;
    }
};