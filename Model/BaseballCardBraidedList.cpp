#include <iostream>

#include "BaseballCardBraidedList.h"
#include "Utils.h"

using namespace std;

namespace model
{

BaseballCardBraidedList::BaseballCardBraidedList() :
    headName(nullptr),
    headYear(nullptr),
    headCondition(nullptr)
{
}

BaseballCardBraidedList::~BaseballCardBraidedList()
{
    this->deleteAllNodes(this->headName);
}

void BaseballCardBraidedList::deleteAllNodes(BaseballCardNode* node)
{
    if (node == nullptr)
    {
        return;
    }

    this->deleteAllNodes(node->getNextName());
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

const vector<BaseballCardNode*> BaseballCardBraidedList::findNodesByLastName(const string& lastName) const
{
    vector<BaseballCardNode*> foundNodes;
    this->findNodesByLastName(this->headName, toUpperCase(lastName), foundNodes);

    return foundNodes;
}

void BaseballCardBraidedList::findNodesByLastName(BaseballCardNode* node, const string& lastName, vector<BaseballCardNode*>& foundNodes) const
{
    if (node == nullptr)
    {
        return;
    }

    string currentLastName = toUpperCase(node->getCard().getLastName());
    if (currentLastName == lastName)
    {
        foundNodes.push_back(node);
    }

    this->findNodesByLastName(node->getNextName(), lastName, foundNodes);
}

void BaseballCardBraidedList::removeByLastName(const string& lastName)
{
    string upperCaseLastName = toUpperCase(lastName);
    this->rebraidAllByLastName(upperCaseLastName);

    vector<BaseballCardNode*> nodesToRemove = this->findNodesByLastName(upperCaseLastName);
    this->deleteNodes(nodesToRemove);
}

void BaseballCardBraidedList::rebraidAllByLastName(const string& lastName)
{
    this->rebraidNameByLastName(lastName);
    this->rebraidYearByLastName(lastName);
}

void BaseballCardBraidedList::rebraidNameByLastName(const string& lastName)
{
    this->headName = this->rebraidByLastName(this->headName, lastName, BaseballCardNodeFunctionalArgs::getNextName, BaseballCardNodeFunctionalArgs::setNextName);
}

void BaseballCardBraidedList::rebraidYearByLastName(const string& lastName)
{
    this->headYear = this->rebraidByLastName(this->headYear, lastName, BaseballCardNodeFunctionalArgs::getNextYear, BaseballCardNodeFunctionalArgs::setNextYear);
}

void BaseballCardBraidedList::deleteNodes(const vector<BaseballCardNode*>& nodes)
{
    for (auto& node : nodes)
    {
        delete node;
    }
}

BaseballCardNode* BaseballCardBraidedList::rebraidByLastName(BaseballCardNode* node, const string& lastName, BaseballCardNodeGetter getNext, BaseballCardNodeSetter setNext)
{
    if (node == nullptr)
    {
        return node;
    }

    string currentLastName = toUpperCase(node->getCard().getLastName());
    if (currentLastName == lastName)
    {
        return this->rebraidByLastName(getNext(node), lastName, getNext, setNext);
    }
    else
    {
        setNext(node, this->rebraidByLastName(getNext(node), lastName, getNext, setNext));
        return node;
    }
}

bool BaseballCardBraidedList::containsLastName(const string& lastName) const
{
    return this->findNodesByLastName(lastName).size() != 0;
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
}
