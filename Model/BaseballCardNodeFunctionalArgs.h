#ifndef BASEBALLCARDNODEFUNCTIONALARGS_H
#define BASEBALLCARDNODEFUNCTIONALARGS_H

#include "BaseballCardNode.h"

namespace model
{

typedef BaseballCardNode* (*BaseballCardNodeGetter)(BaseballCardNode*);
typedef void (*BaseballCardNodeSetter)(BaseballCardNode*, BaseballCardNode*);
typedef bool (*BaseballCardCompare)(const BaseballCard&, const BaseballCard&);

class BaseballCardNodeFunctionalArgs
{
public:

    static BaseballCardNode* getNextName(BaseballCardNode* node);
    static void setNextName(BaseballCardNode* node, BaseballCardNode* toSet);
    static bool compareByName(const BaseballCard& card0, const BaseballCard& card1);

    static BaseballCardNode* getNextYear(BaseballCardNode* node);
    static void setNextYear(BaseballCardNode* node, BaseballCardNode* toSet);
    static bool compareByYear(const BaseballCard& card0, const BaseballCard& card1);
};
}


#endif // BASEBALLCARDNODEFUNCTIONALARGS_H
