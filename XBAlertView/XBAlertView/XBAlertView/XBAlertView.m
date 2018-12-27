//
//  XBAlertView.m
//  D11Module
//
//  Created by xxb on 2017/7/12.
//  Copyright © 2017年 xxb. All rights reserved.
//

#import "XBAlertView.h"
#import "Masonry.h"
#import "XBAlertViewConfig.h"
#import "XBAlertViewManager.h"

@interface XBAlertView ()
@property (nonatomic,assign) BOOL actionBeforeShowRunned;
@end

@implementation XBAlertView

-(instancetype)initWithFrame:(CGRect)frame
{
    if (self = [super initWithFrame:frame])
    {
        self.layer.cornerRadius = 8;
        self.clipsToBounds = YES;
        self.hideWhileTouchOtherArea = NO;
        self.fadeInFadeOut = YES;
        self.needAdaptKeyboard = YES;
        [self mas_makeConstraints:^(MASConstraintMaker *make) {
            make.width.greaterThanOrEqualTo(@(KSpaceToBorder * 2));
        }];
        _arr_buttonTitles = [NSMutableArray new];
    }
    return self;
}

- (instancetype)initWithTitle:(nullable NSString *)title message:(nullable id)message delegate:(nullable id)delegate cancelButtonTitle:(nullable NSString *)cancelButtonTitle otherButtonTitles:(nullable NSArray *)otherButtonTitles
{
    UIWindow *window = [XBAlertViewManager shared].window;
    if (self = [super initWithDisplayView:window])
    {
        _str_title = title;
        _str_message = message;
        self.delegate = delegate;
        if (cancelButtonTitle.length)
        {
            [self.arr_buttonTitles addObject:cancelButtonTitle];
        }
        if (otherButtonTitles.count)
        {
            [self.arr_buttonTitles addObjectsFromArray:otherButtonTitles];
        }
        switch (self.arr_buttonTitles.count)
        {
            case 1:
                self.arr_prominentIndexs = @[@0];
                break;
            case 2:
                self.arr_prominentIndexs = @[@1];
                break;
                
            default:
                break;
        }
    }
    return self;
}

- (void)customView:(UIView *)customView size:(CGSize)size
{
    self.v_custom = customView;
    if (customView)
    {
        [self.v_customViewBG addSubview:customView];
        [customView mas_remakeConstraints:^(MASConstraintMaker *make) {
            make.top.leading.equalTo(self.v_customViewBG);
            make.bottom.lessThanOrEqualTo(self.v_customViewBG).offset(0);
            make.trailing.lessThanOrEqualTo(self.v_customViewBG).offset(0);
            make.size.mas_equalTo(size);
        }];
    }
}

- (UIButton *)buttonAtIndex:(NSInteger)index
{
    if (index > self.arr_buttonTitles.count - 1 || index < 0)
    {
        return nil;
    }
    return [self viewWithTag:kXBAlertViewTagBase + index];
}


#pragma mark - 方法重写
- (void)actionBeforeShow
{
    if (self.actionBeforeShowRunned == YES)
    {
        return;
    }
    self.actionBeforeShowRunned = YES;
    //创建button
    if (self.arr_buttonTitles.count < 1)
    {
        [self.v_customViewBG mas_updateConstraints:^(MASConstraintMaker *make) {
            make.bottom.lessThanOrEqualTo(self).offset(0);
        }];
    }
    else if (self.arr_buttonTitles.count < 2)//只有一个按钮
    {
        [self createButtonForOne];
    }
    else if (self.arr_buttonTitles.count < 3)//有两个按钮
    {
        [self createButtonForTwo];
    }
    else //3个及以上个按钮
    {
        [self createButtonForThreeOrMore];
    }
    
    self.showLayoutBlock = ^(XBAlertViewBase *alertView) {
        [alertView mas_remakeConstraints:^(MASConstraintMaker *make) {
            make.width.mas_equalTo(280);
            make.center.equalTo(alertView.superview);
        }];
    };
    
    self.hiddenLayoutBlock = ^(XBAlertViewBase *alertView) {
        [alertView mas_remakeConstraints:^(MASConstraintMaker *make) {
            make.width.mas_equalTo(280);
            make.center.equalTo(alertView.superview);
        }];
    };
}

-(void)hidden
{
    [super hidden];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [self removeFromSuperview];
    });
}

- (void)dealloc
{
    NSLog(@"XBAlertView销毁");
}


#pragma mark - 创建按钮
- (void)createButtonForOne
{
    NSInteger tag = 0;
    UIButton *button = [self createButtonWithTag:tag];
    
    [button mas_remakeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.v_customViewBG.mas_bottom).offset([self getSpaceOfCustomViewAndButton]);
        make.top.greaterThanOrEqualTo(self.lb_title.mas_bottom).offset(25);
        make.leading.trailing.equalTo(self);
        make.height.mas_equalTo(kXBAlertViewButtonHeight);
        make.bottom.lessThanOrEqualTo(self).offset(0);
    }];
    
    UIView *line = [UIView new];
    [button addSubview:line];
    line.backgroundColor = self.color_partingLine;
    [line mas_makeConstraints:^(MASConstraintMaker *make) {
        make.height.mas_equalTo(0.5);
        make.leading.trailing.top.equalTo(button);
    }];
}
- (void)createButtonForTwo
{
    NSInteger tag_1 = 0;
    UIButton *button1 = [self createButtonWithTag:tag_1];
    
    [button1 mas_remakeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.v_customViewBG.mas_bottom).offset([self getSpaceOfCustomViewAndButton]);
        make.top.greaterThanOrEqualTo(self.lb_title.mas_bottom).offset(25);
        make.leading.equalTo(self);
        make.trailing.equalTo(self.mas_centerX);
        make.height.mas_equalTo(kXBAlertViewButtonHeight);
        make.bottom.lessThanOrEqualTo(self).offset(0);
    }];
    
    NSInteger tag_2 = 1;
    UIButton *button2 = [self createButtonWithTag:tag_2];
    
    [button2 mas_remakeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(button1);
        make.leading.equalTo(button1.mas_trailing);
        make.trailing.equalTo(self);
        make.bottom.equalTo(button1);
    }];
    
    //分割线
    UIView *lineH = [UIView new];
    [self addSubview:lineH];
    lineH.backgroundColor = self.color_partingLine;
    [lineH mas_makeConstraints:^(MASConstraintMaker *make) {
        make.height.mas_equalTo(0.5);
        make.leading.trailing.equalTo(self);
        make.top.equalTo(button1);
    }];
    
    UIView *lineV = [UIView new];
    [self addSubview:lineV];
    lineV.backgroundColor = self.color_partingLine;
    [lineV mas_makeConstraints:^(MASConstraintMaker *make) {
        make.width.mas_equalTo(0.5);
        make.centerX.equalTo(self);
        make.height.top.equalTo(button1);
    }];
}
- (void)createButtonForThreeOrMore
{
    if (self.color_btnBG_nor == nil)
    {
        self.color_btnBG_nor = XB_Color_white;
    }
    
    UIView *lastView = nil;
    for (int i = 0; i < self.arr_buttonTitles.count; i++)
    {
        UIView *line = [UIView new];
        [self addSubview:line];
        
        line.backgroundColor = self.color_partingLine ? self.color_partingLine : XB_Color_gray;
        
        [line mas_remakeConstraints:^(MASConstraintMaker *make) {
            if (i == 0)
            {
                make.top.equalTo(self.v_customViewBG.mas_bottom).offset([self getSpaceOfCustomViewAndButton]);
                make.top.greaterThanOrEqualTo(self.lb_title.mas_bottom).offset(25);
            }
            else
            {
                make.top.equalTo(lastView.mas_bottom);
            }
            
            make.leading.trailing.equalTo(self);
            make.height.mas_equalTo(1 / [UIScreen mainScreen].scale);
        }];
        
        UIButton *button = [self createButtonWithTag:i];
        
        [button mas_remakeConstraints:^(MASConstraintMaker *make) {
            make.top.equalTo(line.mas_bottom);
            make.leading.trailing.equalTo(self);
            make.height.mas_equalTo(kXBAlertViewButtonHeight);
            if (i == self.arr_buttonTitles.count - 1)
            {
                make.bottom.lessThanOrEqualTo(self);
            }
        }];
        lastView = button;
    }
}

#pragma mark - 工厂方法
- (UIButton *)createButtonWithTag:(NSInteger)tag
{
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    [self addSubview:button];
    
    button.tag = tag + kXBAlertViewTagBase;
    button.titleLabel.font = XB_Font(18);
    [button setBackgroundImage:[self createImageWithColor:[self getBtnBgColorWithTag:tag]] forState:UIControlStateNormal];
    [button setBackgroundImage:[self createImageWithColor:[[self getBtnBgColorWithTag:tag] colorWithAlphaComponent:0.6]] forState:UIControlStateHighlighted];
    [button setTitleColor:[self getBtnTitleColorWithTag:tag] forState:UIControlStateNormal];
    [button setTitle:self.arr_buttonTitles[tag] forState:UIControlStateNormal];
    [button addTarget:self action:@selector(btnClick:) forControlEvents:UIControlEventTouchUpInside];
    
    return button;
}

#pragma mark - 点击事件
- (void)btnClick:(UIButton *)button
{
    [self hidden];
    if (self.delegate && [self.delegate respondsToSelector:@selector(alertView:clickedBtnAtIndex:)])
    {
        [self.delegate alertView:self clickedBtnAtIndex:button.tag - kXBAlertViewTagBase];
    }
}


#pragma mark - 获取距离

- (CGFloat)getSpaceOfTitleAndMsg
{
    return self.str_title.length ? 5 : 0;
}
- (CGFloat)getSpaceOfMsgAndCustomView
{
    CGFloat len = 0;
    if ([self.str_message isKindOfClass:[NSString class]])
    {
        len = ((NSString *)self.str_message).length;
    }
    else if ([self.str_message isKindOfClass:[NSAttributedString class]])
    {
        len = ((NSAttributedString *)self.str_message).length;
    }
    return len ? 25 : 0;
}
- (CGFloat)getSpaceOfCustomViewAndButton
{
    return self.v_custom ? 30 : 0;
}
- (UIColor *)getBtnTitleColorNor
{
    return self.color_btnTitle_nor ? self.color_btnTitle_nor : XB_color_dark;
}
- (UIColor *)getBtnTitleColorPirminent
{
    return self.color_btnTitle_prominent ? self.color_btnTitle_prominent : XB_Color_white;
}
- (UIColor *)getBtnBGColorNor
{
    return self.color_btnBG_nor ? self.color_btnBG_nor : XB_Color_gray;
}
- (UIColor *)getBtnBGColorPirminent
{
    return self.color_btnBG_prominent ? self.color_btnBG_prominent : XB_Color_blue;
}
- (UIColor *)getBtnBgColorWithTag:(NSInteger)tag
{
    for (NSNumber *number in self.arr_prominentIndexs)
    {
        if ([number integerValue]== tag)
        {
            return [self getBtnBGColorPirminent];
        }
    }
    return [self getBtnBGColorNor];
}
- (UIColor *)getBtnTitleColorWithTag:(NSInteger)tag
{
    for (NSNumber *number in self.arr_prominentIndexs)
    {
        if ([number integerValue]== tag)
        {
            return [self getBtnTitleColorPirminent];
        }
    }
    return [self getBtnTitleColorNor];
}

#pragma mark - 其他方法
- (UIImage *)createImageWithColor:(UIColor*)color
{
    CGRect rect=CGRectMake(0.0f,0.0f,1.0f,1.0f);UIGraphicsBeginImageContext(rect.size);
    
    CGContextRef context=UIGraphicsGetCurrentContext();CGContextSetFillColorWithColor(context, [color CGColor]);
    
    CGContextFillRect(context, rect);
    
    UIImage*theImage=UIGraphicsGetImageFromCurrentImageContext();UIGraphicsEndImageContext();
    return theImage;
}


#pragma mark - 懒加载

- (UILabel *)lb_title
{
    if (_lb_title == nil)
    {
        UILabel *label = [UILabel new];
        [self addSubview:label];
        
        label.textAlignment = NSTextAlignmentCenter;
        label.textColor = XB_color_Black;
        label.font = XB_Font_bold(20);
        label.numberOfLines = 0;
        label.text = self.str_title;
        
        [label mas_remakeConstraints:^(MASConstraintMaker *make) {
            make.top.equalTo(self).offset(25);
            make.leading.equalTo(self).offset(KSpaceToBorder);
            make.trailing.equalTo(self).offset(-KSpaceToBorder);
        }];
        
        _lb_title = label;
    }
    return _lb_title;
}

- (UILabel *)lb_message
{
    if (_lb_message == nil)
    {
        UILabel *label = [UILabel new];
        [self addSubview:label];
        
        label.textAlignment = NSTextAlignmentCenter;
        label.textColor = XB_color_Black;
        label.font = XB_Font(16);
        label.numberOfLines = 0;
        if ([self.str_message isKindOfClass:[NSAttributedString class]])
        {
            label.attributedText = self.str_message;
        }
        else if ([self.str_message isKindOfClass:[NSString class]])
        {
            label.text = self.str_message;
        }
        
        [label mas_remakeConstraints:^(MASConstraintMaker *make) {
            make.top.equalTo(self.lb_title.mas_bottom).offset([self getSpaceOfTitleAndMsg]);
            make.leading.equalTo(self).offset(KSpaceToBorder);
            make.trailing.equalTo(self).offset(-KSpaceToBorder);
        }];
        
        _lb_message = label;
    }
    return _lb_message;
}

- (UIView *)v_customViewBG
{
    if (_v_customViewBG == nil)
    {
        UIView *view = [UIView new];
        [self addSubview:view];
        
        [view mas_remakeConstraints:^(MASConstraintMaker *make) {
            make.top.equalTo(self.lb_message.mas_bottom).offset([self getSpaceOfMsgAndCustomView]);
            make.centerX.equalTo(self);
        }];
        
        _v_customViewBG = view;
    }
    return _v_customViewBG;
}

@end
