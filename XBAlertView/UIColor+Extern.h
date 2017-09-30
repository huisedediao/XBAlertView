//
//  UIColor+Extern.h
//  smanos
//
//  Created by sven on 3/28/16.
//  Copyright © 2016 sven. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (Extern)

+ (UIColor *)colorWithHexString:(NSString *)color;

//从十六进制字符串获取颜色，
//color:支持@“#123456”、 @“0X123456”、 @“123456”三种格式
+ (UIColor *)colorWithHexString:(NSString *)color alpha:(CGFloat)alpha;

@end
