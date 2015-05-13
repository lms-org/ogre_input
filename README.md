# ogre_input

Capture keyboard and mouse events of an OGRE Render Window and trigger LMS messaging broadcasting events.

## Config
- **WINDOW** - The window to capture events from
- **key.up.Left.command** - command to send if left key was pressed
- **key.up.Left.content** - content to send if left key was pressed
- **key.down.space.command/content** - command/content to send if space key was released
- **mouse.down.0.command/content** - command/content to send if left mouse button was pressed
- **mouse.up.1.command/content** - command/content to send if right mouse button was released

## Dependencies
- ogre_binding
- ogre_window_manager

## Recommended modules
- image_renderer
