//
//  XBAlertView_progress.m
//  D11Module
//
//  Created by xxb on 2017/7/17.
//  Copyright © 2017年 xxb. All rights reserved.
//

#import "XBAlertView_progress.h"
#import "XBCircleProgressView.h"
#import "XBHeader.h"

@interface XBAlertView_progress ()<XBCircleProgressViewDelegate>

@property (nonatomic,strong) XBCircleProgressView *progressView;
@end

@implementation XBAlertView_progress

- (id)initWithDisplayView:(id)displayView
{
    if (self = [super initWithDisplayView:displayView])
    {
    
    }
    return self;
}

- (void)dealloc
{
    NSLog(@"XBAlertView_progress销毁");
}

- (void)show
{
    [self customView:self.progressView size:CGSizeMake(GWidthAdjust_ip6(100), GHeightAdjust_ip6(100))];
    [super show];
}
- (void)hidden
{
    [self.progressView stopAnimation];
    [super hidden];
}

- (void)progressViewDidEndAnimation:(XBCircleProgressView *)progressView
{
    if ([self.delegate respondsToSelector:@selector(alertViewDidEndAnimation:)])
    {
        [self.delegate alertViewDidEndAnimation:self];
    }
    [self hidden];
}

- (XBCircleProgressView *)progressView
{
    if (_progressView == nil)
    {
        XBCircleProgressView *progressView = [XBCircleProgressView new];
        progressView.aniMode = AnimationMode_subduction;
        progressView.waitTime = 15;
        progressView.delegate = self;
        [progressView startAnimation];
        
        _progressView = progressView;
    }
    return _progressView;
}
@end
