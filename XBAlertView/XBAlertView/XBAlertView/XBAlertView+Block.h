//
//  XBAlertView+Block.h
//  ip116_plus
//
//  Created by xxb on 2017/8/15.
//  Copyright © 2017年 DreamCatcher. All rights reserved.
//

#import "XBAlertView.h"

@interface XBAlertView (Block)
- (instancetype)initWithMessage:(NSString *)message
              cancelButtonTitle:(NSString *)cancelButtonTitle;
- (instancetype)initWithTitle:(NSString *)title message:(NSString *)message
            cancelButtonTitle:(NSString *)cancelButtonTitle;
- (instancetype)initWithTitle:(NSString *)title message:(NSString *)message
            cancelButtonTitle:(NSString *)cancelButtonTitle
             otherButtonTitle:(NSString *)otherButtonTitle;
- (void)showUsingBlock:(void (^)(XBAlertView *alertView, NSInteger index))block;
@end
