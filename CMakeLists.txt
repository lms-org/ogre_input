set(SOURCES
	"src/ogre_input.cpp"
	"src/interface.cpp"
)

set(HEADERS
	"include/ogre_input.h"
)

include_directories("include")

add_library(ogre_input SHARED ${SOURCES} ${HEADERS})
target_link_libraries(ogre_input PRIVATE lmscore ogre_binding ogre_window_manager)
