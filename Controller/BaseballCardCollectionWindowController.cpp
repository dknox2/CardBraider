#include "BaseballCardCollectionWindowController.h"

namespace controller
{

BaseballCardCollectionWindowController::BaseballCardCollectionWindowController()
{
    this->braidedList = new BaseballCardBraidedList();
}

BaseballCardCollectionWindowController::~BaseballCardCollectionWindowController()
{
    delete this->braidedList;
}

void BaseballCardCollectionWindowController::loadDataFromFile(const string& fileName)
{
    delete this->braidedList;
    this->braidedList = this->csvReader.buildBraidedListFromFile(fileName);
}

void BaseballCardCollectionWindowController::addCard(BaseballCard& card)
{
    this->braidedList->insertCard(card);
}

string BaseballCardCollectionWindowController::displayCardsAscendingByName() const
{
    const vector<BaseballCard> traversal = this->braidedList->traverseAscendingByName();
    return this->traversalFormatter.formatTraversal(traversal);
}

string BaseballCardCollectionWindowController::displayCardsDescendingByName() const
{
    const vector<BaseballCard> traversal = this->braidedList->traverseDescendingByName();
    return this->traversalFormatter.formatTraversal(traversal);
}

string BaseballCardCollectionWindowController::displayCardsAscendingByYear() const
{
    const vector<BaseballCard> traversal = this->braidedList->traverseAscendingByYear();
    return this->traversalFormatter.formatTraversal(traversal);
}

string BaseballCardCollectionWindowController::displayCardsDescendingByYear() const
{
    const vector<BaseballCard> traversal = this->braidedList->traverseDescendingByYear();
    return this->traversalFormatter.formatTraversal(traversal);
}
}
