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
@optional
- (void)alertViewDidEndAnimation:(XBAlertView *_Nullable)alertView;

@end

@interface XBAlertView : XBAlertViewBase

@property (nonatomic,strong) UILabel * _Nonnull lb_title;
@property (nonatomic,strong) UILabel * _Nonnull lb_message;

///自定义view的背景view，用来先占位置的
@property (nonatomic,strong) UIView * _Nullable v_customViewBG;
@property (nonatomic,strong) UIView * _Nullable v_custom;

///分割线颜色
@property (nonatomic,strong) UIColor * _Nullable color_partingLine;

@property (nonatomic,copy,readonly) NSString * _Nullable str_title;
@property (nonatomic,copy,readonly) id _Nullable str_message;

@property (nonatomic,strong,readonly) NSMutableArray * _Nullable arr_buttonTitles;


@property (nonatomic,strong) UIColor * _Nullable color_btnTitle_nor;
@property (nonatomic,strong) UIColor * _Nullable color_btnTitle_prominent;
@property (nonatomic,strong) UIColor * _Nullable color_btnBG_nor;
@property (nonatomic,strong) UIColor * _Nullable color_btnBG_prominent;

@property (nonatomic,strong) NSArray * _Nullable arr_prominentIndexs;

@property (nonatomic,weak) _Nullable id<XBAlertViewDelegate> delegate;

- (UIButton *_Nullable)buttonAtIndex:(NSInteger)index;

///自定义的view(只需设置size)
- (void)customView:(UIView *_Nullable)customView size:(CGSize)size;

- (instancetype _Nullable )initWithTitle:(nullable NSString *)title message:(nullable id)message delegate:(nullable id)delegate cancelButtonTitle:(nullable NSString *)cancelButtonTitle otherButtonTitles:(nullable NSArray *)otherButtonTitles;

//- (instancetype _Nullable )initWithTitle:(nullable NSString *)title message:(nullable id)message delegate:(nullable id)delegate cancelButtonTitle:(nullable NSString *)cancelButtonTitle otherButtonTitles:(NSString *)otherButtonTitles,...__attribute__((sentinel));
    
@end
