//
//  ViewController.m
//  XBAlertView
//
//  Created by xxb on 2017/8/1.
//  Copyright © 2017年 xxb. All rights reserved.
//

#import "ViewController.h"
#import "XBAlertView.h"
#import "XBAlertView_progress.h"

@interface ViewController () <XBAlertViewDelegate>
@property (nonatomic,strong) XBAlertView_progress *xbv_progress;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    
    for (int i =0; i < 5; i++)
    {
        NSAttributedString *str = [[NSAttributedString alloc] initWithString:@"ejfi\rjie\rfjief"];
        [[[XBAlertView alloc] initWithTitle:@"title" message:str delegate:nil cancelButtonTitle:@"cancel" otherButtonTitles:@[@"ok",@"ok1"]] show];
//        NSAttributedString *str = [[NSAttributedString alloc] initWithString:@"ejfi\rjie\rfjief"];
//        [[[XBAlertView alloc] initWithTitle:@"heheda" message:str delegate:nil cancelButtonTitle:@"cancel" otherButtonTitles:@[@"ok",@"heh"]] show];
    }
//    
//    [[[XBAlertView alloc] initWithTitle:@"heheda" message:@"lalalala!~~~" delegate:nil cancelButtonTitle:@"cancel" otherButtonTitles:@[@"ok"]] show];
//    
//    [[[XBAlertView alloc] initWithTitle:@"heheda" message:@"lalalala!~~~" delegate:nil cancelButtonTitle:@"cancel" otherButtonTitles:@[@"ok"]] show];
    
//    [self createProgress];

//    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
//        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
////            [self.xbv_progress hidden];
//            [self createAlert];
//        });
//    });
}

- (void)createProgress
{
    [self.xbv_progress = [[XBAlertView_progress alloc] initWithTitle:@"D11_Text_Reminder" message:@"D11_Text_PleaseTriggerTheAccessory" delegate:self cancelButtonTitle:@"D11_Text_Cancel" otherButtonTitles:nil] show];
}

- (void)createAlert
{
    XBAlertView *alerView = [[XBAlertView alloc] initWithTitle:@"标题呵呵~" message:@"消息啦啦~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" delegate:self cancelButtonTitle:@"cancel" otherButtonTitles:@[@"ok"]];
    //    alerView.color_btnBG_nor = [UIColor whiteColor];
        alerView.arr_prominentIndexs = @[@0];
//        alerView.color_btnTitle_prominent = [UIColor redColor];
//        alerView.color_btnTitle_nor = [UIColor purpleColor];
//        alerView.color_btnBG_nor = [UIColor greenColor];
//        alerView.color_btnBG_prominent = [UIColor orangeColor];
    [alerView show];
}

- (void)alertView:(XBAlertView *)alertView clickedBtnAtIndex:(NSInteger)btnIndex
{
    NSLog(@"%zd",btnIndex);
//    [self createAlert];
}

@end
