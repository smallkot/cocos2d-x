#include "CCLabelBMFontLoader.h"

using namespace cocos2d;

namespace cocosbuilder {

#define PROPERTY_BLENDFUNC "blendFunc"
#define PROPERTY_FNTFILE "fntFile"
#define PROPERTY_STRING "string"

void LabelBMFontLoader::onHandlePropTypeBlendFunc(Node * pNode, Node * pParent, const char * pPropertyName, BlendFunc pBlendFunc, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_BLENDFUNC) == 0) {
        ((Label *)pNode)->setBlendFunc(pBlendFunc);
    } else {
        NodeLoader::onHandlePropTypeBlendFunc(pNode, pParent, pPropertyName, pBlendFunc, ccbReader);
    }
}

void LabelBMFontLoader::onHandlePropTypeFntFile(Node * pNode, Node * pParent, const char * pPropertyName, const char* pFntFile, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_FNTFILE) == 0) {
        ((Label *)pNode)->setBMFontFilePath(pFntFile);
    } else {
        NodeLoader::onHandlePropTypeFntFile(pNode, pParent, pPropertyName, pFntFile, ccbReader);
    }
}

void LabelBMFontLoader::onHandlePropTypeText(Node * pNode, Node * pParent, const char * pPropertyName, const char* pText, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_STRING) == 0) {
        ((Label *)pNode)->setString(pText);
    } else {
        NodeLoader::onHandlePropTypeText(pNode, pParent, pPropertyName, pText, ccbReader);
    }
}

}
