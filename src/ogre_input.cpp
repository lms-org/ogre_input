#include "ogre_input.h"
#include <ogre/visualmanager.h>
#include <OGRE/OgreRenderWindow.h>
#include "OIS/OIS.h"

bool OgreInput::initialize() {
    config = getConfig();

    window = VisualManager::getInstance()
            ->getWindow(this,config->get<std::string>("WINDOW", "WINDOW"));

    std::string windowHandleString;
    {
        size_t windowHandle = 0;
        window->getGfxWindow()->getCustomAttribute("WINDOW", &windowHandle);
        std::stringstream ss;
        ss << windowHandle;
        windowHandleString = ss.str();
    }

    OIS::ParamList oisParameters;
    oisParameters.insert(std::make_pair(std::string("WINDOW"),
                                        windowHandleString));
    oisParameters.insert(std::make_pair(std::string("x11_mouse_grab"), std::string("false")));
    oisParameters.insert(std::make_pair(std::string("x11_mouse_hide"), std::string("false")));
    oisParameters.insert(std::make_pair(std::string("x11_keyboard_grab"), std::string("false")));
    oisParameters.insert(std::make_pair(std::string("XAutoRepeatOn"), std::string("true")));


    inputManager = OIS::InputManager::createInputSystem(oisParameters);
    keyboard = static_cast<OIS::Keyboard*>(inputManager->createInputObject(OIS::OISKeyboard, true));
    mouse = static_cast<OIS::Mouse*>(inputManager->createInputObject(OIS::OISMouse, true));

    mouse->setEventCallback(this);
    keyboard->setEventCallback(this);

    return true;
}

bool OgreInput::deinitialize() {
    return true;
}

bool OgreInput::cycle() {
    mouse->capture();
    keyboard->capture();

    return true;
}

void OgreInput::event(const std::string &key) {
    std::string command = config->get<std::string>(key + ".command", "");
    std::string content = config->get<std::string>(key + ".content", "");

    if(! command.empty() && ! content.empty()) {
        messaging()->send(command, content);
    } else {
        logger.debug() << "Looking for " << key;
    }
}

bool OgreInput::keyPressed(const OIS::KeyEvent &arg) {
    event("key.down." + keyboard->getAsString(arg.key));
    return true;
}

bool OgreInput::keyReleased(const OIS::KeyEvent &arg) {
    event("key.up." + keyboard->getAsString(arg.key));
    return true;
}

bool OgreInput::mouseMoved(const OIS::MouseEvent &arg) {
    // TODO trigger a mouse move event
    return true;
}

bool OgreInput::mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id) {
    event("mouse.down." + std::to_string(static_cast<int>(id)));
    return true;
}

bool OgreInput::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id) {
    event("mouse.up." + std::to_string(static_cast<int>(id)));
    return true;
}
