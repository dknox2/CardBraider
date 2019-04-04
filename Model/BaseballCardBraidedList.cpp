#include "BaseballCardBraidedList.h"

using namespace std;

namespace model
{

BaseballCardBraidedList::BaseballCardBraidedList() :
    headName(nullptr),
    headYear(nullptr)
{
}

// TODO delete resources
BaseballCardBraidedList::~BaseballCardBraidedList()
{
    this->deleteNodes(this->headName);
}

void BaseballCardBraidedList::deleteNodes(BaseballCardNode* node)
{
    if (node == nullptr)
    {
        return;
    }

    this->deleteNodes(node->getNextName());
    delete node;
}

void BaseballCardBraidedList::insertCard(const BaseballCard& card)
{
    BaseballCardNode* node = new BaseballCardNode(card);

    this->headName = this->insertNodeByName(node);
    this->headYear = this->insertNodeByYear(node);
}

BaseballCardNode* BaseballCardBraidedList::insertNodeByName(BaseballCardNode* node)
{
    return this->insertNode(this->headName, node, BaseballCardNodeFunctionalArgs::getNextName,
                            BaseballCardNodeFunctionalArgs::setNextName, BaseballCardNodeFunctionalArgs::compareByName);
}

BaseballCardNode* BaseballCardBraidedList::insertNodeByYear(BaseballCardNode* node)
{
    return this->insertNode(this->headYear, node, BaseballCardNodeFunctionalArgs::getNextYear,
                            BaseballCardNodeFunctionalArgs::setNextYear, BaseballCardNodeFunctionalArgs::compareByYear);
}

BaseballCardNode* BaseballCardBraidedList::insertNode(BaseballCardNode* node, BaseballCardNode* toInsert, BaseballCardNodeGetter getNext, BaseballCardNodeSetter setNext, BaseballCardCompare comp)
{
    if (node == nullptr)
    {
        return toInsert;
    }

    if (comp(node->getCard(), toInsert->getCard()))
    {
        setNext(node, this->insertNode(getNext(node), toInsert, getNext, setNext, comp));
        return node;
    }

    setNext(toInsert, node);
    return toInsert;
}

const vector<BaseballCard> BaseballCardBraidedList::traverseAscendingByName() const
{
    vector<BaseballCard> traversal;
    this->traverseAscending(this->headName, BaseballCardNodeFunctionalArgs::getNextName, traversal);

    return traversal;
}
const vector<BaseballCard> BaseballCardBraidedList::traverseDescendingByName() const
{
    vector<BaseballCard> traversal;
    this->traverseDescending(this->headName, BaseballCardNodeFunctionalArgs::getNextName, traversal);

    return traversal;
}

const vector<BaseballCard> BaseballCardBraidedList::traverseAscendingByYear() const
{
    vector<BaseballCard> traversal;
    this->traverseAscending(this->headYear, BaseballCardNodeFunctionalArgs::getNextYear, traversal);

    return traversal;
}

const vector<BaseballCard> BaseballCardBraidedList::traverseDescendingByYear() const
{
    vector<BaseballCard> traversal;
    this->traverseDescending(this->headYear, BaseballCardNodeFunctionalArgs::getNextYear, traversal);

    return traversal;
}

void BaseballCardBraidedList::traverseAscending(BaseballCardNode* node, BaseballCardNodeGetter getNext, vector<BaseballCard>& traversal) const
{
    if (node == nullptr)
    {
        return;
    }

    traversal.push_back(node->getCard());
    this->traverseAscending(getNext(node), getNext, traversal);
}

void BaseballCardBraidedList::traverseDescending(BaseballCardNode* node, BaseballCardNodeGetter getNext, vector<BaseballCard>& traversal) const
{
    if (node == nullptr)
    {
        return;
    }

    this->traverseDescending(getNext(node), getNext, traversal);
    traversal.push_back(node->getCard());
}

/*
string BaseballCardBraidedList::displayCardsAscending() const
{
    stringstream stream;
    this->appendCardToOutputAscending(this->headYear, stream);
    return stream.str();
}

void BaseballCardBraidedList::appendCardToOutputAscending(BaseballCardNode* node, stringstream& stream) const
{
    if (node == nullptr)
    {
        return;
    }

    stream << left << setw(16) << (node->getCard().getFirstName() + " " + node->getCard().getLastName())
           << left << setw(8) << node->getCard().getYear()
           << left << setw(8) << node->getCard().getCondition()
           << right << setw(16) << node->getCard().getPrice() << endl;

    BaseballCardNode* nextNode = node->getNextYear();
    this->appendCardToOutputAscending(nextNode, stream);
}

string BaseballCardBraidedList::displayCardsDescending() const
{
    stringstream stream;
    this->appendCardToOutputDescending(this->headYear, stream);

    return stream.str();
}

void BaseballCardBraidedList::appendCardToOutputDescending(BaseballCardNode* node, stringstream& stream) const
{
    if (node == nullptr)
    {
        return;
    }

    BaseballCardNode* nextNode = node->getNextYear();
    this->appendCardToOutputDescending(nextNode, stream);

    stream << left << setw(16) << (node->getCard().getFirstName() + " " + node->getCard().getLastName())
           << left << setw(8) << node->getCard().getYear()
           << left << setw(8) << node->getCard().getCondition()
           << right << setw(16) << node->getCard().getPrice() << endl;
}
*/
}
