#include "HelloWorldScene.h"

#define OFFSET 5
#define TEXT_SIZE 12.0

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{

    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Color4F white(255/255.0, 255/255.0, 255/255.0, 1.0);
    
    auto background = Sprite::create("background.png");
    background->setContentSize(visibleSize);
    background->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    this->addChild(background, 0);
    
    
    btnConnect = ui::Button::create("green.png");
    btnConnect->setTitleText("Connect");
    btnConnect->setTitleColor(Color3B::BLACK);
    btnConnect->setColor(cocos2d::Color3B(white));
    btnConnect->setScale9Enabled(true);
    btnConnect->setSize(Size((btnConnect->getContentSize().width * 1.5), (btnConnect->getContentSize().height)));
    btnConnect->setTitleFontSize(TEXT_SIZE);
    btnConnect->setAnchorPoint(Vec2(0.0,1.0));
    btnConnect->setPosition(Vec2((origin.x + OFFSET),
                          (origin.y + visibleSize.height  - OFFSET)));
    btnConnect->addTouchEventListener( CC_CALLBACK_2(HelloWorld::makeConnect, this) );
    this->addChild(btnConnect, 2);
    
    btnSubscribe = ui::Button::create("green.png");
    btnSubscribe->setTitleText("Subscribe");
    btnSubscribe->setTitleColor(Color3B::BLACK);
    btnSubscribe->setColor(cocos2d::Color3B(white));
    btnSubscribe->setScale9Enabled(true);
    btnSubscribe->setSize(Size((btnSubscribe->getContentSize().width * 1.5), (btnSubscribe->getContentSize().height)));
    btnSubscribe->setTitleFontSize(TEXT_SIZE);
    btnSubscribe->setAnchorPoint(Vec2(0.0,1.0));
    btnSubscribe->setPosition(Vec2(btnConnect->getPosition().x,
                                   btnConnect->getPosition().y - btnConnect->getContentSize().height - OFFSET));
    btnSubscribe->addTouchEventListener( CC_CALLBACK_2(HelloWorld::makeSubscribe, this) );
    this->addChild(btnSubscribe, 2);
    
    btnSend = ui::Button::create("green.png");
    btnSend->setTitleText("Send Message");
    btnSend->setTitleColor(Color3B::BLACK);
    btnSend->setColor(cocos2d::Color3B(white));
    btnSend->setScale9Enabled(true);
    btnSend->setSize(Size((btnSend->getContentSize().width * 1.5), (btnSend->getContentSize().height)));
    btnSend->setTitleFontSize(TEXT_SIZE);
    btnSend->setAnchorPoint(Vec2(0.0,1.0));
    btnSend->setPosition(Vec2(btnConnect->getPosition().x,
                                   btnSubscribe->getPosition().y - btnSubscribe->getContentSize().height - OFFSET));
    btnSend->addTouchEventListener( CC_CALLBACK_2(HelloWorld::sendMSG, this) );
    this->addChild(btnSend, 2);
    
    
    
    
    editChannel = cocos2d::ui::EditBox::create(Size(visibleSize.width - btnConnect->getContentSize().width - btnConnect->getPosition().x - 3 * OFFSET,
                                                         btnConnect->getContentSize().height), ui::Scale9Sprite::create());
    editChannel->setText("myChannel");
    editChannel->setAnchorPoint(Vec2(0.0,1.0));
    editChannel->setFontName("fonts/arial.ttf");
    editChannel->setFontSize(TEXT_SIZE);
    editChannel->setFontColor(Color3B::BLACK);
    editChannel->setPlaceholderFontColor(Color3B::BLACK);
    editChannel->setPlaceholderFontSize(TEXT_SIZE);
    editChannel->setReturnType(ui::EditBox::KeyboardReturnType::DONE);
    editChannel->setPosition(Vec2(btnSubscribe->getContentSize().width + btnSubscribe->getPosition().x + OFFSET,
                                 btnSubscribe->getPosition().y));
    this->addChild(editChannel, 2);
    
    auto backEditChannel = DrawNode::create();
    Vec2 rectangle[4];
    rectangle[0] = editChannel->getPosition();
    rectangle[1] = Vec2(editChannel->getPosition().x + editChannel->getContentSize().width, editChannel->getPosition().y);
    rectangle[2] = Vec2(editChannel->getPosition().x + editChannel->getContentSize().width, editChannel->getPosition().y - editChannel->getContentSize().height);
    rectangle[3] = Vec2(editChannel->getPosition().x, editChannel->getPosition().y - editChannel->getContentSize().height);
    
    
    backEditChannel->drawPolygon(rectangle, 4, white, 1, white);
    this->addChild(backEditChannel, 1);
    
    
    
    editSendMessage = cocos2d::ui::EditBox::create(Size(visibleSize.width - btnConnect->getContentSize().width - btnConnect->getPosition().x - 3 * OFFSET,
                                                         btnConnect->getContentSize().height), ui::Scale9Sprite::create());
    editSendMessage->setText("Hello World!!!");
    editSendMessage->setAnchorPoint(Vec2(0.0,1.0));
    editSendMessage->setFontName("fonts/arial.ttf");
    editSendMessage->setFontSize(TEXT_SIZE);
    editSendMessage->setFontColor(Color3B::BLACK);
    editSendMessage->setPlaceholderFontColor(Color3B::BLACK);
    editSendMessage->setPlaceholderFontSize(TEXT_SIZE);
    editSendMessage->setReturnType(ui::EditBox::KeyboardReturnType::DONE);
    editSendMessage->setPosition(Vec2(btnSend->getContentSize().width + btnSend->getPosition().x + OFFSET,
                                  btnSend->getPosition().y));
    this->addChild(editSendMessage, 2);
    
    auto backEditSendMessage = DrawNode::create();
    Vec2 rectangle2[4];
    rectangle2[0] = editSendMessage->getPosition();
    rectangle2[1] = Vec2(editSendMessage->getPosition().x + editSendMessage->getContentSize().width, editSendMessage->getPosition().y);
    rectangle2[2] = Vec2(editSendMessage->getPosition().x + editSendMessage->getContentSize().width, editSendMessage->getPosition().y - editSendMessage->getContentSize().height);
    rectangle2[3] = Vec2(editSendMessage->getPosition().x, editSendMessage->getPosition().y - editSendMessage->getContentSize().height);
    
    backEditSendMessage->drawPolygon(rectangle2, 4, white, 1, white);
    this->addChild(backEditSendMessage, 1);
    
    

    scrollView = cocos2d::ui::ScrollView::create();
    scrollView->setAnchorPoint(Vec2(0.0, 1.0));
    scrollView->setContentSize(Size((visibleSize.width / 80) * 78, (visibleSize.height / 40) * 26));
    scrollView->setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::NONE);
    scrollView->setBackGroundColor(Color3B(white));
    scrollView->setPosition(Vec2(btnConnect->getPosition().x,
                                 btnSend->getPosition().y - btnSend->getContentSize().height - OFFSET));
    scrollView->setDirection(cocos2d::ui::ScrollView::Direction::VERTICAL);
    scrollView->setBounceEnabled(true);
    scrollView->setTouchEnabled(true);
    
    auto containerSize = Size(scrollView->getContentSize().width, scrollView->getInnerContainerSize().height);
    scrollView->setInnerContainerSize(containerSize);
    
    this->addChild(scrollView, 2);
    
    

    auto backScrollView = DrawNode::create();
    Vec2 rectangle3[4];
    rectangle3[0] = scrollView->getPosition();
    rectangle3[1] = Vec2(scrollView->getPosition().x + scrollView->getContentSize().width, scrollView->getPosition().y);
    rectangle3[2] = Vec2(scrollView->getPosition().x + scrollView->getContentSize().width, scrollView->getPosition().y - scrollView->getContentSize().height);
    rectangle3[3] = Vec2(scrollView->getPosition().x, scrollView->getPosition().y - scrollView->getContentSize().height);
    
    backScrollView->drawPolygon(rectangle3, 4, white, 1, white);
    this->addChild(backScrollView, 1);
    
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


void HelloWorld::log(std::string log){
    
    Point pos;
    if (lastLog == NULL) {
        pos = Point(scrollView->getPosition().x + OFFSET,
                    scrollView->getPosition().y - scrollView->getContentSize().height - OFFSET);
    }else{
        pos = Point(scrollView->getPosition().x + OFFSET,
                    lastLog->getPosition().y + OFFSET * 3);
    }
    
    
    time_t t = time(0);
    tm * now = localtime(&t); // get current year, month, day and time
    
    
    std::string formated = StringUtils::format("[%0.2d:%0.2d:%0.2d] %s", now->tm_hour, now->tm_min, now->tm_sec, log.c_str());
    auto label = Label::createWithSystemFont(formated, "Arial", 12);
    label->setTextColor(Color4B::BLACK);
    label->setAnchorPoint(Vec2(0.0, 0.0));
    label->setPosition(pos);
    
    
    lastLog = label;
    logCount = logCount + 1;
    
    float sy = scrollView->getInnerContainerSize().height - OFFSET * 4;
    float ly = lastLog->getPosition().y;
    
    if (ly > sy) {
        auto containerSize = Size(scrollView->getContentSize().width, scrollView->getInnerContainerSize().height * 1.5);
        scrollView->setInnerContainerSize(containerSize);
    }
    scrollView->addChild(label);
}


void HelloWorld::makeConnect(Ref* pSender, cocos2d::ui::Widget::TouchEventType type){
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        if (ortc != NULL && ortc->is_connected()) {
            ortc->disconnect();
        }else{
            ortc = new OrtcClient(this);
            ortc->setCluster(new std::string(ORTC_CLUSTER));
            ortc->connect(new std::string(ORTC_APP_KEY), new std::string(ORTC_AUTH_TOKEN));
        }
    }
}

void HelloWorld::makeSubscribe(Ref* pSender, cocos2d::ui::Widget::TouchEventType type){
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        if (std::strcmp(editChannel->getText(), "") != 0) {
            if (isSubscribe) {
                ortc->unsubscribe(new std::string(editChannel->getText()));
            }else{
                ortc->subscribe(new std::string(editChannel->getText()), true);
            }
        }else{
            this->log(std::string("Channel is empty!!!"));
        }
    }
}

void HelloWorld::sendMSG(Ref* pSender, cocos2d::ui::Widget::TouchEventType type){
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        if (std::strcmp(editSendMessage->getText(), "") != 0) {
            std::string *message = new std::string(editSendMessage->getText());
            std::string *channel = new std::string(editChannel->getText());
            ortc->sendMessage(channel, message);
        }else{
            this->log(std::string("Message is empty!!!"));
        }
    }
}


void HelloWorld::onMessage(OrtcClient*, std::string *message, std::string *channel){
    CCLOG("message: %s from channel: %s", message->c_str(), channel->c_str());
    this->log(StringUtils::format("message: %s from channel: %s", message->c_str(), channel->c_str()));
}

void HelloWorld::onConnect(OrtcClient* ortc){
    CCLOG("Connected");
    btnConnect->setTitleText("Disconnect");
    this->log(std::string("Connected"));
}

void HelloWorld::onDisconnect(OrtcClient* ortc){
    CCLOG("Disconnected");
    btnConnect->setTitleText("Connect");
    this->log(std::string("Disconnected"));
    
    btnSubscribe->setTitleText("Subscribe");
    isSubscribe = false;
    editChannel->setEnabled(true);
}

void HelloWorld::onSubscribe(OrtcClient* ortc, std::string* channel){
    CCLOG("Subscribe channel: %s", channel->c_str());
    this->log(StringUtils::format("Subscribe channel: %s", channel->c_str()));
    btnSubscribe->setTitleText("Unsubscribe");
    isSubscribe = true;
    editChannel->setEnabled(false);
}

void HelloWorld::onUnsubscribe(OrtcClient* ortc, std::string* channel){
    CCLOG("Unsubscribe channel: %s", channel->c_str());
    this->log(StringUtils::format("Unsubscribe channel: %s", channel->c_str()));
    btnSubscribe->setTitleText("Subscribe");
    isSubscribe = false;
    editChannel->setEnabled(true);
}

void HelloWorld::onException(OrtcClient* ortc, std::string* error){
    CCLOG("Exception: %s", error->c_str());
    this->log(StringUtils::format("Exception: %s", error->c_str()));
}

void HelloWorld::onReconnect(OrtcClient* ortc){
    CCLOG("Reconnected");
    this->log(std::string("Reconnected"));
}

void HelloWorld::onReconnecting(OrtcClient* ortc){
    CCLOG("Reconnecting");
    this->log(std::string("Reconnecting"));
}




