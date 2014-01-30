


module.exports = {

        startmeet: function (success, fail, meetTopic,  startMeetCallback, endMeetCallback) {
          if(typeof meetTopic == "undefined") meetTopic = "";
          window.moxtra.startCallback = startMeetCallback;
          window.moxtra.endCallback = endMeetCallback;
          return cordova.exec(success, fail, "MoxtraIntegration", "startmeet", [meetTopic]);
        },
        startMeetCallback:function()
        {
          //HIDE or show things here 
          if(window.moxtra.startCallback) window.moxtra.startCallback();
        },
        endMeetCallback:function()
        {
          if(window.moxtra.endCallback) window.moxtra.endCallback();
        }
    
    
};

