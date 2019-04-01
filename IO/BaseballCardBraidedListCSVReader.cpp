#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "BaseballCardBraidedListCSVReader.h"

namespace io
{

const char SPLIT = ',';

const int LAST_NAME_INDEX = 0;
const int FIRST_NAME_INDEX = 1;
const int YEAR_INDEX = 2;
const int CONDITION_INDEX = 3;
const int PRICE_INDEX = 4;

BaseballCardBraidedListCSVReader::BaseballCardBraidedListCSVReader()
{
}

BaseballCardBraidedListCSVReader::~BaseballCardBraidedListCSVReader()
{
}

BaseballCardCondition BaseballCardBraidedListCSVReader::stringToBaseballCardCondition(const string& condition)
{
    if (condition == "Poor")
    {
        return BaseballCardCondition::POOR;
    }
    else if (condition == "Good")
    {
        return BaseballCardCondition::GOOD;
    }
    else if (condition == "Excellent")
    {
        return BaseballCardCondition::EXCELLENT;
    }
    else if (condition == "Mint")
    {
        return BaseballCardCondition::MINT;
    }
    else if (condition == "Pristine")
    {
        return BaseballCardCondition::PRISTINE;
    }
    else
    {
        return BaseballCardCondition::UNKNOWN;
    }
}

BaseballCard BaseballCardBraidedListCSVReader::buildBaseballCardFromLine(const string& line)
{
    stringstream stream(line);
    vector<string> tokens;

    string token;
    while (getline(stream, token, SPLIT))
    {
        cout << token << endl;
        tokens.push_back(token);
    }

    string lastName = tokens[LAST_NAME_INDEX];
    string firstName = tokens[FIRST_NAME_INDEX];
    int year = stoi(tokens[YEAR_INDEX]);
    BaseballCardCondition condition = this->stringToBaseballCardCondition(tokens[CONDITION_INDEX]);
    int price = stoi(tokens[PRICE_INDEX]);

    return BaseballCard(firstName, lastName, year, condition, price);
}

BaseballCardBraidedList BaseballCardBraidedListCSVReader::buildBraidedListFromFile(const string& fileName)
{
    BaseballCardBraidedList braidedList;
    ifstream file(fileName);

    string line;
    while (getline(file, line))
    {
        //this->buildBaseballCardFromLine(line);
        BaseballCard card = this->buildBaseballCardFromLine(line);
        braidedList.addCard(card);
    }

    file.close();
    return braidedList;
}

}