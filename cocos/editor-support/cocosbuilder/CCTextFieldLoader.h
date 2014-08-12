#ifndef _SB_CCEDITBOXLOADER_H_
#define _SB_CCEDITBOXLOADER_H_

#include "CCControlLoader.h"
#include "extensions//GUI/CCEditBox/CCEditBox.h"

namespace cocosbuilder {
    
/* Forward declaration. */
class CCBReader;


class EditBoxLoader : public ControlLoader {
public:
    //EditBoxLoader() {}
    /**
     * @js NA
     * @lua NA
     */
    virtual ~EditBoxLoader() {};
    /**
     * @js NA
     * @lua NA
     */
   
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(EditBoxLoader, loader);
    
protected:
    virtual cocos2d::extension::EditBox * createNode(cocos2d::Node * pParent, CCBReader * ccbReader) override;

    /**
     * @js NA
     * @lua NA
     */
    
    virtual void onHandlePropTypeSize(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, cocos2d::Size pSize, CCBReader * ccbReader) override;
    /**
     * @js NA
     * @lua NA
     */
    virtual void onHandlePropTypeSpriteFrame(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::SpriteFrame * pSpriteFrame, CCBReader * ccbReader) override;
    /**
     * @js NA
     * @lua NA
     */
    virtual void onHandlePropTypeFloatScale(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, float pFloatScale, CCBReader * ccbReader) override;
    
    virtual void onHandlePropTypeFontTTF(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, const char * pFontTTF, CCBReader * ccbReader) override;
    
    virtual void onHandlePropTypeColor3(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Color4B pColor4B, CCBReader * ccbReader) override;
    
    virtual void onHandlePropTypeInteger(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, int pInteger, CCBReader * ccbReader) override;
    
    virtual void onHandlePropTypeIntegerLabeled(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, int pIntegerLabeled, CCBReader * ccbReader) override;
    
    virtual void onHandlePropTypeText(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, const char * pText, CCBReader * ccbReader) override;

};


};

#endif
