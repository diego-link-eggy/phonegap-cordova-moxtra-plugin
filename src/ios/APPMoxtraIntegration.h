//
//  MoxtraIntegration.h
//
//  Created by Diego Link on 12/3/13.
//
//

#import <Cordova/CDVPlugin.h>
#import <Cordova/CDVInvokedUrlCommand.h>
#import "MoxtraSDK.h"


@interface APPMoxtraIntegration : CDVPlugin <MoxtraSDKDelegate>

- (void) startmeet:(CDVInvokedUrlCommand*)command;

@end

