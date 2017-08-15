//
//  XBAlertViewBaseManager.h
//  AlertViewTest
//
//  Created by xxb on 2017/8/15.
//  Copyright © 2017年 xxb. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface XBAlertViewBaseManager : NSObject
@property (nonatomic, strong) NSMutableArray *arrM_alertViews;
@property (nonatomic,strong) UIWindow *window;
+ (instancetype)shared;
@end
