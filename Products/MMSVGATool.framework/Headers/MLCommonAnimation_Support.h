//
//  MLCommonAnimation_Support.h
//  svga
//
//  Created by MOMO on 2019/5/17.
//  Copyright © 2019 MOMO. All rights reserved.
//

#import <UIKit/UIKit.h>

struct SDImageCutInupt {
    bool    isCircle;               // 是否是圆
    CGFloat corner;                 // 图片圆角
    UIRectCorner cornerInsert;      // 切哪几个圆角
    CGSize  finalSize;              // 最终裁剪尺寸
};


typedef struct SDImageCutInupt SDImageCutInupt;

extern SDImageCutInupt SDImageCutInuptMake(bool circle, CGFloat corner, UIRectCorner cornerInsert, CGSize  finalSize);
extern bool SDImageCutInuptIsEqual(SDImageCutInupt input1, SDImageCutInupt input2);


#define SDImageCutInuptZero SDImageCutInuptMake(0,0,0,CGSizeZero)

extern UIImage * SDModifyImage(UIImage *image,SDImageCutInupt input);

