#pragma once

# include	<GL/glew.h>

#ifdef	WIN32
# include	<Windows.h>
# include	<GL\GL.h>
# include	<GL\GLU.h>
# include	<GL\glext.h>
#else 
#ifdef __APPLE__
# include       <OpenGl/gl.h>
# include       <OpenGl/glu.h>
#else
# include	<GL/gl.h>
# include	<GL/glu.h>
#endif
#endif
