//
//  XBAlertView.h
//  D11Module
//
//  Created by xxb on 2017/7/12.
//  Copyright © 2017年 xxb. All rights reserved.
//

#import "XBAlertViewBase.h"

@class XBAlertView;

@protocol XBAlertViewDelegate <NSObject>

- (void)alertView:(XBAlertView *_Nullable)alertView clickedBtnAtIndex:(NSInteger)btnIndex;

@end

@interface XBAlertView : XBAlertViewBase

@property (nonatomic,strong) UILabel * _Nonnull lb_title;
@property (nonatomic,strong) UILabel * _Nonnull lb_message;
@property (nonatomic,strong) UIView * _Nullable v_custom;

@property (nonatomic,strong) UIColor * _Nullable color_partingLine;

@property (nonatomic,copy) NSString * _Nullable str_title;
@property (nonatomic,copy) NSString * _Nullable str_message;

@property (nonatomic,strong) NSMutableArray * _Nullable arr_buttonTitles;

@property (nonatomic,weak) _Nullable id<XBAlertViewDelegate> delegate;

- (UIButton *_Nullable)buttonAtIndex:(NSInteger)index;

///自定义的view(只需设置size)
- (void)customView:(UIView *_Nullable)customView size:(CGSize)size;

- (instancetype _Nullable )initWithTitle:(nullable NSString *)title message:(nullable NSString *)message delegate:(nullable id)delegate cancelButtonTitle:(nullable NSString *)cancelButtonTitle otherButtonTitles:(nullable NSArray *)otherButtonTitles;
@end
