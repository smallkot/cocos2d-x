#include "CCTextFieldLoader.h"

using namespace cocos2d;
using namespace cocos2d::extension;

#define PROPERTY_PREFERREDSIZE "preferredSize"
#define PROPERTY_SPRITEFRAME "backgroundSpriteFrame"
#define PROPERTY_PADDING "padding"
#define PROPERTY_FONTNAME "fontName"
#define PROPERTY_FONTSIZE "fontSize"
#define PROPERTY_FONTCOLOR "fontColor"
#define PROPERTY_TEXT "string"
#define PROPERTY_PLACEHOLDER_FONTNAME "placeholderFontName"
#define PROPERTY_PLACEHOLDER_FONTSIZE "placeholderFontSize"
#define PROPERTY_PLACEHOLDER_FONTCOLOR "placeholderFontColor"
#define PROPERTY_PLACEHOLDER "placeholder"
#define PROPERTY_MAXLENGTH "maxLength"
#define PROPERTY_INPUTMODE "inputMode"
#define PROPERTY_KEYBOARDRETURNTYPE "keyboardReturnType"
#define PROPERTY_INPUTFLAG "inputFlag"

namespace cocosbuilder {

cocos2d::extension::EditBox * EditBoxLoader::createNode(cocos2d::Node * pParent, CCBReader * ccbReader) {
    EditBox* pRet = new EditBox();
    pRet->initWithSizeAndBackgroundSprite(cocos2d::Size(0,0), cocos2d::extension::Scale9Sprite::create());
    pRet->autorelease();
    pRet->setFontName("Helvetica");
    pRet->setFontColor(cocos2d::Color3B::BLACK);
        
    return pRet;
}


void EditBoxLoader::onHandlePropTypeSize(Node * pNode, Node * pParent, const char* pPropertyName, Size pSize, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_PREFERREDSIZE) == 0) {
        ((EditBox*)pNode)->setPreferredSize(pSize);
    } else {
        ControlLoader::onHandlePropTypeSize(pNode, pParent, pPropertyName, pSize, ccbReader);
    }
}

void EditBoxLoader::onHandlePropTypeSpriteFrame(Node * pNode, Node * pParent, const char * pPropertyName, SpriteFrame * pSpriteFrame, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_SPRITEFRAME) == 0) {
        ((EditBox*)pNode)->setBackgroundSpriteFrameForState(pSpriteFrame, Control::State::NORMAL);
    } else {
        ControlLoader::onHandlePropTypeSpriteFrame(pNode, pParent, pPropertyName, pSpriteFrame, ccbReader);
    }
}

void EditBoxLoader::onHandlePropTypeFloatScale(Node * pNode, Node * pParent, const char* pPropertyName, float pFloatScale, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_FONTSIZE) == 0) {
        ((EditBox*)pNode)->setFontSize(pFloatScale);
    } else if(strcmp(pPropertyName, PROPERTY_PLACEHOLDER_FONTSIZE) == 0) {
        ((EditBox*)pNode)->setPlaceholderFontSize(pFloatScale);
    } else {
        ControlLoader::onHandlePropTypeFloatScale(pNode, pParent, pPropertyName, pFloatScale, ccbReader);
    }
}
    
void EditBoxLoader::onHandlePropTypeFontTTF(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, const char * pFontTTF, CCBReader * ccbReader)
{
    if(strcmp(pPropertyName, PROPERTY_FONTNAME) == 0) {
        ((EditBox*)pNode)->setFontName(pFontTTF);
    } else if(strcmp(pPropertyName, PROPERTY_PLACEHOLDER_FONTNAME) == 0) {
        ((EditBox*)pNode)->setPlaceholderFontName(pFontTTF);
    } else{
        ControlLoader::onHandlePropTypeFontTTF(pNode, pParent, pPropertyName, pFontTTF, ccbReader);
    }
}

void EditBoxLoader::onHandlePropTypeColor3(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Color4B pColor4B, CCBReader * ccbReader)
{
    if(strcmp(pPropertyName, PROPERTY_FONTCOLOR) == 0){
        ((EditBox*)pNode)->setFontColor(Color3B(pColor4B));
    } else if(strcmp(pPropertyName, PROPERTY_PLACEHOLDER_FONTCOLOR) == 0){
        ((EditBox*)pNode)->setPlaceholderFontColor(Color3B(pColor4B));
    } else {
        ControlLoader::onHandlePropTypeColor3(pNode, pParent, pPropertyName, pColor4B, ccbReader);
    }

}
    
void EditBoxLoader::onHandlePropTypeInteger(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, int pInteger, CCBReader * ccbReader)
{
    if(strcmp(pPropertyName, PROPERTY_MAXLENGTH) == 0) {
        ((EditBox *)pNode)->setMaxLength(pInteger);
    } else {
        ControlLoader::onHandlePropTypeInteger(pNode, pParent, pPropertyName, pInteger, ccbReader);
    }
}
    
void EditBoxLoader::onHandlePropTypeIntegerLabeled(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, int pIntegerLabeled, CCBReader * ccbReader)
{
    if(strcmp(pPropertyName, PROPERTY_INPUTMODE) == 0) {
        ((EditBox *)pNode)->setInputMode(static_cast<EditBox::InputMode>(pIntegerLabeled));
    } else if(strcmp(pPropertyName, PROPERTY_KEYBOARDRETURNTYPE) == 0) {
        ((EditBox *)pNode)->setReturnType(static_cast<EditBox::KeyboardReturnType>(pIntegerLabeled));
    } else if(strcmp(pPropertyName, PROPERTY_INPUTFLAG) == 0) {
        ((EditBox *)pNode)->setInputFlag(static_cast<EditBox::InputFlag>(pIntegerLabeled));
    } else {
        ControlLoader::onHandlePropTypeIntegerLabeled(pNode, pParent, pPropertyName, pIntegerLabeled, ccbReader);
    }
}
    
void EditBoxLoader::onHandlePropTypeText(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, const char * pText, CCBReader * ccbReader)
{
    if(strcmp(pPropertyName, PROPERTY_TEXT) == 0) {
        ((EditBox *)pNode)->setText(pText);
    } else if(strcmp(pPropertyName, PROPERTY_PLACEHOLDER) == 0) {
        ((EditBox *)pNode)->setPlaceHolder(pText);
    } else {
        ControlLoader::onHandlePropTypeText(pNode, pParent, pPropertyName, pText, ccbReader);
    }
}

};