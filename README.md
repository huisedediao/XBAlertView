# XBAlertView
自定义提示框

### 使用：
<br/>1.添加XBAlertViewBase到工程，XBAlertViewBase传送门：[XBAlertViewBase传送门](https://github.com/huisedediao/XBAlertViewBase)
<br/>2.添加masonry

<br/>

### 效果图：
![image](https://github.com/huisedediao/XBAlertView/raw/master/show.png)<br/>

### 示例代码：
<br>
<pre>
#import "ViewController.h"
#import "XBAlertView.h"

@interface ViewController ()
@property (nonatomic,strong) XBAlertView *alertView;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    

}

//注意要用懒加载，避免从xib或者sb加载的view遮住视图
-(XBAlertView *)alertView
{
    if (_alertView==nil)
    {
        _alertView=[XBAlertView alertView];
        _alertView.fadeInFadeOut=YES;
        _alertView.title=@"标题";
        _alertView.subTitle=@"这是子标题-这是子标题-这是子标题-这是子标题-这是子标题-这是子标题-这是子标题-这是子标题-这是子标题";
    }
    return _alertView;
}

- (IBAction)showBtnClick:(id)sender {
    [self.alertView show];
}

@end
</pre>