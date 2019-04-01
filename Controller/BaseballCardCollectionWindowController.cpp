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

string BaseballCardCollectionWindowController::displayCardsAscending() const
{
    return this->braidedList.displayCardsAscending();
}

}
