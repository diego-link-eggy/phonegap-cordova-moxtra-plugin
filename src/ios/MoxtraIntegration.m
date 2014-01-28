//
//  MoxtraIntegration.m
//
//  Created by Diego Link  on 12/3/13.
//	[MoxtraSDK configWithClientId:@"YOUR_CLIENT_ID" andClientSecret:@ "YOUR_CLIENT_SECRET"];
//
//

#import "MoxtraIntegration.h"
#import “MoxtraSDK.h”

@implementation MoxtraIntegration

- (void) startmeet:(CDVInvokedUrlCommand*)command;
{

  	[MoxtraSDK configWithClientId:@"YOUR_CLIENT_ID" andClientSecret:@ "YOUR_CLIENT_SECRET"];
    
	[MoxtraSDK moxtraStartMeetWithTopic:@"Expense Report" withSDKDelegate:self withRootViewController:self.viewController
	                            success:^(NSString *meetid){

	                                //Get session details, do something
	                                NSLog(@"Start meet success with MeetId [%@]", meetid);
	                                CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
	                                [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];

	                            }
	                            failure:^(NSError* error) {
	                                //Handle errors
	                                NSLog(@"error code [%d] description: [%@] info [%@]", [error code], [error localizedDescription], [[error userInfo] description]);
	                                CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:[[error userInfo] description]];   // error callback expects string ATM
	                                [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
	                                
	                            }];
}

- (void) moxtraMeetStarted
{
    NSLog(@"Start meet SDK Delegate");
    NSString* javascript = [NSString stringWithFormat:@"window.moxtra.startMeetCallback();"];
    [self writeJavascript:javascript];

}

- (void)moxtraMeetEnded
{
  //You can show/hide something.
    NSLog(@"End meet SDK Delegate");

    NSString* javascript = [NSString stringWithFormat:@"window.moxtra.endMeetCallback();"];
    // //NSLog(@"Executing: \"%@\"", javascript);
    [self writeJavascript:javascript];
}

@end
