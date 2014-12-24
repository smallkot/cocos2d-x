#ifndef _CCB_CCLABELBMFONTLOADER_H_
#define _CCB_CCLABELBMFONTLOADER_H_

#include "base/CCRef.h"
#include "2d/CCLabel.h"

#include "CCNodeLoader.h"

namespace cocosbuilder {

/* Forward declaration. */
class CCBReader;

class LabelBMFontLoader : public NodeLoader {
public:
    /**
     * @js NA
     * @lua NA
     */
    virtual ~LabelBMFontLoader() {};
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(LabelBMFontLoader, loader);

protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(cocos2d::Label);

    virtual void onHandlePropTypeBlendFunc(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::BlendFunc pBlendFunc, CCBReader * ccbReader) override;
    virtual void onHandlePropTypeFntFile(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, const char* pFntFile, CCBReader * ccbReader) override;
    virtual void onHandlePropTypeText(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, const char* pText, CCBReader * ccbReader) override;
};

}

#endif
