#ifndef _CCB_CCSCROLLLISTVIEWLOADER_H_
#define _CCB_CCSCROLLLISTVIEWLOADER_H_

#include "CCScrollViewLoader.h"
#include "CCScrollListView.h"

namespace cocosbuilder {

class ScrollListViewLoader : public ScrollViewLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ScrollListViewLoader, loader);
    virtual void onHandlePropTypeCCBFileName(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, const char * pCCBFileName, CCBReader * ccbReader) override;
    virtual void onHandlePropTypeText(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, const char * pString, CCBReader * pCCBReader) override;
    virtual void onHandlePropTypeCheck(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, bool pCheck, CCBReader * pCCBReader) override;
    virtual void onHandlePropTypeIntegerLabeled(cocos2d::Node *pNode, cocos2d::Node *pParent, const char *pPropertyName, int pIntegerLabeled, CCBReader *pCCBReader) override;
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(ScrollListView);
    
};
    
}

#endif
