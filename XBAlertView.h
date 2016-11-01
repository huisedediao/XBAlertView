//
//  XBAlertView.h
//  XBAlertView
//
//  Created by XXB on 16/7/11.
//  Copyright © 2016年 XXB. All rights reserved.


//example
/*
 -(XBAlertView *)alertV
 {
 if (_alertV==nil)
 {
 _alertV=[XBAlertView alertView];
 //        _alertV.okBtnIsLeftSide=YES;
 //        _alertV.title=@"温习提示";
 //        _alertV.subTitle=@"你大爷的,这是测试文字你大爷的,这是测试文字你大爷的,这是测试文字";
 }
 return _alertV;
 }
 */

#import <UIKit/UIKit.h>
#import "XBAlertViewBase.h"

@class XBAlertView;

typedef void (^OkEventBlock) (XBAlertView *alertV);
typedef void (^CancelEventBlock) (XBAlertView *alertV);

@interface XBAlertView : XBAlertViewBase

@property (strong,nonatomic) UILabel *titleLabel;
@property (strong,nonatomic) UILabel *subTitleLabel;

@property (strong,nonatomic) UIView *lineViewH;
@property (strong,nonatomic) UIView *lineViewV;

@property (strong,nonatomic) UIButton *okBtn;
@property (strong,nonatomic) UIButton *cancelBtn;

@property (copy,nonatomic) NSString *title;
@property (copy,nonatomic) NSString *subTitle;

@property (copy,nonatomic) OkEventBlock okBlock;
@property (copy,nonatomic) CancelEventBlock cancelBlock;

@property (assign,nonatomic) BOOL okBtnIsLeftSide;

/** 只有一个按钮,确定 */
@property (assign,nonatomic) BOOL singleBtn;

/**
 * 不显示title
 */
@property (assign,nonatomic) BOOL doNotshowTitle;

+(XBAlertView *)alertView;
@end
