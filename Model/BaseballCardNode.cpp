#include "BaseballCardNode.h"

namespace model
{
BaseballCardNode::BaseballCardNode(BaseballCard& card) :
    card(card),
    nextName(nullptr)
{
}

BaseballCardNode::~BaseballCardNode()
{
}

void BaseballCardNode::setNextName(BaseballCardNode* node)
{
    this->nextName = node;
}

BaseballCardNode* BaseballCardNode::getNextName()
{
    return this->nextName;
}

BaseballCard BaseballCardNode::getCard() const
{
    return this->card;
}

}
