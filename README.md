
phonegap-cordova-moxtra-plugin 
======================
Moxtra Integration

Currently only adds MEET functionality to IOS projects. Will be updates as Moxtra adds functions and platforms.


Installation
------------



# Project Structure

<pre>
  |_src
  | |_ios
  |   |APPMoxtraIntegration.m
  |   |APPMoxtraIntegration.h
  |   |MoxtraSDK.sdk
  |   |	| MoxtraSDK
  |   |	| MoxtraSDK.h
  |   |	| MoxtraSDKResources.bundle
  |_www
  |  |_moxtra-integration.js
</pre>


Follow the [Command-line Interface Guide](http://cordova.apache.org/docs/en/edge/guide_cli_index.md.html#The%20Command-line%20Interface).

If you are not using the Cordova Command-line Interface, follow [Using Plugman to Manage Plugins](http://cordova.apache.org/docs/en/edge/plugin_ref_plugman.md.html).

Get your `APP_ID` and `CLIENT_SECRET`  and  from  [Moxtra Developer Site](http://developer.moxtra.com/)

Change the  Plugins/APPMoxtraIntegration.m file where you insert your `APP_ID` and `CLIENT_SECRET` that you got from Moxtra.


Usage Example.


``` 
<script type="text/javascript" charset="utf-8">

            // Wait for device API libraries to load
            //
            document.addEventListener("deviceready", onDeviceReady, false);

              
            function onStartMoxtraMeet() {
               console.log('start meet');
            }

            function onEndMoxtraMeet() {
                console.log('start meet');
            }
            
   

         //
            function onSuccess(acceleration) {
                console.log('');
            }

            // onError: Failed to get the acceleration
            //
            function onError() {
                alert('onError!');
            }
        
        function onDeviceReady() {
            window.moxtra.startmeet(onSuccess, onError, "My Meet Topic", onStartMoxtraMeet, onEndMoxtraMeet);
        }

        </script>
```