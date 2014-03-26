#import <QuartzCore/QuartzCore.h>
#import <OpenGLES/EAGLDrawable.h>

#import "EAGLView.h"

#define USE_DEPTH_BUFFER 1

// A class extension to declare private methods
@interface EAGLView ()

@property (nonatomic, retain) EAGLContext *context;

- (BOOL) createFramebuffer;
- (void) destroyFramebuffer;

@end

@implementation EAGLView

@synthesize context;

// You must implement this
+ (Class)layerClass
{
    return [CAEAGLLayer class];
}

//The GL view is stored in the nib file. When it's unarchived it's sent -initWithCoder:
- (id)initWithCoder:(NSCoder*)coder
{
    if ((self = [super initWithCoder:coder])) {
        // Get the layer
        CAEAGLLayer *eaglLayer = (CAEAGLLayer *)self.layer;

		int w = 320;
		int h = 480;
		if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 3.2f) { // There is no retina display above 3.2
			UIScreen* mainscr = [UIScreen mainScreen];
			w = mainscr.currentMode.size.width;
			h = mainscr.currentMode.size.height;
		}
		if ((w == 640 && h == 960) || (h == 1136 && w == 640) || (h == 1536 && w == 2048)) { // Retina display (iPhone or iPhone 4-inch or iPad/iPad mini)
			self.contentScaleFactor = 2.0;
			eaglLayer.contentsScale=2;
		}

        eaglLayer.opaque = YES;
        eaglLayer.drawableProperties = [NSDictionary dictionaryWithObjectsAndKeys:[NSNumber numberWithBool:NO],
			 kEAGLDrawablePropertyRetainedBacking,
			 kEAGLColorFormatRGBA8,
			 kEAGLDrawablePropertyColorFormat, nil];
        context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES1];
        if (!context || ![EAGLContext setCurrentContext:context]) {
            //[self release];
            return nil;
        }
        mContext = new drawContext(eaglLayer.contentsScale==2);
    }
    rendering = NO;
    return self;
}

- (void)drawView
{
    if(rendering) return;
    rendering = YES;
    [EAGLContext setCurrentContext:context];
    
    glBindFramebufferOES(GL_FRAMEBUFFER_OES, viewFramebuffer);
    mContext->initView(backingWidth, backingHeight);
    mContext->drawView();
    
    glBindRenderbufferOES(GL_RENDERBUFFER_OES, viewRenderbuffer);
    [context presentRenderbuffer:GL_RENDERBUFFER_OES];
    rendering = NO;
}
- (void)load:(NSString*) file
{
    mContext->load(*new std::string([file fileSystemRepresentation]));
    [[NSNotificationCenter defaultCenter] postNotificationName:@"resetParameters" object:nil];
    [self drawView];
}
- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
    NSUInteger ntouch = [[event allTouches] count];
    UITouch* touch = [touches anyObject];
    CGPoint position = [touch locationInView:self];
	if(ntouch != 1) return;
	if(rotate)
		mContext->eventHandler(3,position.x,position.y);
	else
		mContext->eventHandler(1,position.x,position.y);
    
    [self drawView];
}

- (void)layoutSubviews
{
	[super layoutSubviews];
    [EAGLContext setCurrentContext:context];
    [self destroyFramebuffer];
    [self createFramebuffer];
    [self drawView];
}

- (BOOL)createFramebuffer
{
    glGenFramebuffersOES(1, &viewFramebuffer);
    glGenRenderbuffersOES(1, &viewRenderbuffer);
	
    glBindFramebufferOES(GL_FRAMEBUFFER_OES, viewFramebuffer);
    glBindRenderbufferOES(GL_RENDERBUFFER_OES, viewRenderbuffer);
    [context renderbufferStorage:GL_RENDERBUFFER_OES fromDrawable:(CAEAGLLayer*)self.layer];
    glFramebufferRenderbufferOES(GL_FRAMEBUFFER_OES, GL_COLOR_ATTACHMENT0_OES, GL_RENDERBUFFER_OES, viewRenderbuffer);
    
    glGetRenderbufferParameterivOES(GL_RENDERBUFFER_OES, GL_RENDERBUFFER_WIDTH_OES, &backingWidth);
    glGetRenderbufferParameterivOES(GL_RENDERBUFFER_OES, GL_RENDERBUFFER_HEIGHT_OES, &backingHeight);
    
    if (USE_DEPTH_BUFFER) {
        glGenRenderbuffersOES(1, &depthRenderbuffer);
        glBindRenderbufferOES(GL_RENDERBUFFER_OES, depthRenderbuffer);
        glRenderbufferStorageOES(GL_RENDERBUFFER_OES, GL_DEPTH_COMPONENT16_OES, backingWidth, backingHeight);
        glFramebufferRenderbufferOES(GL_FRAMEBUFFER_OES, GL_DEPTH_ATTACHMENT_OES, GL_RENDERBUFFER_OES, depthRenderbuffer);
    }
    
    if(glCheckFramebufferStatusOES(GL_FRAMEBUFFER_OES) != GL_FRAMEBUFFER_COMPLETE_OES) {
        NSLog(@"failed to make complete framebuffer object %x", glCheckFramebufferStatusOES(GL_FRAMEBUFFER_OES));
        return NO;
    }
    
    return YES;
}

- (void)destroyFramebuffer
{
    glDeleteFramebuffersOES(1, &viewFramebuffer);
    viewFramebuffer = 0;
    glDeleteRenderbuffersOES(1, &viewRenderbuffer);
    viewRenderbuffer = 0;
    if(depthRenderbuffer) {
        glDeleteRenderbuffersOES(1, &depthRenderbuffer);
        depthRenderbuffer = 0;
    }
}

- (void)dealloc
{
    if ([EAGLContext currentContext] == context) {
        [EAGLContext setCurrentContext:nil];
    }
}

- (UIImage*) getGLScreenshot
{
    NSInteger myDataLength = backingWidth * backingHeight * 4;

    GLubyte *buffer = (GLubyte *) malloc(myDataLength);
    glReadPixels(0, 0, backingWidth, backingHeight, GL_RGBA, GL_UNSIGNED_BYTE, buffer);

    GLubyte *buffer2 = (GLubyte *) malloc(myDataLength);
    for(int y = 0; y <backingHeight; y++)
    {
        for(int x = 0; x <backingWidth * 4; x++)
        {
            buffer2[(backingHeight - 1 - y) * backingWidth * 4 + x] = buffer[y * 4 * backingWidth + x];
        }
    }

    CGDataProviderRef provider = CGDataProviderCreateWithData(NULL, buffer2, myDataLength, NULL);

    int bitsPerComponent = 8;
    int bitsPerPixel = 32;
    int bytesPerRow = 4 * backingWidth;
    CGColorSpaceRef colorSpaceRef = CGColorSpaceCreateDeviceRGB();
    CGBitmapInfo bitmapInfo = kCGBitmapByteOrderDefault;
    CGColorRenderingIntent renderingIntent = kCGRenderingIntentDefault;

    CGImageRef imageRef = CGImageCreate(backingWidth, backingHeight, bitsPerComponent, bitsPerPixel, bytesPerRow, colorSpaceRef, bitmapInfo, provider, NULL, NO, renderingIntent);
	free(buffer);
	free(buffer2);
    return [UIImage imageWithCGImage:imageRef];
}

- (void)saveGLScreenshotToPhotosAlbum {
    UIImageWriteToSavedPhotosAlbum([self getGLScreenshot], nil, nil, nil);
}

@end
