# XBAlertView
自定义提示框

### 使用：
<br/>1.添加XBAlertViewBase到工程，XBAlertViewBase传送门：[XBAlertViewBase](https://github.com/huisedediao/XBAlertViewBase)
<br/>2.添加masonry到工程

<br/>

### 效果图：
![image](https://github.com/huisedediao/XBAlertView/raw/master/showNew.png)<br/>

### 示例代码：
<br>
<pre>

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
</pre>