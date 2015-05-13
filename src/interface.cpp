#include "ogre_input.h"

extern "C" {
void* getInstance() {
    return new OgreInput();
}
}
