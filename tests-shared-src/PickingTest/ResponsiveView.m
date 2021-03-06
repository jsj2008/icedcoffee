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

#import "ResponsiveView.h"
#import "ResponsiveSprite.h"

@implementation ResponsiveView

- (id)initWithSize:(CGSize)size
{
    if ((self = [super initWithSize:size])) {
        //[self setWantsRenderTextureBacking:YES];
        [self setClipsChildren:YES];
        
        NSString *filename = [[NSBundle mainBundle] pathForResource:@"thiswayup" ofType:@"png"];
        ICTexture2D *texture = [[ICTextureCache currentTextureCache] loadTextureFromFile:filename];        
        ResponsiveSprite *responsiveSprite = [[ResponsiveSprite alloc] initWithTexture:texture];
        [self addChild:responsiveSprite];
        [responsiveSprite release];
    }
    return self;
}

- (void)drawWithVisitor:(ICNodeVisitor *)visitor
{
    [super drawWithVisitor:visitor];
}

- (void)setName:(NSString *)name
{
    [(ICNode *)[[self children] objectAtIndex:0] setName:name];
}

@end
