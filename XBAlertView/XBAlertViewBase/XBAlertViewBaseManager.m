//
//  XBAlertViewBaseManager.m
//  AlertViewTest
//
//  Created by xxb on 2017/8/15.
//  Copyright © 2017年 xxb. All rights reserved.
//

#import "XBAlertViewBaseManager.h"
#import "UIView+Animation.h"

//屏幕宽高
#define kScreenWidth        [UIScreen mainScreen].bounds.size.width
#define kScreenHeight       [UIScreen mainScreen].bounds.size.height

#define kAnimationTime (0.3)

@interface XBAlertViewBaseManager ()
{
    CGFloat lastAngle;
}
@end

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
- (instancetype)init
{
    if (self = [super init])
    {
        static dispatch_once_t onceToken;
        dispatch_once(&onceToken, ^{
            [self addNoticeAtInit_base];
        });
    }
    return self;
}


-(void)addNoticeAtInit_base
{
    //添加通知获取设备发生旋转时的相关信息
    [[UIDevice currentDevice] beginGeneratingDeviceOrientationNotifications];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(deviceOrientationDidChange:)
                                                 name:UIDeviceOrientationDidChangeNotification
                                               object:nil];
}

- (void)removeNotification_base
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

-(void)dealloc
{
    [self removeNotification_base];
}


- (void)deviceOrientationDidChange:(NSNotification *)notification
{
    UIInterfaceOrientation stateNoworientation = [[UIApplication sharedApplication] statusBarOrientation];
    
    dispatch_async(dispatch_get_main_queue(), ^{
        CGFloat angle = 0;
        if (stateNoworientation == UIInterfaceOrientationPortrait)
        {
            angle = 0;
        }
        else if (stateNoworientation ==  UIDeviceOrientationPortraitUpsideDown)
        {
            angle = 180;
        }
        else if (stateNoworientation == UIInterfaceOrientationLandscapeRight)
        {
            angle = 90;
        }
        else
        {
            angle = 270;
        }
        
        CGFloat angleTemp = angle - lastAngle;
        
        [self.window xb_makeRotationWithAngle:angleTemp duration:(angleTemp == 180 || angleTemp == -180)? kAnimationTime * 2 : kAnimationTime];
        
        lastAngle = angle;
    });
}
- (void)resetRotation
{
    [self.window xb_makeRotationWithAngle:-lastAngle duration:0];
}

- (UIWindow *)window
{
    if (_window == nil)
    {
        UIWindow *window = [[UIWindow alloc] init];
        window.windowLevel = 2000;
        window.hidden = NO;
        [window makeKeyWindow];
        window.backgroundColor = [UIColor clearColor];
        
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
