/*
 * Copyright (c) 2014 cocos2d-x.org
 * http://www.cocos2d-x.org
 *
 * cocos2d for iPhone: http://www.cocos2d-iphone.org
 *
 * Copyright (c) 2013 Apportable Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef __CCBUTTON_H__
#define __CCBUTTON_H__

#include "CCControl.h"
#include "base/CCMap.h"

NS_CC_BEGIN

class Label;

NS_CC_END

NS_CC_EXT_BEGIN

class Scale9Sprite;

/**
 The Button represents a button on the screen. The button is presented with a stretchable background image and/or a title label. Different images, colors and opacity can be set for each of the buttons different states.
 
 Methods for setting callbacks for the button is inherited from Control through the setCallback method or addTargetWithActionForControlEvents method.
 */

typedef std::function<void(Ref*)> ccButtonCallback;


class ButtonControl: public Control
{
public:
    
    /// -----------------------------------------------------------------------
    /// @name Creating Buttons
    /// -----------------------------------------------------------------------
    
    /**
     *  Creates a new button with no title and no background. Uses default font and font size.
     *
     *  @param title The title text of the button.
     *
     *  @return A new button.
     */
    static ButtonControl *create();
    
    /**
     *  Creates a new button with a title and sprite frames for its background in different states.
     *
     *  @param title    The title text of the button.
     *  @param fontName Name of the TTF font to use for the title label.
     *  @param size     Font size for the title label.
     *  @param normal      Stretchable background image for the normal state.
     *  @param highlighted Stretchable background image for the highlighted state.
     *  @param disabled    Stretchable background image for the disabled state.
     *  @param selected    Stretchable background image for the selected state.
     *
     *  @return A new button.
     */
    static ButtonControl *create(const std::string &title, const std::string &fontName, float size, SpriteFrame* normal, SpriteFrame* highlighted, SpriteFrame* disabled, SpriteFrame* selected);
    
    virtual void setEnabled(bool enabled);
    virtual void setSelected(bool enabled);
    virtual void setHighlighted(bool enabled);
    
    /** The preferred (and minimum) size that the component will attempt to layout to. If its contents are larger it may have a larger size. */
    void setPreferredSize(const Size& value);
    const Size& getPreferredSize() const;

    /** The maximum size that the component will layout to, the component will not be larger than this size and will instead shrink its content if needed. */
    void setMaxSize(const Size& value);
    const Size& getMaxSize() const;
    
    Scale9Sprite* getBackground() const;
    Label* getLabel() const;
    
    void setZoomWhenHighlighted(bool value);
    const bool getZoomWhenHighlighted() const;
    
    void setHorizontalPadding(float value);
    const float getHorizontalPadding() const;
    
    void setVerticalPadding(float value);
    const float getVerticalPadding() const;
    
    void setTogglesSelectedState(bool value);
    const bool getTogglesSelectedState() const;
    
    void setTitle(const std::string& value);
    const std::string& getTitle() const;
    
    void setFontName(const std::string& value);
    const std::string& getFontName() const;
    
    void setFontSize(float value);
    const float getFontSize() const;
    
    void setCapInsets(const Rect &margins);
    const Rect& getCapInsets() const;
    
    virtual void visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags) override;
    
    virtual const Size& getContentSize() const override;
    
    void setHorizontalAlignment(TextHAlignment hAlignment);
    TextHAlignment getHorizontalAlignment() const;
    
    void setVerticalAlignment(TextVAlignment vAlignment);
    TextVAlignment getVerticalAlignment() const;
    
    void setOffsets(float left, float top, float right, float bottom);
    void setLeftOffset(float left);
    float getLeftOffset() const;
    void setTopOffset(float top);
    float getTopOffset() const;
    void setRightOffset(float right);
    float getRightOffset() const;
    void setBottomOffset(float bottom);
    float getBottomOffset() const;

    /**
     *  Sets the background color for the specified state. The color is multiplied into the background sprite frame.
     *
     *  @param color Color applied to background image.
     *  @param state State to apply the color to.
     */
    void setBackgroundColor(const Color3B& color, Control::State state);
    
    /**
     *  Gets the background color for the specified state.
     *
     *  @param state State to get the color for.
     *
     *  @return Background color.
     */
    const Color3B& getBackgroundColorForState(Control::State state) const;
    
    /**
     *  Sets the background's opacity for the specified state.
     *
     *  @param opacity Opacity to apply to the background image
     *  @param state   State to apply the opacity to.
     */
    void setBackgroundOpacity(GLubyte opacity, Control::State state);
    
    /**
     *  Gets the background opacity for the specified state.
     *
     *  @param state State to get the opacity for.
     *
     *  @return Opacity.
     */
    GLubyte getBackgroundOpacityForState(Control::State state) const;
    
    /**
     *  Sets the label's color for the specified state.
     *
     *  @param color Color applied to the label.
     *  @param state State to set the color for.
     */
    void setLabelColor(const Color3B& color, Control::State state);
    
    /**
     *  Gets the label's color for the specified state.
     *
     *  @param state State to get the color for.
     *
     *  @return Label color.
     */
    const Color3B& getLabelColorForState(Control::State state) const;
    
    /**
     *  Sets the label's opacity for the specified state.
     *
     *  @param opacity Opacity applied to the label.
     *  @param state   State to set the opacity for.
     */
    void setLabelOpacity(GLubyte opacity, Control::State state);
    
    /**
     *  Gets the label's opacity for the specified state.
     *
     *  @param state State to get the opacity for.
     *
     *  @return Label opacity.
     */
    GLubyte getLabelOpacityForState(Control::State state) const;
    
    /**
     *  Sets the background's sprite frame for the specified state. The sprite frame will be stretched to the preferred size of the label. If set to `NULL` no background will be drawn.
     *
     *  @param spriteFrame Sprite frame to use for drawing the background.
     *  @param state       State to set the background for.
     */
    void setBackgroundSpriteFrame(SpriteFrame* spriteFrame, Control::State state);
    
    /**
     *  Gets the background's sprite frame for the specified state.
     *
     *  @param state State to get the sprite frame for.
     *
     *  @return Background sprite frame.
     */
    SpriteFrame* getBackgroundSpriteFrameForState(Control::State state) const;
    
    void setCallback(const ccButtonCallback& callback);
    
    virtual void addChild(Node * child, int zOrder=0, int tag=0) override;
    virtual void setCascadeOpacityEnabled(bool cascadeOpacityEnabled) override;
    virtual void setCascadeColorEnabled(bool cascadeColorEnabled) override;
    
    virtual bool isTouchInside(Touch * touch) override;

protected:
    
    ButtonControl();
    virtual ~ButtonControl();
    
    virtual bool onTouchBegan(Touch *touch, Event *event) override;
    virtual void onTouchMoved(Touch *touch, Event *event) override;
    virtual void onTouchEnded(Touch *touch, Event *event) override;
    virtual void onTouchCancelled(Touch *touch, Event *event) override;
    
    Map<int, SpriteFrame*> _backgroundSpriteFrames;
    std::map<Control::State, Color3B> _backgroundColors;
    std::map<Control::State, GLubyte> _backgroundOpacities;
    std::map<Control::State, Color3B> _labelColors;
    std::map<Control::State, GLubyte> _labelOpacities;
    
    Scale9Sprite* _background;
    Label* _label;
    bool _zoomWhenHighlighted;
    float _horizontalPadding;
    float _verticalPadding;
    std::string _title;
    bool _togglesSelectedState;
    Size _preferredSize;
    Size _maxSize;
    bool _needLaout;
    Rect _margin;
    ccButtonCallback _callBack;
    
    float _leftOffsets;
    float _topOffsets;
    float _rightOffsets;
    float _bottomOffsets;
    
    void layout();
    virtual void needsLayout();
    void stateChanged();
    void updatePropertiesForState(Control::State state);
    
};

NS_CC_EXT_END

#endif
