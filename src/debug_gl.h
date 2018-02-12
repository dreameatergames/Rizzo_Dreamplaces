#ifdef DEBUG_GL

extern void (GLAPIENTRY *qglPolygonMode_)(GLenum face, GLenum mode);
extern void (GLAPIENTRY *qglPolygonStipple_)(const GLubyte *mask);
extern void (GLAPIENTRY *qglPolygonOffset_)(GLfloat factor, GLfloat units);
extern void (GLAPIENTRY *qglScissor_)(GLint x, GLint y, GLsizei width, GLsizei height);
extern void (GLAPIENTRY *qglCopyTexSubImage2D_)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern void (GLAPIENTRY *qglCopyTexSubImage1D_)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
extern void (GLAPIENTRY *qglCopyTexImage2D_)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
extern void (GLAPIENTRY *qglCopyTexImage1D_)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
extern void (GLAPIENTRY *qglTexImage2D_)(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
extern void (GLAPIENTRY *qglTexImage1D_)(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
extern void (GLAPIENTRY *qglBindTexture_)(GLenum target, GLuint texture);
extern void (GLAPIENTRY *qglDeleteTextures_)(GLsizei n, const GLuint *textures);
extern void (GLAPIENTRY *qglGenTextures_)(GLsizei n, GLuint *textures);
extern void (GLAPIENTRY *qglPixelStorei_)(GLenum pname, GLint param);
extern void (GLAPIENTRY *qglTexParameteri_)(GLenum target, GLenum pname, GLint param);
extern void (GLAPIENTRY *qglTexSubImage2D_)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
extern void (GLAPIENTRY *qglTexSubImage1D_)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
extern void (GLAPIENTRY *qglTexEnvi_)(GLenum target, GLenum pname, GLint param);
extern void (GLAPIENTRY *qglClearStencil_)(GLint s);
extern void (GLAPIENTRY *qglStencilOpSeparate_)(GLenum, GLenum, GLenum, GLenum);
extern void (GLAPIENTRY *qglStencilOp_)(GLenum fail, GLenum zfail, GLenum zpass);
extern void (GLAPIENTRY *qglStencilMask_)(GLuint mask);
extern void (GLAPIENTRY *qglStencilFuncSeparate_)(GLenum, GLenum, GLint, GLuint);
extern void (GLAPIENTRY *qglStencilFunc_)(GLenum func, GLint ref, GLuint mask);
extern void (GLAPIENTRY *qglReadPixels_)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
extern void (GLAPIENTRY *qglTranslatef_)(GLfloat x, GLfloat y, GLfloat z);
extern void (GLAPIENTRY *qglScalef_)(GLfloat x, GLfloat y, GLfloat z);
extern void (GLAPIENTRY *qglRotatef_)(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
extern void (GLAPIENTRY *qglMultMatrixf_)(const GLfloat *m);
extern void (GLAPIENTRY *qglLoadMatrixf_)(const GLfloat *m);
extern void (GLAPIENTRY *qglLoadMatrixd_)(const GLdouble *m);
extern void (GLAPIENTRY *qglLoadIdentity_)(void);
extern void (GLAPIENTRY *qglPopMatrix_)(void);
extern void (GLAPIENTRY *qglPushMatrix_)(void);
extern void (GLAPIENTRY *qglViewport_)(GLint x, GLint y, GLsizei width, GLsizei height);
extern void (GLAPIENTRY *qglFrustum_)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val);
extern void (GLAPIENTRY *qglOrtho_)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val);
extern void (GLAPIENTRY *qglMatrixMode_)(GLenum mode);
extern void (GLAPIENTRY *qglPointSize_)(GLfloat size);
extern void (GLAPIENTRY *qglLineWidth_)(GLfloat width);
extern void (GLAPIENTRY *qglEnd_)(void);
extern void (GLAPIENTRY *qglBegin_)(GLenum mode);
extern void (GLAPIENTRY *qglVertex3f_)(GLfloat x, GLfloat y, GLfloat z);
extern void (GLAPIENTRY *qglVertex2f_)(GLfloat x, GLfloat y);
extern void (GLAPIENTRY *qglTexCoord4f_)(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
extern void (GLAPIENTRY *qglTexCoord3f_)(GLfloat s, GLfloat t, GLfloat r);
extern void (GLAPIENTRY *qglTexCoord2f_)(GLfloat s, GLfloat t);
extern void (GLAPIENTRY *qglTexCoord1f_)(GLfloat s);
extern void (GLAPIENTRY *qglColor4f_)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
extern void (GLAPIENTRY *qglArrayElement_)(GLint i);
extern void (GLAPIENTRY *qglTexCoordPointer_)(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr);
extern void (GLAPIENTRY *qglColorPointer_)(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr);
extern void (GLAPIENTRY *qglNormalPointer_)(GLenum type, GLsizei stride, const GLvoid *ptr);
extern void (GLAPIENTRY *qglVertexPointer_)(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr);
extern void (GLAPIENTRY *qglColorMask_)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
extern void (GLAPIENTRY *qglDrawElements_)(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
extern void (GLAPIENTRY *qglDepthRange_)(GLclampd near_val, GLclampd far_val);
extern void (GLAPIENTRY *qglDepthMask_)(GLboolean flag);
extern void (GLAPIENTRY *qglDepthFunc_)(GLenum func);
extern void (GLAPIENTRY *qglClearDepth_)(GLclampd depth);
extern void (GLAPIENTRY *qglFlush_)(void);
extern void (GLAPIENTRY *qglFinish_)(void);
extern const GLubyte* (GLAPIENTRY *qglGetString_)(GLenum name);
extern GLenum (GLAPIENTRY *qglGetError_)(void);
extern void (GLAPIENTRY *qglGetIntegerv_)(GLenum pname, GLint *params);
extern void (GLAPIENTRY *qglGetFloatv_)(GLenum pname, GLfloat *params);
extern void (GLAPIENTRY *qglGetDoublev_)(GLenum pname, GLdouble *params);
extern void (GLAPIENTRY *qglGetBooleanv_)(GLenum pname, GLboolean *params);
extern void (GLAPIENTRY *qglDisableClientState_)(GLenum cap);
extern void (GLAPIENTRY *qglEnableClientState_)(GLenum cap);
extern GLboolean (GLAPIENTRY *qglIsEnabled_)(GLenum cap);
extern void (GLAPIENTRY *qglDisable_)(GLenum cap);
extern void (GLAPIENTRY *qglEnable_)(GLenum cap);
extern void (GLAPIENTRY *qglDrawBuffer_)(GLenum mode);
extern void (GLAPIENTRY *qglCullFace_)(GLenum mode);
extern void (GLAPIENTRY *qglBlendFunc_)(GLenum sfactor, GLenum dfactor);
extern void (GLAPIENTRY *qglAlphaFunc_)(GLenum func, GLclampf ref);
extern void (GLAPIENTRY *qglClearColor_)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
extern void (GLAPIENTRY *qglClear_)(GLbitfield mask);

void debug_gl_start(void);
void debug_SDL_GL_SwapBuffers(void);

#else


#define qglPolygonStipple_ qglPolygonStipple
#define qglPolygonMode_ qglPolygonMode
#define qglPolygonOffset_ qglPolygonOffset
#define qglScissor_ qglScissor
#define qglCopyTexSubImage2D_ qglCopyTexSubImage2D
#define qglCopyTexSubImage1D_ qglCopyTexSubImage1D
#define qglCopyTexImage2D_ qglCopyTexImage2D
#define qglCopyTexImage1D_ qglCopyTexImage1D
#define qglTexImage2D_ qglTexImage2D
#define qglTexImage1D_ qglTexImage1D
#define qglBindTexture_ qglBindTexture
#define qglDeleteTextures_ qglDeleteTextures
#define qglGenTextures_ qglGenTextures
#define qglPixelStorei_ qglPixelStorei
#define qglTexParameteri_ qglTexParameteri
#define qglTexSubImage2D_ qglTexSubImage2D
#define qglTexSubImage1D_ qglTexSubImage1D
#define qglTexEnvi_ qglTexEnvi
#define qglClearStencil_ qglClearStencil
#define qglStencilOpSeparate_ qglStencilOpSeparate
#define qglStencilOp_ qglStencilOp
#define qglStencilMask_ qglStencilMask
#define qglStencilFuncSeparate_ qglStencilFuncSeparate
#define qglStencilFunc_ qglStencilFunc
#define qglReadPixels_ qglReadPixels
#define qglTranslatef_ qglTranslatef
#define qglScalef_ qglScalef
#define qglRotatef_ qglRotatef
#define qglMultMatrixf_ qglMultMatrixf
#define qglLoadMatrixf_ qglLoadMatrixf
#define qglLoadMatrixd_ qglLoadMatrixd
#define qglLoadIdentity_ qglLoadIdentity
#define qglPopMatrix_ qglPopMatrix
#define qglPushMatrix_ qglPushMatrix
#define qglViewport_ qglViewport
#define qglFrustum_ qglFrustum
#define qglOrtho_ qglOrtho
#define qglMatrixMode_ qglMatrixMode
#define qglPointSize_ qglPointSize
#define qglLineWidth_ qglLineWidth
#define qglEnd_ qglEnd
#define qglBegin_ qglBegin
#define qglVertex3f_ qglVertex3f
#define qglVertex2f_ qglVertex2f
#define qglTexCoord4f_ qglTexCoord4f
#define qglTexCoord3f_ qglTexCoord3f
#define qglTexCoord2f_ qglTexCoord2f
#define qglTexCoord1f_ qglTexCoord1f
#define qglColor4f_ qglColor4f
#define qglArrayElement_ qglArrayElement
#define qglTexCoordPointer_ qglTexCoordPointer
#define qglColorPointer_ qglColorPointer
#define qglNormalPointer_ qglNormalPointer
#define qglVertexPointer_ qglVertexPointer
#define qglColorMask_ qglColorMask
#define qglDrawElements_ qglDrawElements
#define qglDepthRange_ qglDepthRange
#define qglDepthMask_ qglDepthMask
#define qglDepthFunc_ qglDepthFunc
#define qglClearDepth_ qglClearDepth
#define qglFlush_ qglFlush
#define qglFinish_ qglFinish
#define qglGetString_ qglGetString
#define qglGetError_ qglGetError
#define qglGetIntegerv_ qglGetIntegerv
#define qglGetFloatv_ qglGetFloatv
#define qglGetDoublev_ qglGetDoublev
#define qglGetBooleanv_ qglGetBooleanv
#define qglDisableClientState_ qglDisableClientState
#define qglEnableClientState_ qglEnableClientState
#define qglIsEnabled_ qglIsEnabled
#define qglDisable_ qglDisable
#define qglEnable_ qglEnable
#define qglDrawBuffer_ qglDrawBuffer
#define qglCullFace_ qglCullFace
#define qglBlendFunc_ qglBlendFunc
#define qglAlphaFunc_ qglAlphaFunc
#define qglClearColor_ qglClearColor
#define qglClear_ qglClear

#define debug_SDL_GL_SwapBuffers() SDL_GL_SwapBuffers()
#define debug_gl_start()

#endif
