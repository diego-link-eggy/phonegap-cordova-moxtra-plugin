//
//  MoxtraIntegration.h
//
//  Created by Diego Link on 12/3/13.
//
//

#import <Cordova/CDVPlugin.h>
#import <Cordova/CDVInvokedUrlCommand.h>

@interface MoxtraIntegration : CDVPlugin

- (void) capture:(CDVInvokedUrlCommand*)command;

@end
