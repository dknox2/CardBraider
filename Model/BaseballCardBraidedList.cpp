#include <iostream>
#include <sstream>

#include "BaseballCardBraidedList.h"

using namespace std;

namespace model
{

BaseballCardBraidedList::BaseballCardBraidedList() : headName(nullptr)
{
}

// TODO Implement this to stop memory leaks (card nodes not deleted when added)
BaseballCardBraidedList::~BaseballCardBraidedList()
{
}

void BaseballCardBraidedList::addCard(BaseballCard card)
{
    this->headName = this->addCard(this->headName, card);
}

BaseballCardNode* BaseballCardBraidedList::addCard(BaseballCardNode* node, BaseballCard& card)
{
    if (node == nullptr)
    {
        node = new BaseballCardNode(card);
        return node;
    }

    node->setNextName(this->addCard(node->getNextName(), card));
    return node;
}

string BaseballCardBraidedList::displayCardsAscending() const
{
    stringstream stream;
    this->appendCardToOutput(this->headName, stream);

    return stream.str();
}

void BaseballCardBraidedList::appendCardToOutput(BaseballCardNode* node, stringstream& stream) const
{
    if (node == nullptr)
    {
        return;
    }

    string formattedNode = node->getCard().getLastName();
    stream << formattedNode << endl;

    BaseballCardNode* nextNode = node->getNextName();
    this->appendCardToOutput(nextNode, stream);
}
}
