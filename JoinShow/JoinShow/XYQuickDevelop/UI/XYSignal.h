//
//  XYSignal.h
//  JoinShow
//
//  Created by heaven on 15/2/28.
//  Copyright (c) 2015年 Heaven. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark- Request && Response
@interface XYSignal : NSObject

// Request
@property (nonatomic, assign) BOOL isDead;  // 是否结束
@property (nonatomic, assign) BOOL isReach;      // 是否触达最后的Handler

@property (nonatomic, weak) id sender;          // 发送者
@property (nonatomic, weak) id receiver;        // 接收者

@property (nonatomic, assign) NSInteger jump;       // 跳转次数
@property (nonatomic, copy) NSString *name;     // 名字
@property (nonatomic, strong) id parameters;        // 参数

@property (nonatomic, copy) NSMutableString *callPath;    // 调用路径

// Response
@property (nonatomic, strong) id response;       // 返回值


+ (id)signalWithName:(NSString *)name;

@end


#pragma mark- UXYSignalHandler

@interface NSObject (UXYSignalHandler)

@property (nonatomic, weak) id uxy_nextSignalHandler;

- (id)uxy_defaultNextSignalHandler;

// 处理任务
- (void)uxy_performSignal:(XYSignal *)signal;

@end

@interface UIView (UXYSignalHandler)

// 返回一个signal对象
- (XYSignal *)uxy_signalWithName:(NSString *)name;

// 发送一个signal
- (XYSignal *)uxy_sendSignalWithName:(NSString *)name;
- (XYSignal *)uxy_sendSignalWithName:(NSString *)name paramters:(id)paramters;
- (XYSignal *)uxy_sendSignalWithName:(NSString *)name withObject:(NSObject *)object from:(id)source;

- (XYSignal *)uxy_sendSignal:(XYSignal *)signal;

@end

@interface UIViewController (UXYSignalHandler)

- (XYSignal *)uxy_sendSignalWithName:(NSString *)name;
- (XYSignal *)uxy_sendSignalWithName:(NSString *)name paramters:(id)paramters;
- (XYSignal *)uxy_sendSignalWithName:(NSString *)name withObject:(NSObject *)object from:(id)source;

@end