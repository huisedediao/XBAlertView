//
//  XBAlertViewBase+Queue.m
//  XBAlertView
//
//  Created by xxb on 2017/8/22.
//  Copyright © 2017年 xxb. All rights reserved.
//

#import "XBAlertViewBase+Queue.h"
#import <objc/message.h>
#import "XBAlertViewManager.h"

#define KAnimationTime (0.25)

@implementation XBAlertViewBase (Queue)

+ (void)load
{
    Method show = class_getInstanceMethod(self, @selector(show));
    Method logShow = class_getInstanceMethod(self, @selector(logShow));
    method_exchangeImplementations(show, logShow);
    
    Method hidden = class_getInstanceMethod(self, @selector(hidden));
    Method logHidden = class_getInstanceMethod(self, @selector(logHidden));
    method_exchangeImplementations(hidden, logHidden);
}

- (void)logShow
{
    if ([self isKindOfClass:NSClassFromString(@"XBAlertView")] == false)
    {
        [self logShow];
        return;
    }
    [[UIApplication sharedApplication].delegate window].userInteractionEnabled = NO;
    [XBAlertViewManager shared].window.hidden = NO;
    
    XBAlertViewBase *alertView = [XBAlertViewManager shared].arrM_alertViews.lastObject;
    [alertView logHidden];
    [[XBAlertViewManager shared].arrM_alertViews addObject:self];
    
    CGFloat timeSpace = [[NSDate date] timeIntervalSince1970] - [XBAlertViewManager shared].lastAlertViewHideOrShowTime;
    CGFloat time = 0;
    if (timeSpace < KAnimationTime)
    {
        time = KAnimationTime;
    }
    [XBAlertViewManager shared].lastAlertViewHideOrShowTime = [[NSDate date] timeIntervalSince1970];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(time * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [XBAlertViewManager shared].b_keepShow = YES;
        [self logShow];
    });
}
- (void)logHidden
{
    if ([self isKindOfClass:NSClassFromString(@"XBAlertView")] == false)
    {
        [self logHidden];
        return;
    }
    [self logHidden];
    [XBAlertViewManager shared].lastAlertViewHideOrShowTime = [[NSDate date] timeIntervalSince1970];
    [XBAlertViewManager shared].b_keepShow = NO;
    NSMutableArray *arrM_alertViews = [XBAlertViewManager shared].arrM_alertViews;
    if (self == arrM_alertViews.lastObject)
    {
        [arrM_alertViews removeObject:self];
    }
    if (arrM_alertViews.count > 0)
    {
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(KAnimationTime * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            [[arrM_alertViews lastObject] logShow];
        });
    }
    else
    {
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(KAnimationTime * 1.1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            if ([XBAlertViewManager shared].b_keepShow == NO)
            {
                [XBAlertViewManager shared].window.hidden = YES;
                [[UIApplication sharedApplication].delegate window].userInteractionEnabled = YES;
            }
        });
    }
}
@end
