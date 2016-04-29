//
//  YTKKeyValueStore.h
//  Ape
//
//  Created by TangQiao on 12-11-6.
//  Copyright (c) 2012年 TangQiao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface YTKKeyValueItem : NSObject

@property (strong, nonatomic) NSString *itemId;
@property (strong, nonatomic) id itemObject;
@property (strong, nonatomic) NSDate *createdTime;

@end


@interface YTKKeyValueStore : NSObject

- (id)initDBWithName:(NSString *)dbName;

- (id)initWithDBWithPath:(NSString *)dbPath;

- (void)createTableWithName:(NSString *)tableName;

- (BOOL)isTableExists:(NSString *)tableName;

- (void)clearTable:(NSString *)tableName;

- (void)close;

///************************ Put&Get methods *****************************************

- (void)putObject:(id)object withId:(NSString *)objectId intoTable:(NSString *)tableName;

- (id)getObjectById:(NSString *)objectId fromTable:(NSString *)tableName;

- (YTKKeyValueItem *)getYTKKeyValueItemById:(NSString *)objectId fromTable:(NSString *)tableName;

- (void)putString:(NSString *)string withId:(NSString *)stringId intoTable:(NSString *)tableName;

- (NSString *)getStringById:(NSString *)stringId fromTable:(NSString *)tableName;

- (void)putNumber:(NSNumber *)number withId:(NSString *)numberId intoTable:(NSString *)tableName;

- (NSNumber *)getNumberById:(NSString *)numberId fromTable:(NSString *)tableName;

- (NSArray *)getAllItemsFromTable:(NSString *)tableName;

- (void)deleteObjectById:(NSString *)objectId fromTable:(NSString *)tableName;

- (void)deleteObjectsByIdArray:(NSArray *)objectIdArray fromTable:(NSString *)tableName;

- (void)deleteObjectsByIdPrefix:(NSString *)objectIdPrefix fromTable:(NSString *)tableName;


/**
 * ------------------------"  存入  " -----------------------
 */
//ZM_Add 存入单个模型
- (void)putModelObject:(id)object withId:(NSString *)objectId intoTable:(NSString *)tableName;

//ZM_Add 存入模型数组：一个Model一个Id
- (void)putModelObjectArray:(NSArray *)objectArray withIdArray:(NSArray *)objectIdArray intoTable:(NSString *)tableName;

//ZM_Add 存入模型数组：只用一个Id
- (void)putModelObjectArray:(NSArray *)objectArray intoTable:(NSString *)tableName;

/**
 * ------------------------"  取出  "-----------------------
 */
//ZM_Add 根据一个Id取出一个模型对象
- (id)getModelObjectById:(NSString *)objectId className:(Class)className fromTable:(NSString *)tableName;

//ZM_Add 根据一个表名取出一个数组模型对象
- (id)getModelArrayByclassName:(Class)className fromTable:(NSString *)tableName arrayCount:(int)arrayCount;

//ZM_Add 
- (NSArray *)getItemsFromTable:(NSString *)tableName withRange:(NSRange)range;

//ZM_Add 表是否存在
- (BOOL)isExistTableWithName:(NSString *)tableName;


/**
 *  --------------------------"  删除  "----------------------
 */
//ZM_Add  删除表
- (BOOL)deleteTable:(NSString *)tableName;

//ZM_Add  删除数据库
- (void)deleteDatabseWithDBName:(NSString *)DBName;

// 获取表库的路径
- (NSString *)getDBPath;

@end








