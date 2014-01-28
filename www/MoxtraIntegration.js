cordova.define("com.phonegap.MoxtraIntegration.MoxtraIntegration", function(require, exports, module) {var exec = require('cordova/exec');

var MoxtraIntegration = {

        startmeet: function (success, fail, startMeetCallback, endMeetCallback) {
          var id = 1;// exec hangs if no params are passed.
          MoxtraIntegration.startCallback = startMeetCallback;
          MoxtraIntegration.endCallback = endMeetCallback;
          return exec(success, fail, "MoxtraIntegration", "startmeet", [id]);
        },
        startMeetCallback:function()
        {
          //HIDE or show things here 
          if(MoxtraIntegration.startCallback) MoxtraIntegration.startCallback();
        },
        endMeetCallback:function()
        {
          if(MoxtraIntegration.endCallback) MoxtraIntegration.endCallback();
        }

    
};

module.exports = MoxtraIntegration;});