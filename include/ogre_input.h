#ifndef OGRE_INPUT_H
#define OGRE_INPUT_H

#include "lms/module.h"
#include "lms/datamanager.h"
#include "ogre/window.h"
#include "lms/type/module_config.h"
#include "OIS/OIS.h"

class OgreInput : public lms::Module, private OIS::MouseListener, private OIS::KeyListener {
public:
    bool initialize() override;
    bool cycle() override;
    bool deinitialize() override;
protected:
    bool keyPressed(const OIS::KeyEvent &arg) override;
    bool keyReleased(const OIS::KeyEvent &arg) override;
    bool mouseMoved( const OIS::MouseEvent &arg) override;
    bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id) override;
    bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id) override;
private:
    visual::Window *window;
    const lms::type::ModuleConfig *config;

    OIS::InputManager *inputManager;
    OIS::Mouse *mouse;
    OIS::Keyboard *keyboard;

};

#endif /* OGRE_INPUT_H */
