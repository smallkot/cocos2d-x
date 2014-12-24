#ifndef _CCB_CCSCROLLVIEWLOADER_H_
#define _CCB_CCSCROLLVIEWLOADER_H_

#include "CCNodeLoader.h"
#include "extensions/GUI/CCScrollView/CCScrollView.h"

namespace cocosbuilder {

/* Forward declaration. */
class CCBReader;

class ScrollViewLoader : public NodeLoader {
public:
    /**
     * @js NA
     * @lua NA
     */
    virtual ~ScrollViewLoader() {};
    /**
     * @js NA
     * @lua NA
     */
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ScrollViewLoader, loader);

protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(cocos2d::extension::ScrollView);
    virtual void onStarPropertiesParsing(cocos2d::Node * pNode, CCBReader * ccbReader) override;
    virtual void onEndPropertiesParsing(cocos2d::Node * pNode, CCBReader * ccbReader) override;
    virtual void onHandlePropTypeSize(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, const cocos2d::Size &pSize, CCBReader * ccbReader) override;
    virtual void onHandlePropTypeCCBFile(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Node * pCCBFileNode, CCBReader * ccbReader) override;
    virtual void onHandlePropTypeCheck(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, bool pCheck, CCBReader * ccbReader) override;
    virtual void onHandlePropTypeFloat(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, float pFloat, CCBReader * ccbReader) override;
    virtual void onHandlePropTypeIntegerLabeled(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, int pIntegerLabeled, CCBReader * ccbReader) override;
private:
    bool _verticalScrollEnabled;
    bool _horizontalScrollEnabled;
};

}

#endif
