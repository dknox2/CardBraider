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

void BaseballCardCollectionWindowController::addCard(BaseballCard& card)
{
    this->braidedList.insertCardByName(card);
}

string BaseballCardCollectionWindowController::displayCardsAscending() const
{
    return this->braidedList.displayCardsAscending();
}

string BaseballCardCollectionWindowController::displayCardsDescending() const
{
    return this->braidedList.displayCardsDescending();
}

}
