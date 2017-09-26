//
//  XBAlertViewConfig.h
//  D11Module
//
//  Created by xxb on 2017/7/12.
//  Copyright © 2017年 xxb. All rights reserved.
//

#ifndef XBAlertViewConfig_h
#define XBAlertViewConfig_h

#define kXBAlertViewTagBase (10010)
#define kXBAlertViewButtonHeight (50)

//屏幕宽高
#define ScreenWidth [UIScreen mainScreen].bounds.size.width
#define ScreenHeight [UIScreen mainScreen].bounds.size.height


//根据传入的文字、宽度和字体计算出合适的size (CGSize)
#define getAdjustSizeWith_text_width_font(text,width,font) ({[text boundingRectWithSize:CGSizeMake(width, CGFLOAT_MAX) options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName :font} context:NULL].size;})

#define XB_Color_gray [UIColor colorWithRed:230/255.0 green:230/255.0 blue:230/255.0 alpha:1]
#define XB_Color_blue [UIColor colorWithRed:49/255.0 green:106/255.0 blue:190/255.0 alpha:1]
#define XB_Color_white [UIColor whiteColor]
#define XB_color_Black             [UIColor colorWithRed:77/255.0 green:77/255.0 blue:77/255.0 alpha:1]
#define XB_color_dark             [UIColor colorWithRed:36/255.0 green:42/255.0 blue:62/255.0 alpha:1]

#define XB_Font(x) [UIFont systemFontOfSize:x]
#define XB_Font_bold(x) [UIFont boldSystemFontOfSize:x]

#define XB_GWidthAdjust_ip6(x) ((ScreenWidth / 375) * x)
#define XB_GHeightAdjust_ip6(x) ((ScreenHeight/667) * x)



#endif /* XBAlertViewConfig_h */
