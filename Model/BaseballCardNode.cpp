#include "BaseballCardNode.h"

namespace model
{
BaseballCardNode::BaseballCardNode(const BaseballCard& card) :
    card(card),
    nextName(nullptr),
    nextYear(nullptr)
{
}

BaseballCardNode::~BaseballCardNode()
{
}

BaseballCardNode* BaseballCardNode::getNextName() const
{
    return this->nextName;
}

void BaseballCardNode::setNextName(BaseballCardNode* node)
{
    this->nextName = node;
}

BaseballCardNode* BaseballCardNode::getNextYear() const
{
    return this->nextYear;
}


void BaseballCardNode::setNextYear(BaseballCardNode* node)
{
    this->nextYear = node;
}

BaseballCard BaseballCardNode::getCard() const
{
    return this->card;
}

}
