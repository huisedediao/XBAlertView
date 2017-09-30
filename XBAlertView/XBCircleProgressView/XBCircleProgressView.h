//
//  XBCircleProgressView.h
//  D11Module
//
//  Created by xxb on 2017/7/12.
//  Copyright © 2017年 xxb. All rights reserved.
//

#import <UIKit/UIKit.h>

@class XBCircleProgressView;

@protocol XBCircleProgressViewDelegate <NSObject>

- (void)progressViewDidEndAnimation:(XBCircleProgressView *)progressView;

@end

typedef enum : NSUInteger {
    AnimationMode_add,              //时间和进度增加
    AnimationMode_subduction        //时间和进度减少
} AnimationMode;

@interface XBCircleProgressView : UIView


@property (nonatomic,weak) id<XBCircleProgressViewDelegate>delegate;

@property (nonatomic,assign) AnimationMode aniMode;
///等待时间（就是动画跑完的时间）
@property (nonatomic,assign) CGFloat waitTime;

- (void)startAnimation;

//父类销毁的时候记得要调用
- (void)stopAnimation;
@end
