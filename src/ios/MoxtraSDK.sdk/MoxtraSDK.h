//
// MoxtraSDK.h
// MoxtraSDK
//
// Created by Elton Liu on 8/1/13.
// Copyright (c) 2013 Moxtra, Inc. All rights reserved.
//
// Check detail information in Moxtra SDK API documents.
//

#import <Foundation/Foundation.h>

//Error code
typedef NS_ENUM(NSInteger, MoxtraSDKErrorCode) {
	MoxtraSDKErrorCode_UNKNOWN = -3000,
    MoxtraSDKErrorCode_NETWORK_ERROR,
    MoxtraSDKErrorCode_USER_LOGIN_FAILD,
    MoxtraSDKErrorCode_MEET_ALREADY_STARTED,
    MoxtraSDKErrorCode_MEETID_INVALID
};

//SDK delegate
@protocol MoxtraSDKDelegate <NSObject>
@optional
- (BOOL)moxtraInviteContacts;
- (void)moxtraMeetEnded;
- (void)moxtraMeetStarted;
@end


//SDK API
@interface MoxtraSDK : NSObject

+ (void)configWithClientId:(NSString*)clientId clientSecret:(NSString*)clientSecret;
+ (void)moxtraUnlinkAccount;

+ (BOOL)moxtraStartMeetWithTopic:(NSString*)topic
				 withSDKDelegate:(id<MoxtraSDKDelegate>)sdkDelegate
          withRootViewController:(UIViewController*)rootViewController
                         success:(void(^)(NSString *meetid))success
						 failure:(void(^)(NSError *error))failure;

+ (BOOL)moxtraStartMeetWithTopic:(NSString*)topic
				  withSharedView:(UIView*)view
				 withSDKDelegate:(id<MoxtraSDKDelegate>)sdkDelegate
          withRootViewController:(UIViewController*)rootViewController
                         success:(void(^)(NSString *meetid))success
						 failure:(void(^)(NSError *error))failure;

+ (BOOL)moxtraJoinMeetWithMeetId:(NSString*)meetid
				 withSDKDelegate:(id<MoxtraSDKDelegate>)sdkDelegate
          withRootViewController:(UIViewController*)rootViewController
                         success:(void(^)(NSString *meetid))success
						 failure:(void(^)(NSError *error))failure;

+ (void)moxtraStopMeet;

+ (BOOL)moxtraIsMeetStarted;
+ (NSString*)moxtraGetMeetId;
+ (NSString*)moxtraGetMeetURL;
+ (BOOL)moxtraInvateFriendsWithEmails:(NSArray*)emails;

+ (UIImage*)getMoxtraMeetDefaultImage;
+ (void)setMoxtraShareEnabled:(BOOL)enabled;	//default is enabled

@end


