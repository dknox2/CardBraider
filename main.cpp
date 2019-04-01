#include "BaseballCardCollectionWindow.h"

using namespace view;

#include "BaseballCardBraidedListCSVReader.h"

int main (int argc, char ** argv)
{
    io::BaseballCardBraidedListCSVReader csvReader;
    csvReader.buildBraidedListFromFile("cards.txt");
    BaseballCardCollectionWindow mainWindow(540, 375, "A3: CardBraider by Dylan Knox");
    mainWindow.show();

    int exitCode = Fl::run();
    return exitCode;
}
