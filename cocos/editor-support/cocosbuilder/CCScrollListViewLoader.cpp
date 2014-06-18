//
//  RjScrollListView.cpp
//  inferno
//
//  Created by user-i121 on 03.07.13.
//
//

#include "CCScrollListViewLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

#define PROPERTY_TEMPLATE   "template"
#define PROPERTY_HORIZONTAL "horizontal"
#define PROPERTY_VERTALIGN  "verticalTextAlignment"
#define PROPERTY_HORIZALIGN "textAlignment"
#define SCROLL_MOVE_ELEMENTS    1

namespace cocosbuilder {


void ScrollListViewLoader::onHandlePropTypeCCBFileName(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, const char * pCCBFileName, cocosbuilder::CCBReader * ccbReader)
{
    if(strcmp(pPropertyName, PROPERTY_TEMPLATE) == 0)
        ((ScrollListView *)pNode)->setTemplate(pCCBFileName);
    else
        ScrollViewLoader::onHandlePropTypeCCBFileName(pNode, pParent, pPropertyName, pCCBFileName, ccbReader);
}

void ScrollListViewLoader::onHandlePropTypeText(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, const char * pString, cocosbuilder::CCBReader * pCCBReader) {
    if(strcmp(pPropertyName, PROPERTY_TEMPLATE) == 0)
        ((ScrollListView *)pNode)->setTemplate(pString);
    else
        ScrollViewLoader::onHandlePropTypeText(pNode, pParent, pPropertyName, pString, pCCBReader);
}

void ScrollListViewLoader::onHandlePropTypeCheck(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, bool pCheck, cocosbuilder::CCBReader * pCCBReader) {
    if(strcmp(pPropertyName, PROPERTY_HORIZONTAL) == 0)
        ((ScrollListView *)pNode)->setHorizontal(pCheck);
    else
        ScrollViewLoader::onHandlePropTypeCheck(pNode, pParent, pPropertyName, pCheck, pCCBReader);
}

void ScrollListViewLoader::onHandlePropTypeIntegerLabeled(cocos2d::Node *pNode, cocos2d::Node *pParent, const char *pPropertyName, int pIntegerLabeled, cocosbuilder::CCBReader *pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_HORIZALIGN) == 0) {
        ((ScrollListView *)pNode)->setTextAlignment((TextHAlignment)pIntegerLabeled);
    } else if (strcmp(pPropertyName, PROPERTY_VERTALIGN) == 0) {
        ((ScrollListView *)pNode)->setVerticalTextAlignment((TextVAlignment)pIntegerLabeled);
    } else {
        ScrollViewLoader::onHandlePropTypeIntegerLabeled(pNode, pParent, pPropertyName, pIntegerLabeled, pCCBReader);
    }
}
    
}

