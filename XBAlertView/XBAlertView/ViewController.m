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
    [[[XBAlertView alloc] initWithTitle:@"标题呵呵~" message:@"消息啦啦~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" delegate:self cancelButtonTitle:@"cancel" otherButtonTitles:@[@"ok"]] show];
}

- (void)alertView:(XBAlertView *)alertView clickedBtnAtIndex:(NSInteger)btnIndex
{
    [alertView hidden];
}

@end
