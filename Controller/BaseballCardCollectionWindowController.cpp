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
    this->braidedList->insertCardByName(card);
}

string BaseballCardCollectionWindowController::displayCardsAscending() const
{
    return this->braidedList->displayCardsAscending();
}

string BaseballCardCollectionWindowController::displayCardsDescending() const
{
    return this->braidedList->displayCardsDescending();
}

}
