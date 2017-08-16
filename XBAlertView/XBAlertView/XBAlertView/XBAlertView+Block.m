//
//  XBAlertView+Block.m
//  ip116_plus
//
//  Created by xxb on 2017/8/15.
//  Copyright © 2017年 DreamCatcher. All rights reserved.
//

#import "XBAlertView+Block.h"

#import <objc/runtime.h>

@interface XBAlertView () <XBAlertViewDelegate>

@property (copy, nonatomic) void (^block)(XBAlertView *XBAlertView, NSInteger buttonIndex);

@end

@implementation XBAlertView (Block)

- (instancetype)initWithTitle:(NSString *)title message:(NSString *)message
            cancelButtonTitle:(NSString *)cancelButtonTitle
            otherButtonTitles:(NSArray *)otherButtonTitles
{
    self = [self initWithTitle:title message:message delegate:nil cancelButtonTitle:cancelButtonTitle otherButtonTitles:otherButtonTitles];
    return self;
}
- (instancetype)initWithMessage:(NSString *)message
              cancelButtonTitle:(NSString *)cancelButtonTitle
              otherButtonTitles:(NSArray *)otherButtonTitles
{
    NSString *title = [NSBundle mainBundle].localizedInfoDictionary[@"CFBundleDisplayName"];
    return [self initWithTitle:title message:message
             cancelButtonTitle:cancelButtonTitle otherButtonTitles:otherButtonTitles];
}
- (instancetype)initWithMessage:(NSString *)message
              cancelButtonTitle:(NSString *)cancelButtonTitle
{
    return [self initWithMessage:message
               cancelButtonTitle:cancelButtonTitle otherButtonTitles:nil];
}
- (instancetype)initWithTitle:(NSString *)title message:(NSString *)message
            cancelButtonTitle:(NSString *)cancelButtonTitle
{
    return [self initWithTitle:title message:message
             cancelButtonTitle:cancelButtonTitle otherButtonTitles:nil];
}
- (instancetype)initWithTitle:(NSString *)title message:(NSString *)message
            cancelButtonTitle:(NSString *)cancelButtonTitle
             otherButtonTitle:(NSString *)otherButtonTitle
{
    return [self initWithTitle:title message:message
             cancelButtonTitle:cancelButtonTitle
             otherButtonTitles:@[otherButtonTitle]];
}


- (void)setBlock:(void (^)(UIAlertView *, NSInteger))block
{
    objc_setAssociatedObject(self, @selector(block), block, OBJC_ASSOCIATION_COPY_NONATOMIC);
}

- (void (^)(UIAlertView *, NSInteger))block
{
    return objc_getAssociatedObject(self, @selector(block));
}

- (void)showUsingBlock:(void (^)(XBAlertView *, NSInteger))block
{
    self.delegate = self;
    self.block = block;
    
    [self show];
}

- (void)alertView:(XBAlertView *)alertView clickedBtnAtIndex:(NSInteger)btnIndex
{
    if (self.block) {
        self.block(alertView, btnIndex);
    }
}

@end
