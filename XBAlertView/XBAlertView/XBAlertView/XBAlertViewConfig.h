//
//  XBAlertViewConfig.h
//  D11Module
//
//  Created by xxb on 2017/7/12.
//  Copyright © 2017年 xxb. All rights reserved.
//

#ifndef XBAlertViewConfig_h
#define XBAlertViewConfig_h

//1像素线宽
#define SINGLE_LINE_WIDTH           (1 / [UIScreen mainScreen].scale)

#define kXBAlertViewTagBase (10010)
#define kXBAlertViewButtonHeight (50)
#define KContentSpaceToBorder (30)
//屏幕宽高
#define ScreenWidth [UIScreen mainScreen].bounds.size.width
#define ScreenHeight [UIScreen mainScreen].bounds.size.height


//根据传入的文字、宽度和字体计算出合适的size (CGSize)
#define getAdjustSizeWith_text_width_font(text,width,font) ({[text boundingRectWithSize:CGSizeMake(width, CGFLOAT_MAX) options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName :font} context:NULL].size;})

#define XBAlertViewColor_partingLineGray [UIColor colorWithRed:181/255.0 green:181/255.0 blue:181/255.0 alpha:1]
#define XBAlertViewColor_btnBGNor [UIColor colorWithRed:230/255.0 green:230/255.0 blue:230/255.0 alpha:1]
#define XBAlertViewColor_btnBGPro [UIColor colorWithRed:49/255.0 green:106/255.0 blue:190/255.0 alpha:1]

#define XBAlertViewColor_title              [UIColor colorWithRed:77/255.0 green:77/255.0 blue:77/255.0 alpha:1]
#define XBAlertViewColor_msg                [UIColor colorWithRed:77/255.0 green:77/255.0 blue:77/255.0 alpha:1]
#define XBAlertViewColor_btnTitleNor             [UIColor colorWithRed:36/255.0 green:42/255.0 blue:62/255.0 alpha:1]
#define XBAlertViewColor_btnTitlePro      [UIColor whiteColor]

#define XBAlertViewFont(x) [UIFont systemFontOfSize:x]
#define XBAlertViewFont_bold(x) [UIFont boldSystemFontOfSize:x]\



#endif /* XBAlertViewConfig_h */
