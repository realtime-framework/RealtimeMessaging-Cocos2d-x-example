#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#define ORTC_CLUSTER "http://ortc-developers.realtime.co/server/2.1"
#define ORTC_APP_KEY "YLJ7kz"
#define ORTC_AUTH_TOKEN "your_authentication_token"
#define ORTC_TEST_CHANNEL "myChannel"

#include "cocos2d.h"
#include <ctime>
#include <String.h>
#include <UIButton.h>
#include <UIEditBox/UIEditBox.h>
#include <UIText.h>
#include <UILayout.h>
#include <UIScrollView.h>
#import <extensions/cocosRealtimeMessaging/OrtcClient.h>

class HelloWorld : public cocos2d::Layer, OrtcClientDelegate
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    cocos2d::ui::Button* btnConnect;
    cocos2d::ui::Button* btnSubscribe;
    cocos2d::ui::Button* btnSend;
    cocos2d::ui::EditBox* editChannel;
    cocos2d::ui::EditBox* editSendMessage;
    cocos2d::ui::ScrollView* scrollView;
    
    cocos2d::Label *lastLog;
    void log(std::string log);
    int logCount = 0;
    
    
    OrtcClient *ortc;
    bool isSubscribe = false;
    
    void makeConnect(Ref* pSender, cocos2d::ui::Widget::TouchEventType type);
    void makeSubscribe(Ref* pSender, cocos2d::ui::Widget::TouchEventType type);
    void sendMSG(Ref* pSender, cocos2d::ui::Widget::TouchEventType type);
    
    void onMessage(OrtcClient*, std::string *message, std::string *channel);
    void onConnect(OrtcClient* ortc);
    void onDisconnect(OrtcClient* ortc);
    void onReconnect(OrtcClient* ortc);
    void onReconnecting(OrtcClient* ortc);
    void onSubscribe(OrtcClient* ortc, std::string* channel);
    void onUnsubscribe(OrtcClient* ortc, std::string* channel);
    void onException(OrtcClient* ortc, std::string* error);
    
};

#endif // __HELLOWORLD_SCENE_H__
