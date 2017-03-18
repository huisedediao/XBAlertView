//
//  XBAlertView.m
//  XBAlertView
//
//  Created by XXB on 16/7/11.
//  Copyright © 2016年 XXB. All rights reserved.
//

#import "XBAlertView.h"
#import "Masonry.h"

#define XBWeakSelf __weak __typeof(&*self)xbWeakSelf = self;
#define STR(x) NSLocalizedString(x,nil)
#define kScreenWidth [UIScreen mainScreen].bounds.size.width
#define kScreenHeight [UIScreen mainScreen].bounds.size.height
#define kSelfWidth (kScreenWidth-30)

@interface XBAlertView ()
@property (nonatomic,assign) CGFloat buttonHeight;
@end

@implementation XBAlertView

- (instancetype)initWithTitle:(nullable NSString *)title subTitle:(nullable NSString *)subTitle okButtonTitle:(nullable NSString *)okButtonTitle  cancelButtonTitle:(nullable NSString *)cancelButtonTitle okBlock:(nullable OkEventBlock)okBlock cancelBlock:(nullable CancelEventBlock)cancelBlock
{
    XBAlertView *alertV = [XBAlertView alertView];
    NSLog(@"init-%@\r",alertV);
    alertV.title = title;
    alertV.subTitle = subTitle;
    alertV.cancelBlock = cancelBlock;
    alertV.okBlock = okBlock;
    alertV.isOnce = YES;
    [alertV.okBtn setTitle:okButtonTitle forState:UIControlStateNormal];
    [alertV.cancelBtn setTitle:cancelButtonTitle forState:UIControlStateNormal];
    
    return alertV;
}

+(XBAlertView *)alertView
{
    XBAlertView *alertV=[[XBAlertView alloc] initWithDisplayView:[[UIApplication sharedApplication].delegate window]];
    alertV.hideWhileTouchOtherArea=NO;
    [alertV mas_makeConstraints:^(MASConstraintMaker *make) {
        make.center.equalTo(alertV.displayView);
        make.width.mas_equalTo(kSelfWidth);
    }];
    return alertV;
}

-(instancetype)init
{
    if (self=[super init])
    {
        [self setupSubviews];
        [self initParams];
        [self setSubviewsLayout];
    }
    return self;
}


-(void)setupSubviews
{
    self.titleLabel=[UILabel new];
    [self addSubview:self.titleLabel];
    self.titleLabel.text=@"hehe";
    
    self.subTitleLabel=[UILabel new];
    [self addSubview:self.subTitleLabel];
    self.subTitleLabel.text=@"hah";
    
    self.lineViewH=[UIView new];
    [self addSubview:self.lineViewH];
    
    self.lineViewV=[UIView new];
    [self addSubview:self.lineViewV];
    
    self.okBtn=[UIButton buttonWithType:UIButtonTypeCustom];
    [self addSubview:self.okBtn];
    
    self.cancelBtn=[UIButton buttonWithType:UIButtonTypeCustom];
    [self addSubview:self.cancelBtn];
}


-(void)initParams
{
    self.buttonHeight=40;
    
    self.backgroundColor=[UIColor whiteColor];
    self.layer.cornerRadius=5;
    self.clipsToBounds=YES;
    self.fadeInFadeOut=YES;
    
    self.titleLabel.textAlignment=NSTextAlignmentCenter;
    self.titleLabel.numberOfLines=0;
    
    self.subTitleLabel.textAlignment=NSTextAlignmentCenter;
    self.subTitleLabel.font=[UIFont systemFontOfSize:15];
    self.subTitleLabel.numberOfLines=0;
    
    self.lineViewH.backgroundColor=[[UIColor grayColor] colorWithAlphaComponent:0.2];
    self.lineViewV.backgroundColor=[[UIColor grayColor] colorWithAlphaComponent:0.2];
    
    [self.okBtn setTitle:STR(@"confirm") forState:UIControlStateNormal];
    [self.okBtn setTitleColor:[UIColor orangeColor] forState:UIControlStateNormal];
    [self.okBtn addTarget:self action:@selector(okBtnClick:) forControlEvents:UIControlEventTouchUpInside];
    self.okBtn.titleLabel.font=[UIFont systemFontOfSize:15];
    
    [self.cancelBtn setTitle:STR(@"cancel") forState:UIControlStateNormal];
    [self.cancelBtn setTitleColor:[UIColor grayColor] forState:UIControlStateNormal];
    [self.cancelBtn addTarget:self action:@selector(cancelBtnClick:) forControlEvents:UIControlEventTouchUpInside];
    self.cancelBtn.titleLabel.font=[UIFont systemFontOfSize:15];
}


-(void)setSubviewsLayout
{
    [self.titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self).offset(15);
        make.leading.equalTo(self);
        make.width.mas_equalTo(kSelfWidth);
    }];
    
    [self.subTitleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.titleLabel.mas_bottom).offset(10);
        make.centerX.equalTo(self.titleLabel);
        make.width.mas_equalTo(kSelfWidth-30);
    }];
    
    [self.lineViewH mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.subTitleLabel.mas_bottom).offset(10);
        make.leading.equalTo(self);
        make.trailing.equalTo(self);
        make.height.mas_equalTo(0.5);
    }];
    
    [self.lineViewV mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.lineViewH.mas_bottom).offset(0);
        make.centerX.equalTo(self.lineViewH);
        make.height.mas_equalTo(self.buttonHeight);
        make.width.mas_equalTo(0.5);
    }];
    
    [self.cancelBtn mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.equalTo(self);
        make.trailing.equalTo(self.lineViewV.mas_leading);
        make.top.equalTo(self.lineViewH.mas_bottom);
        make.height.mas_equalTo(self.buttonHeight);
        make.bottom.lessThanOrEqualTo(self).offset(-0);
    }];
    
    [self.okBtn mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.cancelBtn);
        make.leading.equalTo(self.lineViewV.mas_trailing);
        make.trailing.equalTo(self);
        make.height.equalTo(self.cancelBtn);
    }];
}

#pragma mark - 方法重写
-(void)setTitle:(NSString *)title
{
    _title=title;
    
    self.titleLabel.text=title;
}
-(void)setSubTitle:(NSString *)subTitle
{
    _subTitle=subTitle;
    
    self.subTitleLabel.text=subTitle;
}

-(void)show
{
    [self layoutIfNeeded];
    XBWeakSelf
    self.showLayoutBlock=^(XBAlertViewBase *alertView){
        xbWeakSelf.frame=xbWeakSelf.frame;
//        xbWeakSelf.alpha=1;
//        xbWeakSelf.backgroundView.alpha=1;
    };
    self.hiddenLayoutBlock=^(XBAlertViewBase *alertView){
        xbWeakSelf.frame=xbWeakSelf.frame;
//        xbWeakSelf.alpha=0;
//        xbWeakSelf.backgroundView.alpha=0;
    };
    
    [super show];
}

-(void)hidden
{
    [super hidden];
    if (self.isOnce) {
        [self removeFromSuperview];
    }
}


-(void)setOkBtnIsLeftSide:(BOOL)okBtnIsLeftSide
{
    _okBtnIsLeftSide=okBtnIsLeftSide;
    
    if (self.singleBtn==YES)
    {
        return;
    }
    
    if (okBtnIsLeftSide==NO)
    {
        return;
    }
    
    [self.okBtn setTitle:STR(@"cancel") forState:UIControlStateNormal];
    [self.okBtn setTitleColor:[UIColor grayColor] forState:UIControlStateNormal];
    [self.okBtn removeTarget:self action:@selector(okBtnClick:) forControlEvents:UIControlEventTouchUpInside];
    [self.okBtn addTarget:self action:@selector(cancelBtnClick:) forControlEvents:UIControlEventTouchUpInside];
    
    [self.cancelBtn setTitle:STR(@"confirm") forState:UIControlStateNormal];
    [self.cancelBtn setTitleColor:[UIColor orangeColor] forState:UIControlStateNormal];
    [self.cancelBtn removeTarget:self action:@selector(cancelBtnClick:) forControlEvents:UIControlEventTouchUpInside];
    [self.cancelBtn addTarget:self action:@selector(okBtnClick:) forControlEvents:UIControlEventTouchUpInside];
}

-(void)setSingleBtn:(BOOL)singleBtn
{
    _singleBtn=singleBtn;
    
    if (self.okBtnIsLeftSide==YES)
    {
        return;
    }
    
    if (singleBtn==NO)
    {
        return;
    }
    
    self.lineViewH.hidden=YES;
    self.lineViewV.hidden=YES;
    
    //清除约束
    self.cancelBtn.hidden=YES;
    
    self.okBtn.backgroundColor=[UIColor orangeColor];
    self.okBtn.layer.cornerRadius=5;
    self.okBtn.clipsToBounds=YES;
    [self.okBtn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [self.okBtn mas_remakeConstraints:^(MASConstraintMaker *make) {
        make.leading.equalTo(self).offset(30);
        make.trailing.equalTo(self).offset(-30);
        make.top.equalTo(self.lineViewH.mas_bottom).offset(10);
        make.height.mas_equalTo(self.buttonHeight);
        make.bottom.lessThanOrEqualTo(self).offset(-10);
    }];
}

-(void)setDoNotshowTitle:(BOOL)doNotshowTitle
{
    _doNotshowTitle=doNotshowTitle;
    
    if (doNotshowTitle==YES)
    {
        self.titleLabel.hidden=YES;
        self.subTitleLabel.font=[UIFont systemFontOfSize:17];
        [self.subTitleLabel mas_updateConstraints:^(MASConstraintMaker *make) {
            make.top.equalTo(self.titleLabel);
        }];
    }
}


#pragma mark - 点击事件
-(void)okBtnClick:(UIButton *)button
{
    if (self.okBlock)
    {
        XBWeakSelf
        self.okBlock(xbWeakSelf);
    }
}
-(void)cancelBtnClick:(UIButton *)button
{
    [self hidden];
    if (self.cancelBlock)
    {
        XBWeakSelf
        self.cancelBlock(xbWeakSelf);
    }
}
@end
