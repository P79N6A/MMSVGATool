//
//  MLCommonAnimationView.h
//  MomoChat
//
//  Created by MOMO on 2018/10/22.
//  Copyright © 2018 wemomo.com. All rights reserved.
//  https://moji.wemomo.com/doc#/detail/57786
//

#import <UIKit/UIKit.h>
#import "MLCommonAnimation_Support.h"

typedef SDImageCutInupt MLAnimationCutInput;

NS_ASSUME_NONNULL_BEGIN

typedef void(^MLAnimationClickBlock)(NSString *key);

/// Bool, 是否允许文字折行；YES:允许折行，默认为NO
extern NSAttributedStringKey const MLAnimationTextWrapped;

typedef NS_ENUM(NSInteger, MLCommonAnimationTouchMode) {
    MLCommonAnimationTouchModeSystem, // 整个View拦截点击事件
    MLCommonAnimationTouchModeOnlyClickable, // 仅设置了点击事件的区域拦截点击
    MLCommonAnimationTouchModeDefault = MLCommonAnimationTouchModeOnlyClickable,
};

@interface MLCommonAnimationVideoInfo : NSObject

@property (nonatomic, readonly) CGSize videoSize;
@property (nonatomic, readonly) int FPS;
@property (nonatomic, readonly) int frames;

@end

/// 播放svga动画的类
@interface MLCommonAnimationView : UIView

@property (nonatomic, readonly) NSURL *resourceURL;
@property (nonatomic, readonly) MLCommonAnimationVideoInfo *videoInfo;

/// 当播放结束时将自己移除
@property (nonatomic, assign) BOOL removeFromSuperviewOnFinished;

/// 动画循环次数，默认是1
@property (nonatomic, assign) int loops;

/// 资源加载成功后回调
@property (nonatomic, copy, nullable) void(^videoDidLoad)(MLCommonAnimationView *view, MLCommonAnimationVideoInfo *info);

/// 加载资源，如果URL是一个网络资源，该资源将被下载到Cache目录下
- (void)loadResourceWithURL:(NSURL *)url;

/// 加载本地资源
- (void)loadResourceWithName:(NSString *)name inBundle:(NSBundle *)bundle;

/// 播放动画
- (void)startAnimation;
- (void)startAnimationWithCompletionBlock:(void (^)(BOOL))completion;

/// 暂停
- (void)pauseAnimation;

- (void)resumeAnimation;

/// 结束动画
- (void)stopAnimation;


- (void)stepToPercentage:(CGFloat)percentage andPlay:(BOOL)andPlay;

// 替换动画中的资源
- (void)setImageWithURL:(NSString *)URL forKey:(NSString *)aKey;
- (void)setImageWithURL:(NSString *)URL cutInput:(MLAnimationCutInput)cutInput forKey:(NSString *)aKey;
- (void)setAttributedText:(NSAttributedString *)attributedText forKey:(NSString *)aKey;

/// 可以让点击事件透过View，传递到下一层
@property (nonatomic, assign) MLCommonAnimationTouchMode touchMode;

/// 设置点击
- (void)setClickBlock:(MLAnimationClickBlock)clickBlock forKey:(NSString *)aKey;

/// set with json string or object
- (void)setupWithJson:(id)json;
- (void)setupWithJson:(id)json clickBlock:(nullable void(^)(NSString *key, NSString * __nullable action))clickBlock;
@end

NS_ASSUME_NONNULL_END
