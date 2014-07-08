#include "CCScrollViewLoader.h"

using namespace cocos2d;
using namespace cocos2d::extension;

#define PROPERTY_CONTAINER "container"
#define PROPERTY_DIRECTION "direction"
#define PROPERTY_CLIPSTOBOUNDS "clipsToBounds"
#define PROPERTY_BOUNCES "bounces"
#define PROPERTY_SCALE "scale"
#define PROPERTY_CONTENTNODE "contentNode"
#define PROPERTY_VERTICALSCROLLENABLED "verticalScrollEnabled"
#define PROPERTY_HORIZONTALSCROLLENABLED "horizontalScrollEnabled"

namespace cocosbuilder {
    
void ScrollViewLoader::onStarPropertiesParsing(cocos2d::Node * pNode, CCBReader * ccbReader)
{
    _verticalScrollEnabled = false;
    _horizontalScrollEnabled = false;
}
    
void ScrollViewLoader::onEndPropertiesParsing(cocos2d::Node * pNode, CCBReader * ccbReader)
{
    if(ccbReader->getVersion()>5)
    {
        if(_verticalScrollEnabled)
        {
            if(_horizontalScrollEnabled)
                ((ScrollView *)pNode)->setDirection(ScrollView::Direction::BOTH);
            else
                ((ScrollView *)pNode)->setDirection(ScrollView::Direction::VERTICAL);
        }
        else
        {
            if(_horizontalScrollEnabled)
                ((ScrollView *)pNode)->setDirection(ScrollView::Direction::HORIZONTAL);
            else
                ((ScrollView *)pNode)->setDirection(ScrollView::Direction::NONE);
        }
    }
}

void ScrollViewLoader::onHandlePropTypeSize(Node * pNode, Node * pParent, const char * pPropertyName, Size pSize, CCBReader * ccbReader) {
	if(strcmp(pPropertyName, PROPERTY_CONTENTSIZE) == 0) {
		((ScrollView *)pNode)->setViewSize(pSize);
	} else {
		NodeLoader::onHandlePropTypeSize(pNode, pParent, pPropertyName, pSize, ccbReader);
	}
}

void ScrollViewLoader::onHandlePropTypeCheck(Node * pNode, Node * pParent, const char * pPropertyName, bool pCheck, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_CLIPSTOBOUNDS) == 0) {
        ((ScrollView *)pNode)->setClippingToBounds(pCheck);
    } else if(strcmp(pPropertyName, PROPERTY_BOUNCES) == 0) {
        ((ScrollView *)pNode)->setBounceable(pCheck);
    } else if(strcmp(pPropertyName, PROPERTY_VERTICALSCROLLENABLED) == 0) {
        _verticalScrollEnabled = pCheck;
    } else if(strcmp(pPropertyName, PROPERTY_HORIZONTALSCROLLENABLED) == 0) {
        _horizontalScrollEnabled = pCheck;
    } else {
        NodeLoader::onHandlePropTypeCheck(pNode, pParent, pPropertyName, pCheck, ccbReader);
    }
}

void ScrollViewLoader::onHandlePropTypeCCBFile(Node * pNode, Node * pParent, const char * pPropertyName, Node * pCCBFileNode, CCBReader * ccbReader) {
    if((strcmp(pPropertyName, PROPERTY_CONTAINER) == 0) || (strcmp(pPropertyName, PROPERTY_CONTENTNODE) == 0)) {
        ((ScrollView *)pNode)->setContainer(pCCBFileNode);
		((ScrollView *)pNode)->updateInset();
    } else {
        NodeLoader::onHandlePropTypeCCBFile(pNode, pParent, pPropertyName, pCCBFileNode, ccbReader);
    }
}

void ScrollViewLoader::onHandlePropTypeFloat(Node * pNode, Node * pParent, const char * pPropertyName, float pFloat, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_SCALE) == 0) {
        ((ScrollView *)pNode)->setScale(pFloat);
    } else {
        NodeLoader::onHandlePropTypeFloat(pNode, pParent, pPropertyName, pFloat, ccbReader);
    }
}

void ScrollViewLoader::onHandlePropTypeIntegerLabeled(Node * pNode, Node * pParent, const char * pPropertyName, int pIntegerLabeled, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_DIRECTION) == 0) {
        ((ScrollView *)pNode)->setDirection(ScrollView::Direction(pIntegerLabeled));
    } else {
        NodeLoader::onHandlePropTypeFloatScale(pNode, pParent, pPropertyName, pIntegerLabeled, ccbReader);
    }
}

}