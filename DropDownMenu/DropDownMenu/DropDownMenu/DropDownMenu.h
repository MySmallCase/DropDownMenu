//
//  DropDownMenu.h
//  DropDownMenu
//
//  Created by MyMac on 15/11/4.
//  Copyright © 2015年 MyMac. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DDMIndexPath : NSObject

@property (nonatomic, assign) NSInteger column;
@property (nonatomic, assign) NSInteger row;
@property (nonatomic, assign) NSInteger item;
- (instancetype)initWithColumn:(NSInteger)column row:(NSInteger)row;
// default item = -1
+ (instancetype)indexPathWithCol:(NSInteger)col row:(NSInteger)row;
+ (instancetype)indexPathWithCol:(NSInteger)col row:(NSInteger)row item:(NSInteger)item;
@end

@interface DDMBackgroundCellView : UIView

@end

#pragma mark - data source protocol
@class DropDownMenu;
@protocol DropDownMenuDataSource <NSObject>

@required

/**< 返回 menu 第column列有多少行*/
- (NSInteger)menu:(DropDownMenu *)menu numberOfRowsInColumn:(NSInteger)column;

/**< 返回 menu 第column列 每行title*/
- (NSString *)menu:(DropDownMenu *)menu titleForRowAtIndexPath:(DDMIndexPath *)indexPath;

@optional
/**< 返回 menu 有多少列 ，默认1列*/
- (NSInteger)numberOfColumnsInMenu:(DropDownMenu *)menu;

/**< 返回 menu 第column列 每行image*/
- (NSString *)menu:(DropDownMenu *)menu imageNameForRowAtIndexPath:(DDMIndexPath *)indexPath;

/**< detailText ,right text*/
- (NSString *)menu:(DropDownMenu *)menu detailTextForRowAtIndexPath:(DDMIndexPath *)indexPath;

/**
 *  当有column列 row 行 返回有多少个item ，如果>0，说明有二级列表 ，=0 没有二级列表
 *  如果都没有可以不实现该协议
 */
- (NSInteger)menu:(DropDownMenu *)menu numberOfItemsInRow:(NSInteger)row column:(NSInteger)column;

/**
 *  当有column列 row 行 item项 title
 *  如果都没有可以不实现该协议
 */
- (NSString *)menu:(DropDownMenu *)menu titleForItemsInRowAtIndexPath:(DDMIndexPath *)indexPath;

/**< 当有column列 row 行 item项 image*/
- (NSString *)menu:(DropDownMenu *)menu imageNameForItemsInRowAtIndexPath:(DDMIndexPath *)indexPath;

/**< 当有column列 row 行 item项 detail*/
- (NSString *)menu:(DropDownMenu *)menu detailTextForItemsInRowAtIndexPath:(DDMIndexPath *)indexPath;

@end

#pragma mark - delegate
@protocol DropDownMenuDelegate <NSObject>
@optional
/**
 *  点击代理，点击了第column 第row 或者item项，如果 item >=0
 */
- (void)menu:(DropDownMenu *)menu didSelectRowAtIndexPath:(DDMIndexPath *)indexPath;

/**< 如果不选择指定的indexPath 返回nil  可以不实现*/
- (NSIndexPath *)menu:(DropDownMenu *)menu willSelectRowAtIndexPath:(DDMIndexPath *)indexPath;

@end

@interface DropDownMenu : UIView<UITableViewDataSource, UITableViewDelegate>

@property (nonatomic, weak) id <DropDownMenuDataSource> dataSource;
@property (nonatomic, weak) id <DropDownMenuDelegate> delegate;

@property (nonatomic, assign) UITableViewCellStyle cellStyle; // default value1
@property (nonatomic, strong) UIColor *indicatorColor;      // 三角指示器颜色
@property (nonatomic, strong) UIColor *textColor;           // 文字title颜色
@property (nonatomic, strong) UIColor *textSelectedColor;   // 文字title选中颜色
@property (nonatomic, strong) UIColor *detailTextColor;     // detailText文字颜色
@property (nonatomic, strong) UIFont *detailTextFont;       // font
@property (nonatomic, strong) UIColor *separatorColor;      // 分割线颜色
@property (nonatomic, assign) NSInteger fontSize;           // 字体大小

// 当有二级列表item时，点击row 是否调用点击代理方法
@property (nonatomic, assign) BOOL isClickHaveItemValid;

@property (nonatomic, getter=isRemainMenuTitle) BOOL remainMenuTitle; // 切换条件时是否更改menu title
@property (nonatomic, strong) NSMutableArray  *currentSelectRowArray; // 恢复默认选项用

/**< menu的宽度默认为屏幕宽度*/
- (instancetype)initWithOrigin:(CGPoint)origin andHeight:(CGFloat)height;

// 获取title
- (NSString *)titleForRowAtIndexPath:(DDMIndexPath *)indexPath;

// 重新加载数据
- (void)reloadData;

// 创建menu 第一次显示 不会调用点击代理，这个手动调用
- (void)selectDefalutIndexPath;

- (void)selectIndexPath:(DDMIndexPath *)indexPath; // 默认trigger delegate

- (void)selectIndexPath:(DDMIndexPath *)indexPath triggerDelegate:(BOOL)trigger; // 调用代理

@end
