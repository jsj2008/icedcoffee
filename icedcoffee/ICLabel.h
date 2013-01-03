//  
//  Copyright (C) 2012 Tobias Lensing, Marcus Tillmanns
//  http://icedcoffee-framework.org
//  
//  Permission is hereby granted, free of charge, to any person obtaining a copy of
//  this software and associated documentation files (the "Software"), to deal in
//  the Software without restriction, including without limitation the rights to
//  use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
//  of the Software, and to permit persons to whom the Software is furnished to do
//  so, subject to the following conditions:
//  
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//  
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.
//  

#import "ICView.h"
#import "ICFont.h"

@class ICSprite;
@class ICTextFrame;

#define ICLabelTextDidChange @"ICLabelTextDidChange"
#define ICLabelFontDidChange @"ICLabelFontDidChange"

/**
 @brief Implements a text view that cannot be edited by the user
 */
@interface ICLabel : ICView {
@protected
    ICTextFrame *_textFrame;
    BOOL _shouldNotApplyPropertiesFromAttributedText;
    BOOL _shouldNotApplyPropertiesFromBasicText;
    
    NSString *_text;
    NSAttributedString *_attributedText;
    ICFont *_font;
    NSString *_fontName;
    CGFloat _fontSize;
    float _tracking;
    icColor4B _color;
    float _gamma;
    BOOL _autoresizesToTextSize;
}

#pragma mark - Creating a Label
/** @name Creating a Label */

/**
 @brief Returns a new autoreleased label

 For details see ICLabel::init.
 */
+ (id)label;

/**
 @brief Returns a new autoreleased label with the given size
 
 For details see ICLabel::initWithSize:.
 */
+ (id)labelWithSize:(CGSize)size;

/**
 @brief Returns a new autoreleased label with the given size and attributed text
 
 For details see ICLabel::initWithSize:attributedText:.
 */
+ (id)labelWithSize:(CGSize)size attributedText:(NSAttributedString *)attributedText;

/**
 @brief Returns a new autoreleased label with the given text using the default system font
 
 For details see ICLabel::initWithText:.
 */
+ (id)labelWithText:(NSString *)text;

/**
 @brief Returns a new autoreleased label with the given text and font
 
 For details see ICLabel::initWithText:font:.
 */
+ (id)labelWithText:(NSString *)text font:(ICFont *)font;

/**
 @brief Returns a new autoreleased label with the given text, using a font defined by
 the specified font name and size
 
 For details see ICLabel::initWithText:fontName:fontSize:.
 */
+ (id)labelWithText:(NSString *)text fontName:(NSString *)fontName fontSize:(CGFloat)fontSize;

/**
 @brief Initializes the receiver with default values and empty text
 
 This method initializes the receiver with size (0,0) and a ``nil`` text value. Default values for
 font, color and gamma as described in ICLabel::initWithSize: are implied. In order to display
 text on the receiver, you must set the ICLabel::text or ICLabel::attributedText property after
 initialization is complete.
 */
- (id)init;

/**
 @brief Initializes the receiver with the given size
 
 @param size The size to initialize the receiver with
 
 In addition to the given size, this method initializes the receiver with a default system font
 (using ICFont::systemFontWithDefaultSize) and default values for the color and gamma properties.
 */
- (id)initWithSize:(CGSize)size;

/**
 @brief Initializes the receiver with the given size and attributed text
 */
- (id)initWithSize:(CGSize)size attributedText:(NSAttributedString *)attributedText;

/**
 @brief Initializes the receiver with the given text
 
 @param text The text displayed by the receiver
 
 Default values for font, color and gamma as described in ICLabel::initWithSize: are implied.
 */
- (id)initWithText:(NSString *)text;

/**
 @brief Initializes the receiver with the given text and font
 
 @param text The text displayed by the receiver
 @param font An ICFont object defining the font to be used for displaying text
 
 Default values for color and gamma as described in ICLabel::initWithSize: are implied.
 */
- (id)initWithText:(NSString *)text font:(ICFont *)font;

/**
 @brief Initializes the receiver with the given text and font defined by the specified font
 name and size

 @param text The text displayed by the receiver
 @param fontName The name of the font used by the receiver
 @param fontSize The size in points of the font used by the receiver

 This method resizes the receiver to the bounds of ``text`` and set's the receiver's
 ICLabel::autoresizesToTextSize property to ``YES``.

 Default values for color and gamma as described in ICLabel::initWithSize: are implied.
 */
- (id)initWithText:(NSString *)text fontName:(NSString *)fontName fontSize:(CGFloat)fontSize;


#pragma mark - Manipulating the Label's Text, Font and Color
/** @name Manipulating the Label's Text, Font and Color */

/**
 @brief Whether the receiver autoresizes itself to the contents of its ICLabel::text
 */
@property (nonatomic, assign) BOOL autoresizesToTextSize;

/**
 @brief The text displayed by the receiver
 
 If you set this property to a new value on a receiver that currently displays attributed text,
 the attributes previously set on ICLabel::attributedText will be lost. In this case, the receiver
 will use its font, color and gamma properties to display its text.
 */
@property (nonatomic, copy, setter=setText:) NSString *text;

/**
 @brief The attributed text displayed by the receiver
 
 Setting this property implicitly sets ICLabel::text to ``attributedText``'s string.
 The receiver's font, color and gamma properties will be set to the first corresponding attribute
 found in ``attributedText``.
 */
@property (nonatomic, copy, setter=setAttributedText:) NSAttributedString *attributedText;

/**
 @brief The font used by the receiver to display text

 Setting a new font on a receiver that currently displays attributed text will rebuild the
 receiver's attributed text using its current font, color and gamma properties. Information
 stored in the attributed text to define rich text attributes will be lost.
 */
@property (nonatomic, retain, setter=setFont:) ICFont *font;

/**
 @brief The name of the font used by the receiver to display text
 
 Setting a new font on a receiver that currently displays attributed text will rebuild the
 receiver's attributed text using its current font, color and gamma properties. Information
 stored in the attributed text to define rich text attributes will be lost.
 */
@property (nonatomic, copy, setter=setFontName:) NSString *fontName;

/**
 @brief The size in points of the font used by the receiver to display text

 Setting a new font on a receiver that currently displays attributed text will rebuild the
 receiver's attributed text using its current font, color and gamma properties. Information
 stored in the attributed text to define rich text attributes will be lost.
 */
@property (nonatomic, assign, setter=setFontSize:) CGFloat fontSize;

/**
 @brief The tracking of the receiver's text
 
 Setting a new tracking value on a receiver that currently displays attributed text will rebuild the
 receiver's attributed text using its current font, color and gamma properties. Information
 stored in the attributed text to define rich text attributes will be lost.
 */
@property (nonatomic, assign, setter=setTracking:) float tracking;

/**
 @brief The color of the receiver's text

 Setting a new color on a receiver that currently displays attributed text will rebuild the
 receiver's attributed text using its current font, color and gamma properties. Information
 stored in the attributed text to define rich text attributes will be lost.
 */
@property (nonatomic, assign, setter=setColor:) icColor4B color;

/**
 @brief The gamma value of the receiver's text
 
 Setting a new gamma value on a receiver that currently displays attributed text will rebuild the
 receiver's attributed text using its current font, color and gamma properties. Information
 stored in the attributed text to define rich text attributes will be lost. 
 */
@property (nonatomic, assign, setter=setGamma:) float gamma;

@end
