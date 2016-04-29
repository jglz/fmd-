//
//  ViewController.m
//  fmd数组
//
//  Created by jglz on 16/4/29.
//  Copyright © 2016年 yxb. All rights reserved.
//

#import "ViewController.h"
#import "People.h"
#import "YTKKeyValueStore.h"
@interface ViewController ()
{
    NSMutableArray *dataArr ;

}
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    dataArr = [NSMutableArray arrayWithCapacity:0];
    for (int i = 0; i< 10; i++) {
        People * p = [[People alloc]init];
        p.name = [NSString stringWithFormat:@"gxh%d",i];
        p.age = [NSString stringWithFormat:@"age%d",i];
        
        p.arr = [NSMutableArray arrayWithCapacity:0];
        for (int j = 0 ; j<10; j++) { //测试模型里面套数组，数组里面装的是模型
            People * p1 = [[People alloc]init];
            p1.name = [NSString stringWithFormat:@"yxb%d",j];
            p1.age = [NSString stringWithFormat:@"yxb%d",j];
            [p.arr addObject:p1];
        }
        
        [dataArr addObject:p];
    }
    
    
    
    // 创建数据库 开始存
    YTKKeyValueStore *store = [[YTKKeyValueStore alloc] initDBWithName:@"test.db"];
    // 创建表格
    NSString *tableName = @"user_table";
    [store createTableWithName:tableName];
    
    [store putModelObjectArray:dataArr intoTable:tableName];
    
    
    //取数据
    NSMutableArray *arr = [store getModelArrayByclassName:[People class]fromTable:tableName arrayCount:10];
    
    NSLog(@"%@",arr);
    
    [store clearTable:tableName];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
