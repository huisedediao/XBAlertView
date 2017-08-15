//
//  XBAlertViewBase+Queue.m
//  AlertViewTest
//
//  Created by xxb on 2017/8/15.
//  Copyright © 2017年 xxb. All rights reserved.
//

#import "XBAlertViewBase+Queue.h"
#import <objc/message.h>
#import "XBAlertViewBaseManager.h"

#define KAnimationTime (0.4)

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
    [[UIApplication sharedApplication].delegate window].userInteractionEnabled = NO;
    [XBAlertViewBaseManager shared].window.hidden = NO;
    
    XBAlertViewBase *alertView = [XBAlertViewBaseManager shared].arrM_alertViews.lastObject;
    [alertView logHidden];
    [[XBAlertViewBaseManager shared].arrM_alertViews addObject:self];
    
    CGFloat time = 0;
    if (alertView)
    {
        time = KAnimationTime;
    }
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(time * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [self logShow];
    });
}
- (void)logHidden
{
    [self logHidden];
    NSMutableArray *arrM_alertViews = [XBAlertViewBaseManager shared].arrM_alertViews;
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
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(KAnimationTime * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            [XBAlertViewBaseManager shared].window.hidden = YES;
            [[UIApplication sharedApplication].delegate window].userInteractionEnabled = YES;
        });
    }
}
@end
