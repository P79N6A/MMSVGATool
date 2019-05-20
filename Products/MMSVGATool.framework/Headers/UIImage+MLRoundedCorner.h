// UIImage+RoundedCorner.h
// Created by Trevor Harmon on 9/20/09.
// Free for personal or commercial use, with or without modification.
// No warranty is expressed or implied.

// Extends the UIImage class to support making rounded corners
#import <UIKit/UIKit.h>

@interface UIImage (ml_RoundedCorner)

//基于当前图片得到一张内切圆大小的图片
- (UIImage *)ml_circleClipedImage;

- (UIImage *)ml_clipImageWithFinalSize:(CGSize)fSize
                       cornerRadius:(CGFloat)cornerRadius;

- (UIImage *)ml_clipImageWithFinalSize:(CGSize)fSize
                       cornerRadius:(CGFloat)cornerRadius
                    RoundingCorners:(UIRectCorner)roundingCorner;

@end
