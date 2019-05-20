//
//  UIColor+Utils.h
//  Pods
//
//  Created by momo783 on 2016/9/27.
//
//

#import <UIKit/UIKit.h>

@interface UIColor (MLUtils)

+ (UIColor *)ml_colorWithHexString: (NSString*)hex;//#aabbcc

//带alpha通道的十六进制串
+ (UIColor *)ml_colorWithARGBHexString: (NSString*)hex;//#AARRGGBB

@end
