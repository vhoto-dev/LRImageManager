// LRImageManager.h
//
// Copyright (c) 2013 Luis Recuenco
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import "LRImageCache.h"

typedef NS_ENUM(NSUInteger, LRImageViewAnimationType)
{
    LRImageViewAnimationTypeNone,
    LRImageViewAnimationTypeFade,
};

typedef NSURL * (^LRImageURLModifierBlock)(NSURL *url, CGSize size);
typedef void (^LRImageCompletionHandler)(UIImage *image, NSError *error);

@interface LRImageManager : NSObject

@property (nonatomic, strong, readonly) LRImageCache *imageCache;

@property (nonatomic, copy) LRImageURLModifierBlock imageURLModifier;

@property (nonatomic, assign) BOOL showNetworkActivityIndicator;

@property (nonatomic, assign) BOOL autoRetry;

+ (instancetype)sharedManager;

- (void)imageFromURL:(NSURL *)url
                size:(CGSize)size
   completionHandler:(LRImageCompletionHandler)completionHandler;

- (void)imageFromURL:(NSURL *)url
                size:(CGSize)size
 cacheStorageOptions:(LRCacheStorageOptions)cacheStorageOptions
   completionHandler:(LRImageCompletionHandler)completionHandler;

- (void)cancelImageRequestFromURL:(NSURL *)url size:(CGSize)size;

- (void)cancelAllRequests;

@end

@interface LRImageManager (UIImageView)

- (void)downloadImageForImageView:(UIImageView *)imageView
                         imageURL:(NSURL *)imageURL
                 placeholderImage:(UIImage *)placeholderImage
                             size:(CGSize)size
              cacheStorageOptions:(LRCacheStorageOptions)cacheStorageOptions
                    animationType:(LRImageViewAnimationType)animationType
                completionHandler:(LRImageCompletionHandler)completionHandler;


- (void)cancelDownloadImageForImageView:(UIImageView *)imageView;

@end
