# Cocos2d-x Realtime Messaging Example
Part of the [The Realtime® Framework](http://framework.realtime.co), Realtime Cloud Messaging (aka ORTC) is a secure, fast and highly scalable cloud-hosted Pub/Sub real-time message broker for web and mobile apps.

If your app has data that needs to be updated in the user’s interface as it changes (e.g. real-time stock quotes or ever changing social news feed) Realtime Cloud Messaging is the reliable, easy, unbelievably fast, “works everywhere” solution.

Cocos2d-x is an open-source game framework written in C++, with a thin platform dependent layer. It is widely used to build games, apps and other cross platform GUI based interactive programs.

## Cocos2d-x instalation

*	Download Cocos2dx from [cocos2d-x page](http://www.cocos2d-x.org/download).
*	Place the sdk in your system files, in the folder run `./setup.py` on terminal.
*	Create a new cocos2dx project by running the command `cocos new -l cpp -p [YOUR_PACKAGE_NAME] -d [PATH_TO_NEW_PROJECT]`.


## Setup the example

*	Copy the content of the example Classes folder to Classes folder in your project.
*	Copy the content of the example Resources folder to Resources folder in your project.

## Install cocos Realtime Messaging SDK

*	Copy cocosRealtimeMessaging SDK to cocos2d/extenssions.
*	Edit Android.mk file in cocos2d/extenssions and add the following lins under `LOCAL_SRC_FILES := \`:

		cocosRealtimeMessaging/OrtcClient.cpp \
		cocosRealtimeMessaging/common.cpp \
		cocosRealtimeMessaging/loops.cpp \
		cocosRealtimeMessaging/authentication.cpp \
		cocosRealtimeMessaging/connection.cpp \
		cocosRealtimeMessaging/message.cpp \
		cocosRealtimeMessaging/balancer.cpp \
		cocosRealtimeMessaging/dlist.cpp \
		cocosRealtimeMessaging/ortc.cpp \
		cocosRealtimeMessaging/channel.cpp \
		cocosRealtimeMessaging/events.cpp \
		cocosRealtimeMessaging/presence.cpp \
		cocosRealtimeMessaging/slre/slre.cpp \
			
*	add `LOCAL_STATIC_LIBRARIES += cocos_curl_static` to local static libraries entrys in `Android.mk` if using cocos2dx version >= 3.13
*	In the last line add `$(call import-module,curl/prebuilt/android)`
*	If building for iOS, make sure in the XCode project the cocos2d_libs is using libcurl.a in link with binary libraries.


That's it, run the project.

## Realtime Messaging Cocos2d-x SDK
See [https://github.com/realtime-framework/RealtimeMessaging-Cocos2d-x](https://github.com/realtime-framework/RealtimeMessaging-Cocos2d-x)