#include "BaseballCardCollectionWindowController.h"

namespace controller
{

BaseballCardCollectionWindowController::BaseballCardCollectionWindowController()
{
}

BaseballCardCollectionWindowController::~BaseballCardCollectionWindowController()
{
}

void BaseballCardCollectionWindowController::loadDataFromFile(const string& fileName)
{
    this->braidedList = this->csvReader.buildBraidedListFromFile(fileName);
}

void BaseballCardCollectionWindowController::saveDataToFile(const string& fileName)
{
    this->csvWriter.writeBraidedListToFile(this->braidedList, fileName);
}

void BaseballCardCollectionWindowController::addCard(BaseballCard& card)
{
    this->braidedList.insertCard(card);
}

void BaseballCardCollectionWindowController::removeByLastName(const string& lastName)
{
    this->braidedList.removeByLastName(lastName);
}

bool BaseballCardCollectionWindowController::containsLastName(const string& lastName) const
{
    return this->braidedList.containsLastName(lastName);
}

string BaseballCardCollectionWindowController::displayCards(SortOrder order) const
{
    vector<BaseballCard> traversal;
    switch (order)
    {
    case SortOrder::NAME_ASCENDING:
        traversal = this->braidedList.traverseAscendingByName();
        break;
    case SortOrder::NAME_DESCENDING:
        traversal = this->braidedList.traverseDescendingByName();
        break;
    case SortOrder::YEAR_ASCENDING:
        traversal = this->braidedList.traverseAscendingByYear();
        break;
    case SortOrder::YEAR_DESCENDING:
        traversal = this->braidedList.traverseDescendingByYear();
        break;
    case SortOrder::CONDITION_ASCENDING:
        traversal = this->braidedList.traverseAscendingByCondition();
        break;
    case SortOrder::CONDITION_DESCENDING:
        traversal = this->braidedList.traverseDescendingByCondition();
        break;
    default:
        traversal = this->braidedList.traverseAscendingByName();
        break;
    }

    return this->traversalFormatter.formatTraversal(traversal);
}

}
