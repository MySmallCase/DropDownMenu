//
//  ViewController.m
//  DropDownMenu
//
//  Created by MyMac on 15/11/1.
//  Copyright © 2015年 MyMac. All rights reserved.
//

#import "ViewController.h"
#import "DropDownMenu.h"

@interface ViewController ()<DropDownMenuDataSource,DropDownMenuDelegate>

@property (nonatomic, strong) NSArray *classifys;
@property (nonatomic, strong) NSArray *areas;
@property (nonatomic, strong) NSArray *sorts;

@property (nonatomic,strong) DropDownMenu *menu;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.classifys = @[@"美食",@"今日新单",@"电影",@"酒店"];
    self.areas = @[@"全城",@"芙蓉区",@"雨花区",@"天心区",@"开福区",@"岳麓区",@"全城",@"芙蓉区",@"雨花区",@"天心区",@"开福区",@"岳麓区",@"全城",@"芙蓉区",@"雨花区",@"天心区",@"开福区",@"岳麓区"];
    self.sorts = @[@"默认排序",@"离我最近",@"好评优先",@"人气优先",@"最新发布",@"默认排序",@"离我最近",@"好评优先",@"人气优先",@"最新发布",@"默认排序",@"离我最近",@"好评优先",@"人气优先",@"最新发布",@"默认排序",@"离我最近",@"好评优先",@"人气优先",@"最新发布"];
    // 添加下拉菜单
    DropDownMenu *menu = [[DropDownMenu alloc] initWithOrigin:CGPointMake(0, 0) andHeight:44];
    menu.delegate = self;
    menu.dataSource = self;
    [self.view addSubview:menu];
    _menu = menu;
    [menu selectDefalutIndexPath];
}


- (NSInteger)numberOfColumnsInMenu:(DropDownMenu *)menu
{
    return 3;
}

- (NSInteger)menu:(DropDownMenu *)menu numberOfRowsInColumn:(NSInteger)column
{
    if (column == 0) {
        return self.classifys.count;
    }else if (column == 1){
        return self.areas.count;
    }else {
        return self.sorts.count;
    }
}

- (NSString *)menu:(DropDownMenu *)menu titleForRowAtIndexPath:(DDMIndexPath *)indexPath
{
    if (indexPath.column == 0) {
        return self.classifys[indexPath.row];
    } else if (indexPath.column == 1){
        return self.areas[indexPath.row];
    } else {
        return self.sorts[indexPath.row];
    }
}


- (void)menu:(DropDownMenu *)menu didSelectRowAtIndexPath:(DDMIndexPath *)indexPath
{
    
    if (indexPath.column == 0) {
        NSLog(@"00===%ld====",(long)indexPath.row);
    }else if (indexPath.column == 1){
        NSLog(@"11===%ld====",(long)indexPath.row);
    }else{
        NSLog(@"22===%ld====",(long)indexPath.row);
    }
    
}

@end
