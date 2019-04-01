#include "BaseballCardBraidedList.h"

namespace model
{
BaseballCardBraidedList::BaseballCardBraidedList() : headName(nullptr)
{
}

BaseballCardBraidedList::~BaseballCardBraidedList()
{
}

void BaseballCardBraidedList::addCard(BaseballCard card)
{
    this->addCard(this->headName, card);
}

void BaseballCardBraidedList::addCard(BaseballCardNode* node, BaseballCard& card)
{
    if (node == nullptr)
    {
        node = new BaseballCardNode(card);
    }
    else
    {
        this->addCard(node->getNextName(), card);
    }
}

}
