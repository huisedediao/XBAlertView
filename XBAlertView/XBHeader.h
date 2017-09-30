//
//  XBHeader.h
//  D11Module
//
//  Created by xxb on 2017/7/12.
//  Copyright © 2017年 xxb. All rights reserved.
// 

#ifndef XBHeader_h
#define XBHeader_h

#import "UIColor+Extern.h"


#define WEAK_SELF __typeof(self) __weak weakSelf = self;

//#define kHeightFactor       (ScreenHeight/667.0)
//#define kWidthFactor        (ScreenWidth/375.0)

#define RGBA(r, g, b, a)    [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]
#define RGB(r, g, b)        RGBA(r, g, b, 1.0)


#define PNGIMAGE(NAME)      [UIImage imageNamed:NAME]

/*******************************  block  ********************************/
typedef void (^XBCusBlock) (UITableViewCell *cell);

/*******************************  block  ********************************/



/*******************************  color  ********************************/

#define Color_BackGround            [UIColor colorWithHexString:@"#EBEBF0"]
#define Color_TextColor             [UIColor colorWithHexString:@"#242A3F"]
#define Color_TextColor_Disable     [UIColor colorWithHexString:@"#B3B3B3"]

#define Color_NavBar_BackGround     [UIColor colorWithHexString:@"#2E265C"]
#define Color_Blue                  [UIColor colorWithHexString:@"#36A6EB"]
#define Color_Red                   [UIColor colorWithHexString:@"#EB3636"]

#define Color_Cell_BackGround       [UIColor colorWithHexString:@"#FFFFFF"]
#define Color_Cell_Separator        [UIColor colorWithHexString:@"#CCCCCC"]

#define Color_btn_blue              [UIColor colorWithHexString:@"#4E70D3"]

/*******************************  color  ********************************/




//屏幕宽高
#define ScreenWidth [UIScreen mainScreen].bounds.size.width
#define ScreenHeight [UIScreen mainScreen].bounds.size.height


//根据传入的文字、宽度和字体计算出合适的size (CGSize)
#define getAdjustSizeWith_text_width_font(text,width,font) ({[text boundingRectWithSize:CGSizeMake(width, CGFLOAT_MAX) options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName :font} context:NULL].size;})

//根据传入的文字和字体获取宽度 (CGFloat)
#define getWidthWith_title_font(title,font) ({\
UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(0, 0, 1000, 0)];\
label.text = title;\
label.font = font;\
[label sizeToFit];\
label.frame.size.width;\
})




//========new============

#define D11_DefaultNotiCenter [NSNotificationCenter defaultCenter]

#define D11_defaultRoomID (0)
#define D11_defaultRoomName @"Default"

#define D11_currentGidModel [[DCGidManager sharedInstance] gidModelFromGid:CurrentGid]
#define D11_currentGidModelIsGeneral [D11_currentGidModel.deviceModel.auth isEqualToString:kAccount_general]
#define kAccount_admin    @"admin"    //(管理者)
#define kAccount_advance  @"advance"  //(高级用户)
#define kAccount_general  @"general"  //(一般用户)

//======================================== color ========================================
#define D11_Color_gray                                      [UIColor colorWithHexString:@"#E6E6E6"]
#define D11_Color_blue                                      [UIColor colorWithRed:80/255.0 green:115/255.0 blue:208/255.0 alpha:1]
#define D11_color_Black                                     [UIColor colorWithHexString:@"#4C4C4C"]
#define D11_color_dark                                      [UIColor colorWithHexString:@"#7F7F7F"]
#define D11_Color_bg                                        [UIColor colorWithHexString:@"#242A3D"]//RGB(36,42,62)
#define D11_Color_white                                     [UIColor whiteColor]
#define D11_Color_whiteAlpha40                              [D11_Color_white colorWithAlphaComponent:0.4]
#define D11_color_dark_text                                 [UIColor colorWithHexString:@"#242A3F"]
#define D11_color_text_disable                              [UIColor colorWithHexString:@"#B3B3B3"]
//#define Color_btn_blue              [UIColor colorWithHexString:@"#4E70D3"]
#define D11_Color_red                                       [UIColor colorWithRed:238/255.0 green:37/255.0 blue:64/255.0 alpha:1]  
//======================================== font ========================================
//#define D11_Font(x)                                         [UIFont systemFontOfSize:x]
//#define D11_Font_bold(x)                                    [UIFont boldSystemFontOfSize:x]
#define D11_Font_Text(x)                                    [UIFont systemFontOfSize:x]
#define D11_Font_Title(x)                                   [UIFont systemFontOfSize:x]
#define D11_Font_btn(x)                                     [UIFont systemFontOfSize:x]



//======================================== image ========================================
#define D11_Image_noAccessory                               [UIImage imageNamed:@"d11_accessory_noaccessory"]
#define D11_Image_noRoom                                    [UIImage imageNamed:@"d11_accessory_noroom"]
#define D11_Image_bgColor                                   [UIImage imageWithColor:D11_Color_bg]
#define D11_Image_blueColor                                 [UIImage imageWithColor:D11_Color_blue]
#define D11_Image_clearColor                                [UIImage imageWithColor:[UIColor clearColor]]
#define D11_Image_accessoryEdit                             [UIImage imageNamed:@"d11_accessory_edit01"]
#define D11_Image_accessoryAdd                              [UIImage imageNamed:@"d11_accessory_addaccessory"]
#define D11_Image_accessoryNoSel                            [UIImage imageNamed:@"d11_accessory_select01"]
#define D11_Image_accessorySel                              [UIImage imageNamed:@"d11_accessory_select02"]
#define D11_Image_sensorOffline                             [UIImage imageNamed:@"d11_accessory_offline"]
#define D11_Image_sensorOnline                              [UIImage imageNamed:@"d11_accessory_online"]
#define D11_Image_sensorPower_100                           [UIImage imageNamed:@"d11_accessory_power01"]
#define D11_Image_sensorPower_80                            [UIImage imageNamed:@"d11_accessory_power02"]
#define D11_Image_sensorPower_60                            [UIImage imageNamed:@"d11_accessory_power03"]
#define D11_Image_sensorPower_40                            [UIImage imageNamed:@"d11_accessory_power04"]
#define D11_Image_sensorPower_20                            [UIImage imageNamed:@"d11_accessory_power05"]
#define D11_Image_sensorPower_10                            [UIImage imageNamed:@"d11_accessory_power06"]
#define D11_Image_cellRightIcon                             [UIImage imageNamed:@"d11_accessory_arrow"]
#define D11_Image_cellOpenDoor                              [UIImage imageNamed:@"d11_accessory_opendoor"]
#define D11_Image_roomCellEditWhite                         [UIImage imageNamed:@"d11_accessory_edit01"]
#define D11_Image_roomCellEditBlack                         [UIImage imageNamed:@"d11_accessory_edit02"]
#define D11_Image_accessory_delete                          [UIImage imageNamed:@"d11_accessory_delete"]
#define D11_Image_accessory_edit                            [UIImage imageNamed:@"d11_accessory_edit02"]
#define D11_Image_accessory_choose                          [UIImage imageNamed:@"d11_accessory_choose"]
#define D11_Image_accessory_homezone                        [UIImage imageNamed:@"d11_accessory_homezone"]
#define D11_Image_accessory_24hourzone                      [UIImage imageNamed:@"d11_accessory_24hourzone"]
#define D11_Image_accessory_delayzone                       [UIImage imageNamed:@"d11_accessory_delayzone"]
#define D11_Image_accessory_normalzone                      [UIImage imageNamed:@"d11_accessory_normalzone"]
#define D11_Image_accessory_back_black                      [UIImage imageNamed:@"d11_accessory_back02"]
#define D11_Image_accessory_dwc945_01                       [UIImage imageNamed:@"d11_accessory_dwc945_01"]
#define D11_Image_accessory_dwc945_02                       [UIImage imageNamed:@"d11_accessory_dwc945_02"]
#define D11_Image_accessory_pir945_01                       [UIImage imageNamed:@"d11_accessory_pir945_01"]
#define D11_Image_accessory_pir945_02                       [UIImage imageNamed:@"d11_accessory_pir945_02"]
#define D11_Image_accessory_rc945_01                        [UIImage imageNamed:@"d11_accessory_rc945_01"]
#define D11_Image_accessory_sd945_01                        [UIImage imageNamed:@"d11_accessory_sd945_01"]
#define D11_Image_accessory_sd945_02                        [UIImage imageNamed:@"d11_accessory_sd945_02"]
#define D11_Image_accessory_kb945_01                        [UIImage imageNamed:@"d11_accessory_kp945_01"]
#define D11_Image_accessory_kb945_02                        [UIImage imageNamed:@"d11_accessory_kp945_02"]
#define D11_Image_accessory_kb945_03                        [UIImage imageNamed:@"d11_accessory_kp945_03"]
#define D11_Image_accessory_eyeclose                        [UIImage imageNamed:@"d11_accessory_eyeclose"]
#define D11_Image_accessory_eyeopen                        [UIImage imageNamed:@"d11_accessory_eyeopen"]
#define D11_Image_accessory_ss2800_01                        [UIImage imageNamed:@"h4_accessory_ss2800_01"]
#define D11_Image_accessory_ss2800_02                        [UIImage imageNamed:@"h4_accessory_ss2800_02"]
#define D11_Image_accessory_gb1260_01                        [UIImage imageNamed:@"h4_accessory_gb1260_01"]
#define D11_Image_accessory_gb1260_02                        [UIImage imageNamed:@"h4_accessory_gb1260_02"]
#define D11_Image_accessory_wi20_01                         [UIImage imageNamed:@"h4_accessory_wi20_01"]
#define D11_Image_accessory_aid420_01                         [UIImage imageNamed:@"h4_accessory_aid420_01"]
#define D11_Image_accessory_aid420_02                         [UIImage imageNamed:@"h4_accessory_aid420_02"]
#define D11_Image_accessory_aid420_03                         [UIImage imageNamed:@"h4_accessory_aid420_03"]


//======================================== text ========================================
#define D11_Text_sos                                        NSLocalizedString(@"SOS", nil)
#define D11_Text_RFIDCardType                               NSLocalizedString(@"RFID Tags", nil)
#define D11_Text_noAccessory                                NSLocalizedString(@"No accsessory", nil)
#define D11_Text_noRoom                                     NSLocalizedString(@"No Room", nil)
#define D11_Text_pleaseAddSensor                            NSLocalizedString(@"Please add sensor by pressing add button at top right.", nil)
#define D11_Text_pleaseAddRoom                              NSLocalizedString(@"Please add room by pressing add button at top right.", nil)
#define D11_Text_List                                       NSLocalizedString(@"List", nil)
#define D11_Text_Room                                       NSLocalizedString(@"Room", nil)
#define D11_Text_DeSelectAll                                NSLocalizedString(@"Deselect all", nil)
#define D11_Text_SelectAll                                  NSLocalizedString(@"Select all", nil)
#define D11_Text_Delete                                     NSLocalizedString(@"Delete", nil)
#define D11_Text_Accessories                                NSLocalizedString(@"Accessories", nil)
#define D11_Text_Cancel                                     NSLocalizedString(@"Cancel", nil)
#define D11_Text_sensorOnline                               NSLocalizedString(@"STATUS:Online", nil)
#define D11_Text_sensorOffline                              NSLocalizedString(@"STATUS:Offline", nil)
#define D11_Text_sensorPower                                NSLocalizedString(@"POWER:%zd%", nil)
#define D11_Text_AddAccessory                               NSLocalizedString(@"Add Accessory", nil)
#define D11_Text_AddRoom                                    NSLocalizedString(@"Add Room", nil)
#define D11_Text_Reminder                                   NSLocalizedString(@"Reminder", nil)
#define D11_Text_PleaseChooseRooms                          NSLocalizedString(@"Please choose rooms", nil)
#define D11_Text_PleaseChooseAccessory                      NSLocalizedString(@"Please choose accessory", nil)
#define D11_Text_PleaseTriggerTheAccessory                  NSLocalizedString(@"Please trigger the accessory", nil)
#define D11_Text_TimeOut                                    NSLocalizedString(@"Time out, please try again.", nil)
#define D11_Text_AreYouSureToDeleteThisRoom                 NSLocalizedString(@"Are you sure to delete selected room?It will not delete the accessories linkage with the hub.", nil)
#define D11_Text_AreYouSureToDeleteSelectedAccessories      NSLocalizedString(@"Are you sure to delete selected accessories?", nil)
#define D11_Text_Ok                                         NSLocalizedString(@"Ok", nil)
#define D11_Text_Basement                                   NSLocalizedString(@"Basement", nil)
#define D11_Text_Bedroom                                    NSLocalizedString(@"Bedroom", nil)
#define D11_Text_Bathroom                                   NSLocalizedString(@"Bathroom", nil)
#define D11_Text_LivingRoom                                 NSLocalizedString(@"Living Room", nil)
#define D11_Text_KidsRoom                                   NSLocalizedString(@"Kid's Room", nil)
#define D11_Text_Studyroom                                  NSLocalizedString(@"Study Room", nil)
#define D11_Text_DiningRoom                                 NSLocalizedString(@"Dining Room", nil)
#define D11_Text_Staircase                                  NSLocalizedString(@"Staircase", nil)
#define D11_Text_Enterance                                  NSLocalizedString(@"Enterance", nil)
#define D11_Text_Garage                                     NSLocalizedString(@"Garage", nil)
#define D11_Text_Hallway                                    NSLocalizedString(@"Hallway", nil)
#define D11_Text_Default                                    NSLocalizedString(@"Default", nil)
#define D11_Text_Delete                                     NSLocalizedString(@"Delete", nil)
#define D11_Text_Done                                       NSLocalizedString(@"Done", nil)
#define D11_Text_Zone                                       NSLocalizedString(@"Zone", nil)
#define D11_Text_Room                                       NSLocalizedString(@"Room", nil)
#define D11_Text_NormalZone                                 NSLocalizedString(@"Normal Zone", nil)
#define D11_Text_HomeZone                                   NSLocalizedString(@"Home Zone", nil)
#define D11_Text_DelayZone                                  NSLocalizedString(@"Delay Zone", nil)
#define D11_Text_24HourZone                                 NSLocalizedString(@"24-Hour Zone", nil)
#define D11_Text_Accessories                                NSLocalizedString(@"Accessories", nil)
#define D11_Text_Next                                       NSLocalizedString(@"Next", nil)
#define D11_Text_StartPairing                               NSLocalizedString(@"START PAIRING", nil)
#define D11_Text_RemoveTheBattery                           NSLocalizedString(@"Remove the Battery Tab to power up.", nil)
#define D11_Text_RemoveTheUpper                             NSLocalizedString(@"Remove the upper installation caps of the receiver and the Transmitter and take out the receiver Circuit Board and the Transmitter Circuit Board.", nil)
#define D11_Text_PressAndHoldTheButton                           NSLocalizedString(@"Press and hold the button for 5 senconds to power up. A beep will heard", nil)
#define D11_Text_PlugInTheAdpter                            NSLocalizedString(@"Plug in the adpter to power up.", nil)
#define D11_Text_PressStartPairingThen                      NSLocalizedString(@"Press “START PAIRING”,then click the Button 3 times as shown.", nil)
#define D11_Text_PressStartPairingThenLong                  NSLocalizedString(@"Press “START PAIRING”,then click learning button on the sensor 3 times as shown.Please remain holding the button while process this step.", nil)
#define D11_Text_SlideTheCoverOf                            NSLocalizedString(@"Slide the cover of the Outdoor Keypad and remove the Battery Tap to power up.", nil)
#define D11_Text_OutdoorKeypad                      NSLocalizedString(@"Outdoor Keypad", nil)
#define D11_Text_Location                       NSLocalizedString(@"Location", nil)
#define D11_Text_KeypadPassword                     NSLocalizedString(@"Keypad Password", nil)
#define D11_Text_KeypadPressingTone                      NSLocalizedString(@"Keypad pressing tone", nil)
#define D11_Text_RequirePasswordForSOS                      NSLocalizedString(@"Require password for SOS", nil)
#define D11_Text_RFIDReaderFunction                      NSLocalizedString(@"RFID reader function", nil)
#define D11_Text_DirectArmDisarm                      NSLocalizedString(@"Direct arm/disarm by RFID tag", nil)
#define D11_Text_PairedRFIDTags                     NSLocalizedString(@"Paired RFID tags: %zd", nil)
#define D11_Text_WhetherToInput                     NSLocalizedString(@"Whether to input the password before long pressing the sos[bland] button or not.", nil)
#define D11_Text_IfTurnedOff                        NSLocalizedString(@"If turned off,you are required to press * before swiping the RFID tag.", nil)
#define D11_Text_AddUpTo5Users                        NSLocalizedString(@"Add up to 5 users.", nil)
#define D11_Text_AreYouSureToDeleteTheUser                 NSLocalizedString(@"Are you sure to delete the user?", nil)
#define D11_Text_SwipeTheTag                           NSLocalizedString(@"Swipe the tag on the reader, wait until a beep is heard.", nil)
#define D11_Text_NewRFIDTagHas            NSLocalizedString(@"New RFID tag has been paired. Do you want to name the tag now?", nil)
#define D11_Text_later              NSLocalizedString(@"later", nil)
#define D11_Text_Yes                NSLocalizedString(@"Yes", nil)
#define D11_Text_AreYouSureToDeleteThisTag                NSLocalizedString(@"Are you sure to delete this tag?", nil)
#define D11_Text_AreYouSureToDeleteThisAccessory                NSLocalizedString(@"Are you sure to delete this accessory?", nil)
#define D11_Text_Default                                NSLocalizedString(@"Default", nil)
#define D11_Text_Location                           NSLocalizedString(@"Location", nil)
#define D11_Text_TamperSwitch                       NSLocalizedString(@"Tamper Switch", nil)
#define D11_Text_ArmHomeArmLight                    NSLocalizedString(@"Arm/Home arm Light", nil)
#define D11_Text_StatusBeep                         NSLocalizedString(@"Status Beep", nil)
#define D11_Text_AlarmLights                        NSLocalizedString(@"Alarm Lights", nil)
#define D11_Text_AlarmVolume                        NSLocalizedString(@"Alarm volume", nil)
#define D11_Text_AlarmDuration                      NSLocalizedString(@"Alarm Duration", nil)
#define D11_Text_LowBatteryLight                    NSLocalizedString(@"Low Battery Light", nil)
#define D11_Text_mins                               NSLocalizedString(@"mins", nil)
#define D11_Text_Mute                               NSLocalizedString(@"Mute", nil)
#define D11_Text_Low                                NSLocalizedString(@"Low", nil)
#define D11_Text_High                               NSLocalizedString(@"High", nil)
#define D11_Text_second                             NSLocalizedString(@"s", nil)
#define D11_Text_Medium                               NSLocalizedString(@"Medium(Recommended)", nil)
#define D11_Text_AlarmWhenHomeArmed                               NSLocalizedString(@"Alarm When Home Armed", nil)
#define D11_Text_AlarmRegardlessof                               NSLocalizedString(@"Alarm Regardless of state (24/7)", nil)
#define D11_Text_AlarmDelay                                     NSLocalizedString(@"Alarm Delay", nil)
#define D11_Text_AlarmTimeSettings                                     NSLocalizedString(@"Alarm Time Settings", nil)
#define D11_Text_ExitInstallationMode                                   NSLocalizedString(@"Exit Installation Mode", nil)
#define D11_Text_Sensitivity                                   NSLocalizedString(@"Sensitivity", nil)

//配件
//配件类型名称
#define D11_Text_K1_Sensor_Type_Func_ZWave    NSLocalizedString(@"K1_Sensor_Type_Func_ZWave",nil)//ZWave
#define D11_Text_K1_Sensor_Type_Func_SD    NSLocalizedString(@"K1_Sensor_Type_Func_SD",nil)//门磁 （rf）
#define D11_Text_K1_Sensor_Type_Func_SI    NSLocalizedString(@"K1_Sensor_Type_Func_SI",nil)//红外  (rf)
#define D11_Text_K1_Sensor_Type_Func_SM    NSLocalizedString(@"K1_Sensor_Type_Func_SM",nil)//烟感  (rf)
#define D11_Text_K1_Sensor_Type_Func_SC    NSLocalizedString(@"K1_Sensor_Type_Func_SC",nil)//CO探测
#define D11_Text_K1_Sensor_Type_Func_SF    NSLocalizedString(@"K1_Sensor_Type_Func_SF",nil)//水浸  (rf)
#define D11_Text_K1_Sensor_Type_Func_LM    NSLocalizedString(@"K1_Sensor_Type_Func_LM",nil)//亮度
#define D11_Text_K1_Sensor_Type_Func_TP    NSLocalizedString(@"K1_Sensor_Type_Func_TP",nil)//温度   (rf)
#define D11_Text_K1_Sensor_Type_Func_HU    NSLocalizedString(@"K1_Sensor_Type_Func_HU",nil)//湿度
#define D11_Text_K1_Sensor_Type_Func_PW    NSLocalizedString(@"K1_Sensor_Type_Func_PW",nil)//功率
#define D11_Text_K1_Sensor_Type_Func_PE    NSLocalizedString(@"K1_Sensor_Type_Func_PE",nil)//电量
#define D11_Text_K1_Sensor_Type_Func_PS    NSLocalizedString(@"K1_Sensor_Type_Func_PS",nil)//电源控制器（电插）
#define D11_Text_K1_Sensor_Type_Func_DM    NSLocalizedString(@"K1_Sensor_Type_Func_DM",nil)//智能调节灯
#define D11_Text_K1_Sensor_Type_Func_LC    NSLocalizedString(@"K1_Sensor_Type_Func_LC",nil)//电子控制锁
#define D11_Text_K1_Sensor_Type_Func_CS    NSLocalizedString(@"K1_Sensor_Type_Func_CS",nil)//报警器或警号  (rf)
#define D11_Text_K1_Sensor_Type_Func_KP    NSLocalizedString(@"K1_Sensor_Type_Func_KP",nil)//无线键盘     (rf)
#define D11_Text_K1_Sensor_Type_Func_RC    NSLocalizedString(@"K1_Sensor_Type_Func_RC",nil)//遥控器
#define D11_Text_K1_Sensor_Type_Func_RF    NSLocalizedString(@"K1_Sensor_Type_Func_RF",nil)//RF读卡器    (rf)
#define D11_Text_K1_Sensor_Type_Func_SG    NSLocalizedString(@"K1_Sensor_Type_Func_SG",nil)//光栅
#define D11_Text_K1_Sensor_Type_Func_NEST    NSLocalizedString(@"K1_Sensor_Type_Func_NEST",nil)//NEST
#define D11_Text_K1_Sensor_Type_Func_Outdoor_KP    NSLocalizedString(@"K1_Sensor_Type_Func_Outdoor_KP",nil)//outdoor keypad
#define D11_Text_K1_Sensor_Type_Func_IR_Beam    NSLocalizedString(@"K1_Sensor_Type_Func_IR_Beam",nil)//IR Beam Sensors
#define D11_Text_K1_Sensor_Type_Func_Outdoor_CS    NSLocalizedString(@"K1_Sensor_Type_Func_Outdoor_CS",nil)//Outdoor Siren
#define D11_Text_K1_Sensor_Type_Func_Glass_Break_Dec    NSLocalizedString(@"K1_Sensor_Type_Func_Glass_Break_Dec",nil)//Glass Break Detector


//RFID
#define D11_Text_RFIDTag                                    NSLocalizedString(@"RFID Tag", nil)
#define D11_Text_Tag26                                      NSLocalizedString(@"(TAG-26)", nil)


//双向
#define D11_Text_TDS                                        NSLocalizedString(@"Door Sensor", nil)
#define D11_Text_DWC945                                     NSLocalizedString(@"(DWC945)", nil)

#define D11_Text_TMS                                        NSLocalizedString(@"Motion Sensor", nil)
#define D11_Text_PIR945                                     NSLocalizedString(@"(PIR-945)", nil)

#define D11_Text_TRC                                        NSLocalizedString(@"Remote Control", nil)
#define D11_Text_RC945                                      NSLocalizedString(@"(RC-946)", nil)

#define D11_Text_TOK                                        NSLocalizedString(@"Outdoor keypad", nil)
#define D11_Text_KP945                                      NSLocalizedString(@"(KP-945)", nil)

#define D11_Text_TSS                                        NSLocalizedString(@"Smoke Sensor", nil)
#define D11_Text_SD945                                      NSLocalizedString(@"(SD-945)", nil)

#define D11_Text_OutdoorSiren                                        NSLocalizedString(@"Outdorr Siren", nil)

#define D11_Text_GlassBreakDetector                                        NSLocalizedString(@"Glass Break Detector ", nil)

#define D11_Text_waterSensor                                        NSLocalizedString(@"Water Sensor", nil)

#define D11_Text_IRBeamSensors                                        NSLocalizedString(@"IR Beam Sensors ", nil)


//单向
#define D11_Text_DoorSensor                                 NSLocalizedString(@"Door Sensor", nil)
#define D11_Text_DWC102                                     NSLocalizedString(@"DWC-102", nil)

#define D11_Text_RollSDS                                    NSLocalizedString(@"Roll Shutter Door Sensor", nil)
#define D11_Text_DWC55                                      NSLocalizedString(@"(DWC_55)", nil)

#define D11_Text_MetallicDS                                 NSLocalizedString(@"Metallic Door Sensor", nil)
#define D11_Text_DWC3F                                      NSLocalizedString(@"DWC-3F", nil)

#define D11_Text_CMMS                                       NSLocalizedString(@"Ceiling-Mounted Motion Sensor", nil)
#define D11_Text_PIR700                                     NSLocalizedString(@"(PIR-700)", nil)

#define D11_Text_CMS                                        NSLocalizedString(@"Curtain Motion Sensor", nil)
#define D11_Text_PIR800                                     NSLocalizedString(@"(PIR-800)", nil)

#define D11_Text_PMS                                        NSLocalizedString(@"Pet-Immune Motion Sensor", nil)
#define D11_Text_PIR910                                     NSLocalizedString(@"(PIR-910)", nil)

#define D11_Text_SMS                                        NSLocalizedString(@"Solar Motion Sensor", nil)
#define D11_Text_PIR926                                     NSLocalizedString(@"(PIR-926)", nil)

#define D11_Text_RC                                         NSLocalizedString(@"Remote Control", nil)
#define D11_Text_RC80                                       NSLocalizedString(@"(RC-80)", nil)

#define D11_Text_WK                                         NSLocalizedString(@"Wireless Keypad", nil)
#define D11_Text_KP700                                      NSLocalizedString(@"(KP-700)", nil)

#define D11_Text_GBD                                        NSLocalizedString(@"Glass Break Detetor", nil)
#define D11_Text_G126                                       NSLocalizedString(@"(GT-126)", nil)

#define D11_Text_WS                                         NSLocalizedString(@"Water Sensor", nil)
#define D11_Text_WI210                                      NSLocalizedString(@"(WI-210)", nil)

#define D11_Text_SD                                         NSLocalizedString(@"Smoker Detector", nil)
#define D11_Text_SMK500                                     NSLocalizedString(@"(SMK-500)", nil)

#define D11_Text_GD                                         NSLocalizedString(@"Gas Detector", nil)
#define D11_Text_GAS88                                      NSLocalizedString(@"(GAS-88)", nil)

#define D11_Text_WVD                                        NSLocalizedString(@"Wireless Vibration Detector", nil)
#define D11_Text_WD80                                       NSLocalizedString(@"(WD-80)", nil)

#define D11_Text_OIS                                        NSLocalizedString(@"Outdoor IR Sensors", nil)
#define D11_Text_AID420                                     NSLocalizedString(@"(AID-420)", nil)

#define D11_Text_WPB                                        NSLocalizedString(@"Wireless Panic Button", nil)
#define D11_Text_SOS100                                     NSLocalizedString(@"(SOS-100)", nil)




//======================================== 字典的key ========================================
#define D11_accessories_list_sectionTitleKey                @"D11_accessories_list_sectionTitleKey"
#define D11_accessories_list_sensorTypeKey                  @"D11_accessories_list_sensorTypeKey"
#define D11_accessories_list_sectionContentKey              @"D11_accessories_list_sectionContentKey"


//======================================== 图片名称 ========================================
#define D11_imageName_rfid              @"d11_accessory_tag26"

#define D11_imageName_tdc               @"d11_accessory_dwc945"
#define D11_imageName_tms               @"d11_accessory_pir945"
#define D11_imageName_trc               @"d11_accessory_rc945"
#define D11_imageName_tok               @"d11_accessory_kp945"
#define D11_imageName_tss               @"h4_accessory_sd945"
#define D11_imageName_outdoorSiren      @"h4_accessory_ss2800"
#define D11_imageName_GlassBreak        @"h4_accessory_gb1260"
#define D11_imageName_waterSensor       @"h4_accessory_wi20"
#define D11_imageName_IRBeamSensor      @"h4_accessory_gb1260"


#define D11_imageName_dc                @"d11_accessory_dwc102"
#define D11_imageName_rsdc              @"d11_accessory_dwc55"
#define D11_imageName_mdc               @"d11_accessory_dwc3f"
#define D11_imageName_cmms              @"d11_accessory_pir700"
#define D11_imageName_cms               @"d11_accessory_pir800"
#define D11_imageName_pms               @"d11_accessory_pir910"
#define D11_imageName_sms               @"d11_accessory_pir926"
#define D11_imageName_rc                @"d11_accessory_rc80"
#define D11_imageName_wk                @"d11_accessory_kp700"
#define D11_imageName_gbd               @"d11_accessory_wd80"
#define D11_imageName_ws                @"d11_accessory_wi120"
#define D11_imageName_sd                @"d11_accessory_smk500"
#define D11_imageName_gd                @"d11_accessory_gas88"
#define D11_imageName_wvd               @"d11_accessory_wd80"
#define D11_imageName_ois               @"d11_accessory_aid420"
#define D11_imageName_wpb               @"d11_accessory_sos100"



//======================================== 数值 ========================================
#define D11_float_selectIconWidth (22.0)
#define D11_float_listViewNameLabelLeading (15+30+GHeightAdjust_ip6(D11_float_selectIconWidth))
#define D11_float_beginEditAnimationTime (0.35)
#define D11_float_leadingSpace (15)
#define D11_float_cellHeightNor (50)
#define D11_float_cellHeightTwoWay (75)
#define D11_float_roomCellTop (30)
#define D11_float_cellHeight_addAccessory (70)


#define D11_int_listViewBeginEdit   (11)
#define D11_int_listViewEndEdit     (10)
#define D11_int_roomViewBeginEdit   (21)
#define D11_int_roomViewEndEdit     (20)
#define D11_int_kbEditBeginEdit     (31)
#define D11_int_kbEditEndEdit       (30)


//#define GWidthAdjust_ip6(x)                                 ((ScreenWidth / 375) * x)
//#define GHeightAdjust_ip6(x)                                ((ScreenHeight/667) * x)

#define GWidthAdjust_ip6(x)                                 (1 * x)
#define GHeightAdjust_ip6(x)                                (1 * x)


//======================================== 通知 ========================================
#define D11_Notice_EditNotice                   @"D11_Notice_EditNotice"
#define D11_Notice_enterEditNotice              @"D11_Notice_enterEditNotice"
#define D11_Notice_exitEditNotice               @"D11_Notice_exitEditNotice"
#define D11_Notice_ListViewCellClickNotice      @"D11_Notice_ListViewCellClickNotice"
#define D11_Notice_ListViewRefreshNotice        @"D11_Notice_ListViewRefreshNotice"
#define D11_Notice_imgV_openStatusAlpha1           @"D11_Notice_imgV_openStatusAlpha1"
#define D11_Notice_imgV_openStatusAlpha0            @"D11_Notice_imgV_openStatusAlpha0"


//======================================== 复用标识 ========================================
#define Reuse_Accessory_title_rightImage    @"Accessory_title_rightImage"
#define Reuse_Accessory_title_edit          @"Accessory_title_edit"
#define Reuse_Accessory_title_subTitle      @"Accessory_title_subTitle"
#define Reuse_Accessory_title_select        @"Accessory_title_select"
#define Reuse_Accessory_title_switch        @"Accessory_title_switch"
#define Reuse_Accessory_title_subTitle_rightIcon        @"Accessory_title_subTitle_rightIcon"


#endif /* XBHeader_h */
