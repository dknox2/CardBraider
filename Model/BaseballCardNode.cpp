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

BaseballCardNode* BaseballCardNode::getNextName()
{
    return this->nextName;
}

BaseballCard BaseballCardNode::getCard() const
{
    return this->card;
}

}
