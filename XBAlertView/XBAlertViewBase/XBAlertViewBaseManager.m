//
//  XBAlertViewBaseManager.m
//  AlertViewTest
//
//  Created by xxb on 2017/8/15.
//  Copyright © 2017年 xxb. All rights reserved.
//

#import "XBAlertViewBaseManager.h"

@implementation XBAlertViewBaseManager

+ (instancetype)shared
{
    return [self new];
}
+ (instancetype)allocWithZone:(struct _NSZone *)zone
{
    static XBAlertViewBaseManager *manager = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        manager = [super allocWithZone:zone];
    });
    return manager;
}
- (UIWindow *)window
{
    if (_window == nil)
    {
        UIWindow *window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
        window.windowLevel = 2000;
        window.hidden = NO;
        [window makeKeyWindow];
        
        _window = window;
    }
    return _window;
}
- (NSMutableArray *)arrM_alertViews
{
    if (_arrM_alertViews == nil)
    {
        _arrM_alertViews = [NSMutableArray new];
    }
    return _arrM_alertViews;
}
@end
