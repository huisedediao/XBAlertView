//
//  XBAlertViewManager.h
//  d11
//
//  Created by xxb on 2017/8/17.
//  Copyright © 2017年 DreamCatcher. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface XBAlertViewManager : NSObject

@property (nonatomic, strong) NSMutableArray *arrM_alertViews;

@property (nonatomic,strong) UIWindow *window;

@property (atomic,assign) BOOL b_keepShow;

+ (instancetype)shared;

@end