#include <iostream>
#include <sstream>

#include "BaseballCardBraidedList.h"

using namespace std;

namespace model
{

BaseballCardBraidedList::BaseballCardBraidedList() : headName(nullptr)
{
}

// TODO delete resources
BaseballCardBraidedList::~BaseballCardBraidedList()
{
}

BaseballCardNode* BaseballCardBraidedList::getNextName(BaseballCardNode* node)
{
    return node->getNextName();
}

void BaseballCardBraidedList::setNextName(BaseballCardNode* node, BaseballCardNode* toSet)
{
    node->setNextName(toSet);
}

bool BaseballCardBraidedList::compareLastThenFirst(const BaseballCard& card0, const BaseballCard& card1)
{
    string card0Name = card0.getLastName() + card0.getFirstName();
    string card1Name = card1.getLastName() + card1.getFirstName();

    return card0Name >= card1Name;
}

void BaseballCardBraidedList::insertCardByName(BaseballCard card)
{
    this->headName = this->insertCard(this->headName, card, getNextName, setNextName, compareLastThenFirst);
}

BaseballCardNode* BaseballCardBraidedList::insertCard(BaseballCardNode* node, BaseballCard& card, BaseballCardNodeGetter getNext, BaseballCardNodeSetter setNext, BaseballCardCompare comp)
{
    if (node == nullptr)
    {
        return new BaseballCardNode(card);
    }

    if (comp(card, node->getCard()))
    {
        setNext(node, this->insertCard(getNext(node), card, getNext, setNext, comp));
        return node;
    }

    BaseballCardNode* temp = node;
    node = new BaseballCardNode(card);
    setNext(node, temp);

    return node;
}

string BaseballCardBraidedList::displayCardsAscending() const
{
    stringstream stream;
    this->appendCardToOutputAscending(this->headName, stream);

    return stream.str();
}

void BaseballCardBraidedList::appendCardToOutputAscending(BaseballCardNode* node, stringstream& stream) const
{
    if (node == nullptr)
    {
        return;
    }

    string formattedNode = node->getCard().getLastName();
    stream << formattedNode << endl;

    BaseballCardNode* nextNode = node->getNextName();
    this->appendCardToOutputAscending(nextNode, stream);
}

string BaseballCardBraidedList::displayCardsDescending() const
{
    stringstream stream;
    this->appendCardToOutputDescending(this->headName, stream);

    return stream.str();
}

void BaseballCardBraidedList::appendCardToOutputDescending(BaseballCardNode* node, stringstream& stream) const
{
    if (node == nullptr)
    {
        return;
    }

    BaseballCardNode* nextNode = node->getNextName();
    this->appendCardToOutputDescending(nextNode, stream);

    string formattedNode = node->getCard().getLastName();
    stream << formattedNode << endl;

}
}
