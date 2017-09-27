//
//  ViewController.m
//  XBAlertView
//
//  Created by xxb on 2017/8/1.
//  Copyright © 2017年 xxb. All rights reserved.
//

#import "ViewController.h"
#import "XBAlertView.h"

@interface ViewController () <XBAlertViewDelegate>

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    [self createAlert];
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [self createAlert];
    });
}

- (void)createAlert
{
    XBAlertView *alerView = [[XBAlertView alloc] initWithTitle:@"标题呵呵~" message:@"消息啦啦~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" delegate:self cancelButtonTitle:@"cancel" otherButtonTitles:@[@"ok"]];
    //    alerView.color_btnBG_nor = [UIColor whiteColor];
//        alerView.arr_prominentIndexs = @[@0];
//        alerView.color_btnTitle_prominent = [UIColor redColor];
//        alerView.color_btnTitle_nor = [UIColor purpleColor];
//        alerView.color_btnBG_nor = [UIColor greenColor];
//        alerView.color_btnBG_prominent = [UIColor orangeColor];
    [alerView show];
}

- (void)alertView:(XBAlertView *)alertView clickedBtnAtIndex:(NSInteger)btnIndex
{
    NSLog(@"%zd",btnIndex);
}

@end
