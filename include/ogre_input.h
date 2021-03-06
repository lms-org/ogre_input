#ifndef OGRE_INPUT_H
#define OGRE_INPUT_H

#include <map>
#include "lms/time.h"
#include "lms/module.h"
#include "ogre/window.h"
#include "lms/config.h"
#include "OIS/OIS.h"

class OgreInput : public lms::Module, private OIS::MouseListener, private OIS::KeyListener {
public:
    bool initialize() override;
    bool cycle() override;
    bool deinitialize() override;
private:
    void event(const std::string &key);
protected:
    bool keyPressed(const OIS::KeyEvent &arg) override;
    bool keyReleased(const OIS::KeyEvent &arg) override;
    bool mouseMoved( const OIS::MouseEvent &arg) override;
    bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id) override;
    bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id) override;
private:
    visual::Window *window;

    OIS::InputManager *inputManager;
    OIS::Mouse *mouse;
    OIS::Keyboard *keyboard;

    typedef std::map<OIS::KeyCode, lms::Time> RepeatKeysType;
    RepeatKeysType repeatKeys;
};

#endif /* OGRE_INPUT_H */
