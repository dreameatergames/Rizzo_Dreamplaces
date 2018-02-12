
#ifdef DEBUG_GL


#include<stdio.h>
#include<stdlib.h>
#include<SDL.h>

#include "quakedef.h"
#include "glquake.h"

#if 0
#define MAX_FRAMES 18
#define MAX_TOTAL_FRAMES 20
#define MAX_TEXS 640
#define START_DEBUG_NOW 1
#else
#define MAX_FRAMES 3000
#define MAX_TOTAL_FRAMES 4000
#define MAX_TEXS 6400
#define START_DEBUG_NOW 0
#endif


void (GLAPIENTRY *qglPolygonMode_)(GLenum face, GLenum mode);
void (GLAPIENTRY *qglPolygonStipple_)(const GLubyte *mask);
void (GLAPIENTRY *qglPolygonOffset_)(GLfloat factor, GLfloat units);
void (GLAPIENTRY *qglScissor_)(GLint x, GLint y, GLsizei width, GLsizei height);
void (GLAPIENTRY *qglCopyTexSubImage2D_)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void (GLAPIENTRY *qglCopyTexSubImage1D_)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void (GLAPIENTRY *qglCopyTexImage2D_)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void (GLAPIENTRY *qglCopyTexImage1D_)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
void (GLAPIENTRY *qglTexImage2D_)(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
void (GLAPIENTRY *qglTexImage1D_)(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
void (GLAPIENTRY *qglBindTexture_)(GLenum target, GLuint texture);
void (GLAPIENTRY *qglDeleteTextures_)(GLsizei n, const GLuint *textures);
void (GLAPIENTRY *qglGenTextures_)(GLsizei n, GLuint *textures);
void (GLAPIENTRY *qglPixelStorei_)(GLenum pname, GLint param);
void (GLAPIENTRY *qglTexParameteri_)(GLenum target, GLenum pname, GLint param);
void (GLAPIENTRY *qglTexSubImage2D_)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
void (GLAPIENTRY *qglTexSubImage1D_)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
void (GLAPIENTRY *qglTexEnvi_)(GLenum target, GLenum pname, GLint param);
void (GLAPIENTRY *qglClearStencil_)(GLint s);
void (GLAPIENTRY *qglStencilOpSeparate_)(GLenum, GLenum, GLenum, GLenum);
void (GLAPIENTRY *qglStencilOp_)(GLenum fail, GLenum zfail, GLenum zpass);
void (GLAPIENTRY *qglStencilMask_)(GLuint mask);
void (GLAPIENTRY *qglStencilFuncSeparate_)(GLenum, GLenum, GLint, GLuint);
void (GLAPIENTRY *qglStencilFunc_)(GLenum func, GLint ref, GLuint mask);
void (GLAPIENTRY *qglReadPixels_)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
void (GLAPIENTRY *qglTranslatef_)(GLfloat x, GLfloat y, GLfloat z);
void (GLAPIENTRY *qglScalef_)(GLfloat x, GLfloat y, GLfloat z);
void (GLAPIENTRY *qglRotatef_)(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
void (GLAPIENTRY *qglMultMatrixf_)(const GLfloat *m);
void (GLAPIENTRY *qglLoadMatrixf_)(const GLfloat *m);
void (GLAPIENTRY *qglLoadMatrixd_)(const GLdouble *m);
void (GLAPIENTRY *qglLoadIdentity_)(void);
void (GLAPIENTRY *qglPopMatrix_)(void);
void (GLAPIENTRY *qglPushMatrix_)(void);
void (GLAPIENTRY *qglViewport_)(GLint x, GLint y, GLsizei width, GLsizei height);
void (GLAPIENTRY *qglFrustum_)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val);
void (GLAPIENTRY *qglOrtho_)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val);
void (GLAPIENTRY *qglMatrixMode_)(GLenum mode);
void (GLAPIENTRY *qglPointSize_)(GLfloat size);
void (GLAPIENTRY *qglLineWidth_)(GLfloat width);
void (GLAPIENTRY *qglEnd_)(void);
void (GLAPIENTRY *qglBegin_)(GLenum mode);
void (GLAPIENTRY *qglVertex3f_)(GLfloat x, GLfloat y, GLfloat z);
void (GLAPIENTRY *qglVertex2f_)(GLfloat x, GLfloat y);
void (GLAPIENTRY *qglTexCoord4f_)(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void (GLAPIENTRY *qglTexCoord3f_)(GLfloat s, GLfloat t, GLfloat r);
void (GLAPIENTRY *qglTexCoord2f_)(GLfloat s, GLfloat t);
void (GLAPIENTRY *qglTexCoord1f_)(GLfloat s);
void (GLAPIENTRY *qglColor4f_)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void (GLAPIENTRY *qglArrayElement_)(GLint i);
void (GLAPIENTRY *qglTexCoordPointer_)(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr);
void (GLAPIENTRY *qglColorPointer_)(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr);
void (GLAPIENTRY *qglNormalPointer_)(GLenum type, GLsizei stride, const GLvoid *ptr);
void (GLAPIENTRY *qglVertexPointer_)(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr);
void (GLAPIENTRY *qglColorMask_)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
void (GLAPIENTRY *qglDrawElements_)(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
void (GLAPIENTRY *qglDepthRange_)(GLclampd near_val, GLclampd far_val);
void (GLAPIENTRY *qglDepthMask_)(GLboolean flag);
void (GLAPIENTRY *qglDepthFunc_)(GLenum func);
void (GLAPIENTRY *qglClearDepth_)(GLclampd depth);
void (GLAPIENTRY *qglFlush_)(void);
void (GLAPIENTRY *qglFinish_)(void);
const GLubyte* (GLAPIENTRY *qglGetString_)(GLenum name);
GLenum (GLAPIENTRY *qglGetError_)(void);
void (GLAPIENTRY *qglGetIntegerv_)(GLenum pname, GLint *params);
void (GLAPIENTRY *qglGetFloatv_)(GLenum pname, GLfloat *params);
void (GLAPIENTRY *qglGetDoublev_)(GLenum pname, GLdouble *params);
void (GLAPIENTRY *qglGetBooleanv_)(GLenum pname, GLboolean *params);
void (GLAPIENTRY *qglDisableClientState_)(GLenum cap);
void (GLAPIENTRY *qglEnableClientState_)(GLenum cap);
GLboolean (GLAPIENTRY *qglIsEnabled_)(GLenum cap);
void (GLAPIENTRY *qglDisable_)(GLenum cap);
void (GLAPIENTRY *qglEnable_)(GLenum cap);
void (GLAPIENTRY *qglDrawBuffer_)(GLenum mode);
void (GLAPIENTRY *qglCullFace_)(GLenum mode);
void (GLAPIENTRY *qglBlendFunc_)(GLenum sfactor, GLenum dfactor);
void (GLAPIENTRY *qglAlphaFunc_)(GLenum func, GLclampf ref);
void (GLAPIENTRY *qglClearColor_)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
void (GLAPIENTRY *qglClear_)(GLbitfield mask);

int static debug_gl_now=START_DEBUG_NOW;
static GLuint texs[MAX_TEXS];


static void printnum(void)
{
	static unsigned n=0;
	if (n)
		if (debug_gl_now) puts("DEBUG_GL:};\nDEBUG_GL:#endif");
	if (n>=MAX_FRAMES)
	{
		int i;
		for(i=n;i<MAX_TOTAL_FRAMES && debug_gl_now;i++)
		{
			printf("DEBUG_GL:#ifdef FRAME_%i\n",i);
			printf("DEBUG_GL:void run_%i(void){ }\n",i);
			puts("DEBUG_GL:#endif");
		}
		if (debug_gl_now) fflush(stdout);
		SDL_Delay(1000);
		exit(0);
	}
	if (debug_gl_now) printf("DEBUG_GL:#ifdef FRAME_%i\n",n);
	if (debug_gl_now) printf("DEBUG_GL:void run_%i(void)\n",n);
	if (debug_gl_now) puts("DEBUG_GL:{");
	if (debug_gl_now) fflush(stdout);
	n++;
}

static unsigned int sizeofgl(GLenum type)
{
	switch(type)
	{
		case GL_BYTE:
		case GL_UNSIGNED_BYTE:
			return sizeof(GLbyte);
		case GL_SHORT:
		case GL_UNSIGNED_SHORT:
			return sizeof(GLshort);
		case GL_FLOAT:
			return sizeof(GLfloat);
		case GL_DOUBLE:
			return sizeof(GLdouble);
		case GL_2_BYTES:
			return 2;
		case GL_3_BYTES:
			return 1;
		case GL_4_BYTES:
			return 4;
		default:
			return sizeof(GLint);
	}
}


static char *constgl(GLint c)
{
	char tmp_[16];
	char *tmp=(char *)&tmp_;
	switch(c)
	{
		case 0x1700: return "GL_MODELVIEW";
		case 0x1701: return "GL_PROJECTION";
		case 0x1702: return "GL_TEXTURE";
		case 0x0BA0: return "GL_MATRIX_MODE";
		case 0x0BA6: return "GL_MODELVIEW_MATRIX";
		case 0x0BA7: return "GL_PROJECTION_MATRIX";
		case 0x0BA8: return "GL_TEXTURE_MATRIX";
		case 0x0B71: return "GL_DEPTH_TEST";
		case 0x0B44: return "GL_CULL_FACE";
		case 0x0BE2: return "GL_BLEND";
		case 0x0BC0: return "GL_ALPHA_TEST";
		case 0x0: return "GL_ZERO";
		case 0x1: return "GL_ONE";
		case 0x0300: return "GL_SRC_COLOR";
		case 0x0301: return "GL_ONE_MINUS_SRC_COLOR";
		case 0x0306: return "GL_DST_COLOR";
		case 0x0307: return "GL_ONE_MINUS_DST_COLOR";
		case 0x0302: return "GL_SRC_ALPHA";
		case 0x0303: return "GL_ONE_MINUS_SRC_ALPHA";
		case 0x0304: return "GL_DST_ALPHA";
		case 0x0305: return "GL_ONE_MINUS_DST_ALPHA";
		case 0x0308: return "GL_SRC_ALPHA_SATURATE";
		case 0x8001: return "GL_CONSTANT_COLOR";
		case 0x8002: return "GL_ONE_MINUS_CONSTANT_COLOR";
		case 0x8003: return "GL_CONSTANT_ALPHA";
		case 0x8004: return "GL_ONE_MINUS_CONSTANT_ALPHA";
		case 0x2300: return "GL_TEXTURE_ENV";
		case 0x2200: return "GL_TEXTURE_ENV_MODE";
		case 0x0DE0: return "GL_TEXTURE_1D";
		case 0x0DE1: return "GL_TEXTURE_2D";
		case 0x2802: return "GL_TEXTURE_WRAP_S";
		case 0x2803: return "GL_TEXTURE_WRAP_T";
		case 0x8072: return "GL_TEXTURE_WRAP_R";
		case 0x1004: return "GL_TEXTURE_BORDER_COLOR";
		case 0x2800: return "GL_TEXTURE_MAG_FILTER";
		case 0x2801: return "GL_TEXTURE_MIN_FILTER";
		case 0x0D05: return "GL_PACK_ALIGNMENT";
		case 0x0CF5: return "GL_UNPACK_ALIGNMENT";
		case 0x8068: return "GL_TEXTURE_BINDING_1D";
		case 0x8069: return "GL_TEXTURE_BINDING_2D";
		case 0x2600: return "GL_NEAREST";
		case 0x2601: return "GL_LINEAR";
		case 0x2700: return "GL_NEAREST_MIPMAP_NEAREST";
		case 0x2702: return "GL_NEAREST_MIPMAP_LINEAR";
		case 0x2701: return "GL_LINEAR_MIPMAP_NEAREST";
		case 0x2703: return "GL_LINEAR_MIPMAP_LINEAR";
		case 0x1B01: return "GL_LINE";
		case 0x1B02: return "GL_FILL";
		case 0x84FE: return "GL_TEXTURE_MAX_ANISOTROPY_EXT";
		case 0x84FF: return "GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT";
		case 0x0104: return "GL_ADD";
		case 0x2101: return "GL_DECAL";
		case 0x2100: return "GL_MODULATE";
		case 0x2901: return "GL_REPEAT";
		case 0x2900: return "GL_CLAMP";
//		case 0x0000: return "GL_POINTS";
//		case 0x0001: return "GL_LINES";
		case 0x0002: return "GL_LINE_LOOP";
		case 0x0003: return "GL_LINE_STRIP";
		case 0x0004: return "GL_TRIANGLES";
		case 0x0005: return "GL_TRIANGLE_STRIP";
		case 0x0006: return "GL_TRIANGLE_FAN";
		case 0x0007: return "GL_QUADS";
		case 0x0008: return "GL_QUAD_STRIP";
		case 0x0009: return "GL_POLYGON";
//		case 0x0: return "GL_FALSE";
//		case 0x1: return "GL_TRUE";
		case 0x1400: return "GL_BYTE";
		case 0x1401: return "GL_UNSIGNED_BYTE";
		case 0x1402: return "GL_SHORT";
		case 0x1403: return "GL_UNSIGNED_SHORT";
		case 0x1404: return "GL_INT";
		case 0x1405: return "GL_UNSIGNED_INT";
		case 0x1406: return "GL_FLOAT";
		case 0x140A: return "GL_DOUBLE";
		case 0x1407: return "GL_2_BYTES";
		case 0x1408: return "GL_3_BYTES";
		case 0x1409: return "GL_4_BYTES";
		case 0x8074: return "GL_VERTEX_ARRAY";
		case 0x8075: return "GL_NORMAL_ARRAY";
		case 0x8076: return "GL_COLOR_ARRAY";
		case 0x8077: return "GL_INDEX_ARRAY";
		case 0x8078: return "GL_TEXTURE_COORD_ARRAY";
		case 0x8079: return "GL_EDGE_FLAG_ARRAY";
//		case 0: return "GL_NONE";
//		case 0x0400: return "GL_FRONT_LEFT";
		case 0x0401: return "GL_FRONT_RIGHT";
		case 0x0402: return "GL_BACK_LEFT";
		case 0x0403: return "GL_BACK_RIGHT";
		case 0x0404: return "GL_FRONT";
		case 0x0405: return "GL_BACK";
		case 0x0406: return "GL_LEFT";
		case 0x0407: return "GL_RIGHT";
		case 0x0408: return "GL_FRONT_AND_BACK";
		case 0x0409: return "GL_AUX0";
		case 0x040A: return "GL_AUX1";
		case 0x040B: return "GL_AUX2";
		case 0x040C: return "GL_AUX3";
		case 0x1F00: return "GL_VENDOR";
		case 0x1F01: return "GL_RENDERER";
		case 0x1F02: return "GL_VERSION";
		case 0x1F03: return "GL_EXTENSIONS";
//		case 0x0: return "GL_NO_ERROR";
		case 0x0501: return "GL_INVALID_VALUE";
		case 0x0500: return "GL_INVALID_ENUM";
		case 0x0502: return "GL_INVALID_OPERATION";
		case 0x0503: return "GL_STACK_OVERFLOW";
		case 0x0504: return "GL_STACK_UNDERFLOW";
		case 0x0505: return "GL_OUT_OF_MEMORY";
		case 0x0BD0: return "GL_DITHER";
		case 0x1907: return "GL_RGB";
		case 0x1908: return "GL_RGBA";
		case 0x0D33: return "GL_MAX_TEXTURE_SIZE";
//		case 0x0200: return "GL_NEVER";
		case 0x0201: return "GL_LESS";
		case 0x0202: return "GL_EQUAL";
		case 0x0203: return "GL_LEQUAL";
		case 0x0204: return "GL_GREATER";
		case 0x0205: return "GL_NOTEQUAL";
		case 0x0206: return "GL_GEQUAL";
		case 0x0207: return "GL_ALWAYS";
		case 0x0D14: return "GL_RED_SCALE";
		case 0x0D18: return "GL_GREEN_SCALE";
		case 0x0D1A: return "GL_BLUE_SCALE";
		case 0x0D1C: return "GL_ALPHA_SCALE";
		case 0x0100: return "GL_DEPTH_BUFFER_BIT";
		case 0x4000: return "GL_COLOR_BUFFER_BIT";
		case 0x0200: return "GL_ACCUM_BUFFER_BIT";
		case 0x0400: return "GL_STENCIL_BUFFER_BIT";
		case 0x0B90: return "GL_STENCIL_TEST";
		case 0x1E00: return "GL_KEEP";
		case 0x1E01: return "GL_REPLACE";
		case 0x1E02: return "GL_INCR";
		case 0x1E03: return "GL_DECR";
		case 0x8038: return "GL_POLYGON_OFFSET_FACTOR";
		case 0x2A00: return "GL_POLYGON_OFFSET_UNITS";
		case 0x2A01: return "GL_POLYGON_OFFSET_POINT";
		case 0x2A02: return "GL_POLYGON_OFFSET_LINE";
		case 0x8037: return "GL_POLYGON_OFFSET_FILL";
		case 0x0B10: return "GL_POINT_SMOOTH";
		case 0x0B20: return "GL_LINE_SMOOTH";
		case 0x0B41: return "GL_POLYGON_SMOOTH";
		case 0x0B42: return "GL_POLYGON_STIPPLE";
		case 0x84E0: return "GL_ACTIVE_TEXTURE_ARB";
		case 0x84E1: return "GL_CLIENT_ACTIVE_TEXTURE_ARB";
		case 0x84E2: return "GL_MAX_TEXTURE_UNITS_ARB";
		case 0x84C0: return "GL_TEXTURE0_ARB";
		case 0x84C1: return "GL_TEXTURE1_ARB";
		case 0x84C2: return "GL_TEXTURE2_ARB";
		case 0x84C3: return "GL_TEXTURE3_ARB";
		case 0x84C4: return "GL_TEXTURE4_ARB";
		case 0x84C5: return "GL_TEXTURE5_ARB";
		case 0x84C6: return "GL_TEXTURE6_ARB";
		case 0x84C7: return "GL_TEXTURE7_ARB";
		case 0x84C8: return "GL_TEXTURE8_ARB";
		case 0x84C9: return "GL_TEXTURE9_ARB";
		case 0x84CA: return "GL_TEXTURE10_ARB";
		case 0x84CB: return "GL_TEXTURE11_ARB";
		case 0x84CC: return "GL_TEXTURE12_ARB";
		case 0x84CD: return "GL_TEXTURE13_ARB";
		case 0x84CE: return "GL_TEXTURE14_ARB";
		case 0x84CF: return "GL_TEXTURE15_ARB";
		case 0x84D0: return "GL_TEXTURE16_ARB";
		case 0x84D1: return "GL_TEXTURE17_ARB";
		case 0x84D2: return "GL_TEXTURE18_ARB";
		case 0x84D3: return "GL_TEXTURE19_ARB";
		case 0x84D4: return "GL_TEXTURE20_ARB";
		case 0x84D5: return "GL_TEXTURE21_ARB";
		case 0x84D6: return "GL_TEXTURE22_ARB";
		case 0x84D7: return "GL_TEXTURE23_ARB";
		case 0x84D8: return "GL_TEXTURE24_ARB";
		case 0x84D9: return "GL_TEXTURE25_ARB";
		case 0x84DA: return "GL_TEXTURE26_ARB";
		case 0x84DB: return "GL_TEXTURE27_ARB";
		case 0x84DC: return "GL_TEXTURE28_ARB";
		case 0x84DD: return "GL_TEXTURE29_ARB";
		case 0x84DE: return "GL_TEXTURE30_ARB";
		case 0x84DF: return "GL_TEXTURE31_ARB";
		case 0x8570: return "GL_COMBINE_ARB";
		case 0x8571: return "GL_COMBINE_RGB_ARB";
		case 0x8572: return "GL_COMBINE_ALPHA_ARB";
		case 0x8580: return "GL_SOURCE0_RGB_ARB";
		case 0x8581: return "GL_SOURCE1_RGB_ARB";
		case 0x8582: return "GL_SOURCE2_RGB_ARB";
		case 0x8588: return "GL_SOURCE0_ALPHA_ARB";
		case 0x8589: return "GL_SOURCE1_ALPHA_ARB";
		case 0x858A: return "GL_SOURCE2_ALPHA_ARB";
		case 0x8590: return "GL_OPERAND0_RGB_ARB";
		case 0x8591: return "GL_OPERAND1_RGB_ARB";
		case 0x8592: return "GL_OPERAND2_RGB_ARB";
		case 0x8598: return "GL_OPERAND0_ALPHA_ARB";
		case 0x8599: return "GL_OPERAND1_ALPHA_ARB";
		case 0x859A: return "GL_OPERAND2_ALPHA_ARB";
		case 0x8573: return "GL_RGB_SCALE_ARB";
		case 0x8574: return "GL_ADD_SIGNED_ARB";
		case 0x8575: return "GL_INTERPOLATE_ARB";
		case 0x84E7: return "GL_SUBTRACT_ARB";
		case 0x8576: return "GL_CONSTANT_ARB";
		case 0x8577: return "GL_PRIMARY_COLOR_ARB";
		case 0x8578: return "GL_PREVIOUS_ARB";
		case 0x80E8: return "GL_MAX_ELEMENTS_VERTICES";
		case 0x80E9: return "GL_MAX_ELEMENTS_INDICES";
		case 0x806B: return "GL_PACK_SKIP_IMAGES";
		case 0x806C: return "GL_PACK_IMAGE_HEIGHT";
		case 0x806D: return "GL_UNPACK_SKIP_IMAGES";
		case 0x806E: return "GL_UNPACK_IMAGE_HEIGHT";
		case 0x806F: return "GL_TEXTURE_3D";
		case 0x8070: return "GL_PROXY_TEXTURE_3D";
		case 0x8071: return "GL_TEXTURE_DEPTH";
		case 0x8073: return "GL_MAX_3D_TEXTURE_SIZE";
		case 0x806A: return "GL_TEXTURE_BINDING_3D";
		case 0x8511: return "GL_NORMAL_MAP_ARB";
		case 0x8512: return "GL_REFLECTION_MAP_ARB";
		case 0x8513: return "GL_TEXTURE_CUBE_MAP_ARB";
		case 0x8514: return "GL_TEXTURE_BINDING_CUBE_MAP_ARB";
		case 0x8515: return "GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB";
		case 0x8516: return "GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB";
		case 0x8517: return "GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB";
		case 0x8518: return "GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB";
		case 0x8519: return "GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB";
		case 0x851A: return "GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB";
		case 0x851B: return "GL_PROXY_TEXTURE_CUBE_MAP_ARB";
		case 0x851C: return "GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB";
		case 0x86AE: return "GL_DOT3_RGB_ARB";
		case 0x86AF: return "GL_DOT3_RGBA_ARB";
		case 0x0C11: return "GL_SCISSOR_TEST";
		case 0x0C10: return "GL_SCISSOR_BOX";
		case 0x812F: return "GL_CLAMP_TO_EDGE";
		case 0x8800: return "GL_STENCIL_BACK_FUNC";
		case 0x8801: return "GL_STENCIL_BACK_FAIL";
		case 0x8802: return "GL_STENCIL_BACK_PASS_DEPTH_FAIL";
		case 0x8803: return "GL_STENCIL_BACK_PASS_DEPTH_PASS";
		case 0x8910: return "GL_STENCIL_TEST_TWO_SIDE_EXT";
		case 0x8911: return "GL_ACTIVE_STENCIL_FACE_EXT";
		case 0x8006: return "GL_FUNC_ADD_EXT";
		case 0x8007: return "GL_MIN_EXT";
		case 0x8008: return "GL_MAX_EXT";
		case 0x8009: return "GL_BLEND_EQUATION_EXT";
		case 0x800A: return "GL_FUNC_SUBTRACT_EXT";
		case 0x800B: return "GL_FUNC_REVERSE_SUBTRACT_EXT";
		case 0x8892: return "GL_ARRAY_BUFFER_ARB";
		case 0x8893: return "GL_ELEMENT_ARRAY_BUFFER_ARB";
		case 0x8894: return "GL_ARRAY_BUFFER_BINDING_ARB";
		case 0x8895: return "GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB";
		case 0x8896: return "GL_VERTEX_ARRAY_BUFFER_BINDING_ARB";
		case 0x8897: return "GL_NORMAL_ARRAY_BUFFER_BINDING_ARB";
		case 0x8898: return "GL_COLOR_ARRAY_BUFFER_BINDING_ARB";
		case 0x8899: return "GL_INDEX_ARRAY_BUFFER_BINDING_ARB";
		case 0x889A: return "GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB";
		case 0x889B: return "GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB";
		case 0x889C: return "GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB";
		case 0x889D: return "GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB";
		case 0x889E: return "GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB";
		case 0x889F: return "GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB";
		case 0x88E0: return "GL_STREAM_DRAW_ARB";
		case 0x88E1: return "GL_STREAM_READ_ARB";
		case 0x88E2: return "GL_STREAM_COPY_ARB";
		case 0x88E4: return "GL_STATIC_DRAW_ARB";
		case 0x88E5: return "GL_STATIC_READ_ARB";
		case 0x88E6: return "GL_STATIC_COPY_ARB";
		case 0x88E8: return "GL_DYNAMIC_DRAW_ARB";
		case 0x88E9: return "GL_DYNAMIC_READ_ARB";
		case 0x88EA: return "GL_DYNAMIC_COPY_ARB";
		case 0x88B8: return "GL_READ_ONLY_ARB";
		case 0x88B9: return "GL_WRITE_ONLY_ARB";
		case 0x88BA: return "GL_READ_WRITE_ARB";
		case 0x8764: return "GL_BUFFER_SIZE_ARB";
		case 0x8765: return "GL_BUFFER_USAGE_ARB";
		case 0x88BB: return "GL_BUFFER_ACCESS_ARB";
		case 0x88BC: return "GL_BUFFER_MAPPED_ARB";
		case 0x88BD: return "GL_BUFFER_MAP_POINTER_ARB";
		case 0x8B40: return "GL_PROGRAM_OBJECT_ARB";
		case 0x8B4E: return "GL_OBJECT_TYPE_ARB";
		case 0x8B4F: return "GL_OBJECT_SUBTYPE_ARB";
		case 0x8B80: return "GL_OBJECT_DELETE_STATUS_ARB";
		case 0x8B81: return "GL_OBJECT_COMPILE_STATUS_ARB";
		case 0x8B82: return "GL_OBJECT_LINK_STATUS_ARB";
		case 0x8B83: return "GL_OBJECT_VALIDATE_STATUS_ARB";
		case 0x8B84: return "GL_OBJECT_INFO_LOG_LENGTH_ARB";
		case 0x8B85: return "GL_OBJECT_ATTACHED_OBJECTS_ARB";
		case 0x8B86: return "GL_OBJECT_ACTIVE_UNIFORMS_ARB";
		case 0x8B87: return "GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB";
		case 0x8B88: return "GL_OBJECT_SHADER_SOURCE_LENGTH_ARB";
		case 0x8B48: return "GL_SHADER_OBJECT_ARB";
		case 0x8B50: return "GL_FLOAT_VEC2_ARB";
		case 0x8B51: return "GL_FLOAT_VEC3_ARB";
		case 0x8B52: return "GL_FLOAT_VEC4_ARB";
		case 0x8B53: return "GL_INT_VEC2_ARB";
		case 0x8B54: return "GL_INT_VEC3_ARB";
		case 0x8B55: return "GL_INT_VEC4_ARB";
		case 0x8B56: return "GL_BOOL_ARB";
		case 0x8B57: return "GL_BOOL_VEC2_ARB";
		case 0x8B58: return "GL_BOOL_VEC3_ARB";
		case 0x8B59: return "GL_BOOL_VEC4_ARB";
		case 0x8B5A: return "GL_FLOAT_MAT2_ARB";
		case 0x8B5B: return "GL_FLOAT_MAT3_ARB";
		case 0x8B5C: return "GL_FLOAT_MAT4_ARB";
		case 0x8B5D: return "GL_SAMPLER_1D_ARB";
		case 0x8B5E: return "GL_SAMPLER_2D_ARB";
		case 0x8B5F: return "GL_SAMPLER_3D_ARB";
		case 0x8B60: return "GL_SAMPLER_CUBE_ARB";
		case 0x8B61: return "GL_SAMPLER_1D_SHADOW_ARB";
		case 0x8B62: return "GL_SAMPLER_2D_SHADOW_ARB";
		case 0x8B63: return "GL_SAMPLER_2D_RECT_ARB";
		case 0x8B64: return "GL_SAMPLER_2D_RECT_SHADOW_ARB";
		case 0x8B31: return "GL_VERTEX_SHADER_ARB";
		case 0x8B4A: return "GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB";
		case 0x8B4B: return "GL_MAX_VARYING_FLOATS_ARB";
		case 0x8869: return "GL_MAX_VERTEX_ATTRIBS_ARB";
		case 0x8872: return "GL_MAX_TEXTURE_IMAGE_UNITS_ARB";
		case 0x8B4C: return "GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB";
		case 0x8B4D: return "GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB";
		case 0x8871: return "GL_MAX_TEXTURE_COORDS_ARB";
		case 0x8642: return "GL_VERTEX_PROGRAM_POINT_SIZE_ARB";
		case 0x8643: return "GL_VERTEX_PROGRAM_TWO_SIDE_ARB";
		case 0x8B89: return "GL_OBJECT_ACTIVE_ATTRIBUTES_ARB";
		case 0x8B8A: return "GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB";
		case 0x8622: return "GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB";
		case 0x8623: return "GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB";
		case 0x8624: return "GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB";
		case 0x8625: return "GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB";
		case 0x886A: return "GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB";
		case 0x8626: return "GL_CURRENT_VERTEX_ATTRIB_ARB";
		case 0x8645: return "GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB";
		case 0x8B30: return "GL_FRAGMENT_SHADER_ARB";
		case 0x8B49: return "GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB";
		case 0x8B8B: return "GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB";
		case 0x8B8C: return "GL_SHADING_LANGUAGE_VERSION_ARB";
		case 0x80E0: return "GL_BGR";
		case 0x80E1: return "GL_BGRA";
	}
	sprintf(tmp,"0x%X\n",c);
	return tmp;
}

void static debug_glPolygonStipple(const GLubyte *mask)
{
#ifndef DEBUG_GL_NO_TODO
	if (debug_gl_now) printf("DEBUG_GL:\tglPolygonStipple(const GLubyte *mask);\n");
	if (debug_gl_now) fflush(stdout);
	if (qglPolygonMode_)
		qglPolygonStipple_(mask);
	else
		puts("DEBUG_GL:\tglPolygonStipple not set");
	if (debug_gl_now) fflush(stdout);
#endif
}

void static debug_glPolygonMode(GLenum face, GLenum mode)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglPolygonMode(%s,%s);\n",constgl(face),constgl(mode));
	if (debug_gl_now) fflush(stdout);
	if (qglPolygonMode_)
		qglPolygonMode_(face,mode);
	else
		puts("DEBUG_GL:\tglPolygonMode not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glPolygonOffset(GLfloat factor, GLfloat units)
{
#ifndef DEBUG_GL_NO_TODO
	if (debug_gl_now) printf("DEBUG_GL:\tglPolygonOffset(%f,%f);\n",(double)factor,(double)units);
	if (debug_gl_now) fflush(stdout);
	if (qglPolygonOffset_)
		qglPolygonOffset_(factor,units);
	else
		puts("DEBUG_GL:\tglPolygonOffset not set");
	if (debug_gl_now) fflush(stdout);
#endif
}

void static debug_glScissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglScissor(%i, %i, %i, %i);\n",x,y,width,height);
	if (debug_gl_now) fflush(stdout);
	if (qglScissor_)
		qglScissor_(x,y,width,height);
	else
		puts("DEBUG_GL:\tglScissor not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
#ifndef DEBUG_GL_NO_TODO
#ifdef DEBUG_GL_NO_TODO
	if (level) return;
#endif
	if (debug_gl_now) printf("DEBUG_GL:\tglCopyTexSubImage2D(%s, %i, %i, %i, %i, %i, %i, %i);\n",constgl(target),level,xoffset,yoffset,x,y,width,height);
	if (debug_gl_now) fflush(stdout);
	if (qglCopyTexSubImage2D_)
		qglCopyTexSubImage2D_(target,level,xoffset,yoffset,x,y,width,height);
	else
		puts("DEBUG_GL:\tglCopyTexSubImage2D not set");
	if (debug_gl_now) fflush(stdout);
#endif
}

void static debug_glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)
{
#ifndef DEBUG_GL_NO_TODO
#ifdef DEBUG_GL_NO_TODO
	if (level) return;
#endif
	if (debug_gl_now) printf("DEBUG_GL:\tglCopyTexSubImage1D(%s, %i, %i, %i, %i, %i);\n",constgl(target),level,xoffset,x,y,width);
	if (debug_gl_now) fflush(stdout);
	if (qglCopyTexSubImage1D_)
		qglCopyTexSubImage1D_(target,level,xoffset,x,y,width);
	else
		puts("DEBUG_GL:\tglCopyTexSubImage1D not set");
	if (debug_gl_now) fflush(stdout);
#endif
}

void static debug_glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
#ifndef DEBUG_GL_NO_TODO
#ifdef DEBUG_GL_NO_TODO
	if (level) return;
#endif
	if (debug_gl_now) printf("DEBUG_GL:\tglCopyTexImage2D(%s, %i, %i, %i, %i, %i, %i, %i);\n",constgl(target),level,internalformat,x,y,width,height,border);
	if (debug_gl_now) fflush(stdout);
	if (qglCopyTexImage2D_)
		qglCopyTexImage2D_(target,level,internalformat,x,y,width,height,border);
	else
		puts("DEBUG_GL:\tglCopyTexImage2D not set");
	if (debug_gl_now) fflush(stdout);
#endif
}

void static debug_glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border)
{
#ifndef DEBUG_GL_NO_TODO
#ifdef DEBUG_GL_NO_TODO
	if (level) return;
#endif
	if (debug_gl_now) printf("DEBUG_GL:\tglCopyTexImage1D(%s, %i, %i, %i, %i, %i, %i);\n",constgl(target),level,internalformat,x,y,width,border);
	if (debug_gl_now) fflush(stdout);
	if (qglCopyTexImage1D_)
		qglCopyTexImage1D_(target,level,internalformat,x,y,width,border);
	else
		puts("DEBUG_GL:\tglCopyTexImage1D not set");
	if (debug_gl_now) fflush(stdout);
#endif
}

void static debug_glTexImage2D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
#ifdef DEBUG_GL_NO_TODO
	if (level) return;
#endif
	int i;
	unsigned char *pix=(unsigned char *)pixels;
	unsigned size=width*height;
	if (pix && size)
	{
	if (debug_gl_now) printf("DEBUG_GL:\t{\n");
	if (format==GL_RGB)
	{
	if (debug_gl_now) printf("DEBUG_GL:\t\tunsigned char pixels[%i]={",size*3);
	for(i=0;(i<size)&&(debug_gl_now);i++)
	{
	  if (!(i&7)) printf("\nDEBUG_GL:\t\t\t");
	  printf(" 0x%.2X, 0x%.2X, 0x%.2X, ",pix[i*3],pix[1+(i*3)],pix[2+(i*3)]);
	}
	}
	else
	{
	if (debug_gl_now) printf("DEBUG_GL:\t\tunsigned char pixels[%i]={",size*4);
	for(i=0;(i<size)&&(debug_gl_now);i++)
	{
	  if (!(i&7)) printf("\nDEBUG_GL:\t\t\t");
	  printf(" 0x%.2X, 0x%.2X, 0x%.2X, 0x%.2X, ",pix[i*4],pix[1+(i*4)],pix[2+(i*4)],pix[3+(i*4)]);
	}
	}
	if (debug_gl_now) printf("\nDEBUG_GL:\t\t\t};\n");
	if (debug_gl_now) printf("DEBUG_GL:\t\tglTexImage2D(%s, %i, %i, %i, %i, %i, %s, %s, &pixels);\n",constgl(target),level,internalFormat,width,height,border,constgl(format),constgl(type));
	if (debug_gl_now) printf("DEBUG_GL:\t}\n");
	}
	else
	if (debug_gl_now) printf("DEBUG_GL:\tglTexImage2D(%s, %i, %i, %i, %i, %i, %s, %s, NULL);\n",constgl(target),level,internalFormat,width,height,border,constgl(format),constgl(type));
	if (debug_gl_now) fflush(stdout);
	if (qglTexImage2D_)
		qglTexImage2D_(target,level,internalFormat,width,height,border,format,type,pixels);
	else
		puts("DEBUG_GL:\tglTexImage2D not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glTexImage1D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
#ifdef DEBUG_GL_NO_TODO
	if (level) return;
#endif
	int i;
	unsigned char *pix=(unsigned char *)pixels;
	unsigned size=width;
	if (pix && size)
	{
	if (debug_gl_now) printf("DEBUG_GL:\t{\n");
	if (format==GL_RGB)
	{
	if (debug_gl_now) printf("DEBUG_GL:\t\tunsigned char pixels[%i]={",size*3);
	for(i=0;(i<size)&&(debug_gl_now);i++)
	{
	  if (!(i&7)) printf("\nDEBUG_GL:\t\t\t");
	  printf(" 0x%.2X, 0x%.2X, 0x%.2X, ",pix[i*3],pix[1+(i*3)],pix[2+(i*3)]);
	}
	}
	else
	{
	if (debug_gl_now) printf("DEBUG_GL:\t\tunsigned char pixels[%i]={",size*4);
	for(i=0;(i<size)&&(debug_gl_now);i++)
	{
	  if (!(i&7)) printf("\nDEBUG_GL:\t\t\t");
	  printf(" 0x%.2X, 0x%.2X, 0x%.2X, 0x%.2X, ",pix[i*4],pix[1+(i*4)],pix[2+(i*4)],pix[3+(i*4)]);
	}
	}
	if (debug_gl_now) printf("\nDEBUG_GL:\t\t\t};\n");
	if (debug_gl_now) printf("DEBUG_GL:\t\tglTexImage1D(%s, %i, %i, %i, %i, %s, %s, &pixels);\n",constgl(target),level,internalFormat,width,border,constgl(format),constgl(type));
	if (debug_gl_now) printf("DEBUG_GL:\t}\n");
	}
	else
	if (debug_gl_now) printf("DEBUG_GL:\tglTexImage1D(%s, %i, %i, %i, %i, %s, %s, NULL);\n",constgl(target),level,internalFormat,width,border,constgl(format),constgl(type));
	if (debug_gl_now) fflush(stdout);
	if (qglTexImage1D_)
		qglTexImage1D_(target,level,internalFormat,width,border,format,type,pixels);
	else
		puts("DEBUG_GL:\tglTexImage1D not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glBindTexture(GLenum target, GLuint texture)
{
	int i;
	if (!texture)
		return;
	for(i=0;i<MAX_TEXS;i++)
		if ((texs[i]==texture)&&(texs[i])) break;
	if (i<=MAX_TEXS)
	{
	if (debug_gl_now) printf("DEBUG_GL:\tglBindTexture(%s, textures[%i]);\n",constgl(target),i);
	} else
	if (debug_gl_now) printf("DEBUG_GL:\tglBindTexture(%s, %i);\n",constgl(target),texture);
	if (debug_gl_now) fflush(stdout);
	if (qglBindTexture_)
		qglBindTexture_(target,texture);
	else
		puts("DEBUG_GL:\tglBindTexture not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glDeleteTextures(GLsizei n, const GLuint *textures)
{
	int i=0,j;
	if (!textures)
	{
	if (debug_gl_now) printf("DEBUG_GL:\tglDeleteTextures(%i, NULL);\n",n);
	}
	else
	{
	for(i=0;i<MAX_TEXS;i++)
		if (texs[i]==*textures) break;
	if (i<=MAX_TEXS)
	{
	if (debug_gl_now) printf("DEBUG_GL:\tglDeleteTextures(%i, &textures[%i]);\n",n,i);
	}else
	if (debug_gl_now) printf("DEBUG_GL:\tglDeleteTextures(%i, %i);\n",n,*textures);
	}
	if (debug_gl_now) fflush(stdout);
	if (qglDeleteTextures_)
		qglDeleteTextures_(n,textures);
	else
		puts("DEBUG_GL:\tglDeleteTextures not set");
	if (debug_gl_now) fflush(stdout);
	if (i<=MAX_TEXS)
	for(j=0;j<n;j++)
		texs[i+j]=0;
}


void static debug_glGenTextures(GLsizei n, GLuint *textures)
{
	int i,j;
	for(i=0;i<MAX_TEXS;i++)
		if (!texs[i]) break;
	if (debug_gl_now) printf("DEBUG_GL:\tglGenTextures(%i, &textures[%i]);\n",n,i);
	if (debug_gl_now) fflush(stdout);
	if (qglGenTextures_)
		qglGenTextures_(n,textures);
	else
		puts("DEBUG_GL:\tglGenTextures not set");
	if (debug_gl_now) fflush(stdout);
	for(j=0;(j<n)&&((i+j)<MAX_TEXS);j++)
		texs[i+j]=*textures;
}

void static debug_glPixelStorei(GLenum pname, GLint param)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglPixelStorei(%s, %s);\n",constgl(pname),constgl(param));
	if (debug_gl_now) fflush(stdout);
	if (qglPixelStorei_)
		qglPixelStorei_(pname,param);
	else
		puts("DEBUG_GL:\tglPixelStorei not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glTexParameteri(GLenum target, GLenum pname, GLint param)
{
#ifdef DEBUG_GL_NO_TODO
	if (pname!=GL_TEXTURE_MAG_FILTER && pname!=GL_TEXTURE_MIN_FILTER && pname!=GL_TEXTURE_WRAP_S && pname!=GL_TEXTURE_WRAP_T)
		return;
#endif
	if (debug_gl_now) printf("DEBUG_GL:\tglTexParameteri(%s, %s, %s);\n",constgl(target),constgl(pname),constgl(param));
	if (debug_gl_now) fflush(stdout);
	if (qglTexParameteri_)
		qglTexParameteri_(target,pname,param);
	else
		puts("DEBUG_GL:\tglTexParameteri not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
{
#ifdef DEBUG_GL_NO_TODO
	if (level) return;
#endif
	int i;
	unsigned char *pix=(unsigned char *)pixels;
	unsigned size=width*height;
	if (pix && size)
	{
	if (debug_gl_now) printf("DEBUG_GL:\t{\n");
	if (format==GL_RGB)
	{
	if (debug_gl_now) printf("DEBUG_GL:\t\tunsigned char pixels[%i]={",size*3);
	for(i=0;(i<size)&&(debug_gl_now);i++)
	{
	  if (!(i&7)) printf("\nDEBUG_GL:\t\t\t");
	  printf(" 0x%.2X, 0x%.2X, 0x%.2X, ",pix[i*3],pix[1+(i*3)],pix[2+(i*3)]);
	}
	}
	else
	{
	if (debug_gl_now) printf("DEBUG_GL:\t\tunsigned char pixels[%i]={",size*4);
	for(i=0;(i<size)&&(debug_gl_now);i++)
	{
	  if (!(i&7)) printf("\nDEBUG_GL:\t\t\t");
	  printf(" 0x%.2X, 0x%.2X, 0x%.2X, 0x%.2X, ",pix[i*4],pix[1+(i*4)],pix[2+(i*4)],pix[3+(i*4)]);
	}
	}
	if (debug_gl_now) printf("\nDEBUG_GL:\t\t\t};\n");
	if (debug_gl_now) printf("DEBUG_GL:\t\tglTexSubImage2D(%s,%i,%i,%i,%i,%i,%s,%s,&pixels);\n",constgl(target),level,xoffset,yoffset,width,height,constgl(format),constgl(type));
	if (debug_gl_now) printf("DEBUG_GL:\t}\n");
	}
	else
	if (debug_gl_now) printf("DEBUG_GL:\tglTexSubImage2D(%s,%i,%i,%i,%i,%i,%s,%s,NULL);\n",constgl(target),level,xoffset,yoffset,width,height,constgl(format),constgl(type));
	if (debug_gl_now) fflush(stdout);
	if (qglTexSubImage2D_)
		qglTexSubImage2D_(target,level,xoffset,yoffset,width,height,format,type,pixels);
	else
		puts("DEBUG_GL:\tglTexSubImage2D not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels)
{
#ifdef DEBUG_GL_NO_TODO
	if (level) return;
#endif
	int i;
	unsigned char *pix=(unsigned char *)pixels;
	unsigned size=width;
	if (pix && size)
	{
	if (debug_gl_now) printf("DEBUG_GL:\t{\n");
	if (format==GL_RGB)
	{
	if (debug_gl_now) printf("DEBUG_GL:\t\tunsigned char pixels[%i]={",size*3);
	for(i=0;(i<size)&&(debug_gl_now);i++)
	{
	  if (!(i&7)) printf("\nDEBUG_GL:\t\t\t");
	  printf(" 0x%.2X, 0x%.2X, 0x%.2X, ",pix[i*3],pix[1+(i*3)],pix[2+(i*3)]);
	}
	}
	else
	{
	if (debug_gl_now) printf("DEBUG_GL:\t\tunsigned char pixels[%i]={",size*4);
	for(i=0;(i<size)&&(debug_gl_now);i++)
	{
	  if (!(i&7)) printf("\nDEBUG_GL:\t\t\t");
	  printf(" 0x%.2X, 0x%.2X, 0x%.2X, 0x%.2X, ",pix[i*4],pix[1+(i*4)],pix[2+(i*4)],pix[3+(i*4)]);
	}
	}
	if (debug_gl_now) printf("\nDEBUG_GL:\t\t\t};\n");
	if (debug_gl_now) printf("DEBUG_GL:\t\tglTexSubImage1D(%s,%i,%i,%i,%s,%s,&pixels);\n",constgl(target),level,xoffset,width,constgl(format),constgl(type));
	if (debug_gl_now) printf("DEBUG_GL:\t}\n");
	}
	else
	if (debug_gl_now) printf("DEBUG_GL:\tglTexSubImage1D(%s,%i,%i,%i,%s,%s,NULL);\n",constgl(target),level,xoffset,width,constgl(format),constgl(type));
	if (debug_gl_now) fflush(stdout);
	if (qglTexSubImage1D_)
		qglTexSubImage1D_(target,level,xoffset,width,format,type,pixels);
	else
		puts("DEBUG_GL:\tglTexSubImage1D not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glTexEnvi(GLenum target, GLenum pname, GLint param)
{
#ifdef DEBUG_GL_NO_TODO
	if (param!= GL_REPLACE && param!=GL_MODULATE && param!=GL_DECAL)
		return;
#endif
	if (debug_gl_now) printf("DEBUG_GL:\tglTexEnvi(%s,%s,%s);\n",constgl(target),constgl(pname),constgl(param));
	if (debug_gl_now) fflush(stdout);
	if (qglTexEnvi_)
		qglTexEnvi_(target,pname,param);
	else
		puts("DEBUG_GL:\tglTexEnvi not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glClearStencil(GLint s)
{
#ifndef DEBUG_GL_NO_TODO
	if (debug_gl_now) printf("DEBUG_GL:\tglClearStencil(%i);\n",s);
	if (debug_gl_now) fflush(stdout);
	if (qglClearStencil_)
		qglClearStencil_(s);
	else
		puts("DEBUG_GL:\tglClearStencil not set");
	if (debug_gl_now) fflush(stdout);
#endif
}

void static debug_glStencilOpSeparate(GLenum a, GLenum b, GLenum c, GLenum d)
{
#ifndef DEBUG_GL_NO_TODO
	if (debug_gl_now) printf("DEBUG_GL:\tglStencilOpSeparate(%i, %i, %i, %i);\n",a,b,c,d);
	if (debug_gl_now) fflush(stdout);
	if (qglStencilOpSeparate_)
		qglStencilOpSeparate_(a,b,c,d);
	else
		puts("DEBUG_GL:\tglStencilOpSeparate not set");
	if (debug_gl_now) fflush(stdout);
#endif
}

void static debug_glStencilOp(GLenum fail, GLenum zfail, GLenum zpass)
{
#ifndef DEBUG_GL_NO_TODO
	if (debug_gl_now) printf("DEBUG_GL:\tglStencilOp(%i, %i, %i);\n",fail,zfail,zpass);
	if (debug_gl_now) fflush(stdout);
	if (qglStencilOp_)
		qglStencilOp_(fail,zfail,zpass);
	else
		puts("DEBUG_GL:\tglStencilOp not set");
	if (debug_gl_now) fflush(stdout);
#endif
}

void static debug_glStencilMask(GLuint mask)
{
#ifndef DEBUG_GL_NO_TODO
	if (debug_gl_now) printf("DEBUG_GL:\tglStencilMask(%i);\n",mask);
	if (debug_gl_now) fflush(stdout);
	if (qglStencilMask_)
		qglStencilMask_(mask);
	else
		puts("DEBUG_GL:\tglStencilMask not set");
	if (debug_gl_now) fflush(stdout);
#endif
}

void static debug_glStencilFuncSeparate(GLenum a, GLenum b, GLint c, GLuint d)
{
#ifndef DEBUG_GL_NO_TODO
	if (debug_gl_now) printf("DEBUG_GL:\tglStencilFuncSeparate(%i, %i, %i, %i);\n",a,b,c,d);
	if (debug_gl_now) fflush(stdout);
	if (qglStencilFuncSeparate_)
		qglStencilFuncSeparate_(a,b,c,d);
	else
		puts("DEBUG_GL:\tglStencilFuncSeparate not set");
	if (debug_gl_now) fflush(stdout);
#endif
}

void static debug_glStencilFunc(GLenum func, GLint ref, GLuint mask)
{
#ifndef DEBUG_GL_NO_TODO
	if (debug_gl_now) printf("DEBUG_GL:\tglStencilFunc(%i, %i, %i);\n",func,ref,mask);
	if (debug_gl_now) fflush(stdout);
	if (qglStencilFunc_)
		qglStencilFunc_(func,ref,mask);
	else
		puts("DEBUG_GL:\tglStencilFunc not set");
	if (debug_gl_now) fflush(stdout);
#endif
}

void static debug_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels)
{
#ifndef DEBUG_GL_NO_TODO
	if (debug_gl_now) printf("DEBUG_GL:\tglReadPixels(%i, %i, %i, %i, %s, %s, pixels);\n",x,y,width,height,constgl(format),constgl(type));
	if (debug_gl_now) fflush(stdout);
	if (qglReadPixels_)
		qglReadPixels_(x,y,width,height,format,type,pixels);
	else
		puts("DEBUG_GL:\tglReadPixels not set");
	if (debug_gl_now) fflush(stdout);
#endif
}

void static debug_glTranslatef(GLfloat x, GLfloat y, GLfloat z)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglTranslatef(%f, %f, %f);\n",(double)x,(double)y,(double)z);
	if (debug_gl_now) fflush(stdout);
	if (qglTranslatef_)
		qglTranslatef_(x,y,z);
	else
		puts("DEBUG_GL:\tglTranslatef not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glScalef(GLfloat x, GLfloat y, GLfloat z)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglScalef(%f, %f, %f);\n",(double)x,(double)y,(double)z);
	if (debug_gl_now) fflush(stdout);
	if (qglScalef_)
		qglScalef_(x,y,z);
	else
		puts("DEBUG_GL:\tglScalef not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglRotatef(%f, %f, %f, %f);\n",(double)angle,(double)x,(double)y,(double)z);
	if (debug_gl_now) fflush(stdout);
	if (qglRotatef_)
		qglRotatef_(angle,x,y,z);
	else
		puts("DEBUG_GL:\tglRotatef not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glMultMatrixf(const GLfloat *m)
{
	int i,j;
	if (m)
	{
	if (debug_gl_now) printf("DEBUG_GL:\t{\n");
	if (debug_gl_now) printf("DEBUG_GL:\t\tGLfloat m[4][4]={\n");
	for(j=0;j<4;j++)
	{
	 if (debug_gl_now) printf("DEBUG_GL:\t\t\t{\n");
	 for(i=0;i<4;i++)
	  if (debug_gl_now) printf(" %f,",(double)m[i+(j*4)]);
	 if (debug_gl_now) printf("},\n");
	}
	if (debug_gl_now) printf("DEBUG_GL:\t\t};\n");
	if (debug_gl_now) printf("DEBUG_GL:\t\tglMultMatrix((const GLfloat *)&m);\n");
	if (debug_gl_now) printf("DEBUG_GL:\t}\n");
	}
	else
	if (debug_gl_now) printf("DEBUG_GL:\tglMultMatrix(NULL);\n");
	if (debug_gl_now) fflush(stdout);
	if (qglMultMatrixf_)
		qglMultMatrixf_(m);
	else
		puts("DEBUG_GL:\tglMultMatrixf not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glLoadMatrixf(const GLfloat *m)
{
	int i,j;
	if (m)
	{
	if (debug_gl_now) printf("DEBUG_GL:\t{\n");
	if (debug_gl_now) printf("DEBUG_GL:\t\tGLfloat m[4][4]={\n");
	for(j=0;j<4;j++)
	{
	 if (debug_gl_now) printf("DEBUG_GL:\t\t\t{");
	 for(i=0;i<4;i++)
	  if (debug_gl_now) printf(" %f,",(double)m[i+(j*4)]);
	 if (debug_gl_now) printf("},\n");
	}
	if (debug_gl_now) printf("DEBUG_GL:\t\t};\n");
	if (debug_gl_now) printf("DEBUG_GL:\t\tglLoadMatrixf((const GLfloat *)&m);\n");
	if (debug_gl_now) printf("DEBUG_GL:\t}\n");
	}
	else
	if (debug_gl_now) printf("DEBUG_GL:\tglLoadMatrixf(NULL);\n");
	if (debug_gl_now) fflush(stdout);
	if (qglLoadMatrixf_)
		qglLoadMatrixf_(m);
	else
		puts("DEBUG_GL:\tglLoadMatrixf not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glLoadMatrixd(const GLdouble *m)
{
	int i,j;
	if (m)
	{
	if (debug_gl_now) printf("DEBUG_GL:\t{\n");
	if (debug_gl_now) printf("DEBUG_GL:\t\tGLdouble m[4][4]={\n");
	for(j=0;j<4;j++)
	{
	 if (debug_gl_now) printf("DEBUG_GL:\t\t\t{");
	 for(i=0;i<4;i++)
	  if (debug_gl_now) printf(" %f,",(double)m[i+(j*4)]);
	 if (debug_gl_now) printf("},\n");
	}
	if (debug_gl_now) printf("DEBUG_GL:\t\t};\n");
	if (debug_gl_now) printf("DEBUG_GL:\t\tglLoadMatrixd((const GLdouble *)&m);\n");
	if (debug_gl_now) printf("DEBUG_GL:\t}\n");
	}
	else
	if (debug_gl_now) printf("DEBUG_GL:\tglLoadMatrixd(NULL);\n");
	if (debug_gl_now) fflush(stdout);
	if (qglLoadMatrixd_)
		qglLoadMatrixd_(m);
	else
		puts("DEBUG_GL:\tglLoadMatrixd not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glLoadIdentity(void)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglLoadIdentity();\n");
	if (debug_gl_now) fflush(stdout);
	if (qglLoadIdentity_)
		qglLoadIdentity_();
	else
		puts("DEBUG_GL:\tglLoadIdentity not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glPopMatrix(void)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglPopMatrix();\n");
	if (debug_gl_now) fflush(stdout);
	if (qglPopMatrix_)
		qglPopMatrix_();
	else
		puts("DEBUG_GL:\tglPopMatrix not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glPushMatrix(void)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglPushMatrix();\n");
	if (debug_gl_now) fflush(stdout);
	if (qglPushMatrix_)
		qglPushMatrix_();
	else
		puts("DEBUG_GL:\tglPushMatrix not set");
	if (debug_gl_now) fflush(stdout);
}
void static debug_glViewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglViewport(%i, %i, %i, %i);\n",x,y,width,height);
	if (debug_gl_now) fflush(stdout);
	if (qglViewport_)
		qglViewport_(x,y,width,height);
	else
		puts("DEBUG_GL:\tglViewport not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglFrustum(%f,%f,%f,%f,%f,%f);\n",left,right,bottom,top,near_val,far_val);
	if (debug_gl_now) fflush(stdout);
	if (qglFrustum_)
		qglFrustum_(left,right,bottom,top,near_val,far_val);
	else
		puts("DEBUG_GL:\tglFrustum not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglOrtho(%f,%f,%f,%f,%f,%f);\n",left,right,bottom,top,near_val,far_val);
	if (debug_gl_now) fflush(stdout);
	if (qglOrtho_)
		qglOrtho_(left,right,bottom,top,near_val,far_val);
	else
		puts("DEBUG_GL:\tglOrtho not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glMatrixMode(GLenum mode)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglMatrixMode(%s);\n",constgl(mode));
	if (debug_gl_now) fflush(stdout);
	if (qglMatrixMode_)
		qglMatrixMode_(mode);
	else
		puts("DEBUG_GL:\tglMatrixMode not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glPointSize(GLfloat size)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglPointSize(%f);\n",(double)size);
	if (debug_gl_now) fflush(stdout);
	if (qglPointSize_)
		qglPointSize_(size);
	else
		puts("DEBUG_GL:\tglPointSize not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glLineWidth(GLfloat width)
{
#ifndef DEBUG_GL_NO_TODO
	if (debug_gl_now) printf("DEBUG_GL:\tglLineWidth(%f);\n",(double)width);
	if (debug_gl_now) fflush(stdout);
	if (qglLineWidth_)
		qglLineWidth_(width);
	else
		puts("DEBUG_GL:\tglLineWidth not set");
	if (debug_gl_now) fflush(stdout);
#endif
}

void static debug_glEnd(void)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglEnd();\n");
	if (debug_gl_now) fflush(stdout);
	if (qglEnd_)
		qglEnd_();
	else
		puts("DEBUG_GL:\tglEnd not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glBegin(GLenum mode)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglBegin(%s);\n",constgl(mode));
	if (debug_gl_now) fflush(stdout);
	if (qglBegin_)
		qglBegin_(mode);
	else
		puts("DEBUG_GL:\tglBegin not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glVertex3f(GLfloat x, GLfloat y, GLfloat z)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglVertex3f(%f,%f,%f);\n",(double)x,(double)y,(double)z);
	if (debug_gl_now) fflush(stdout);
	if (qglVertex3f_)
		qglVertex3f_(x,y,z);
	else
		puts("DEBUG_GL:\tglVertex3f not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glVertex2f(GLfloat x, GLfloat y)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglVertex2f(%f,%f);\n",(double)x,(double)y);
	if (debug_gl_now) fflush(stdout);
	if (qglVertex2f_)
		qglVertex2f_(x,y);
	else
		puts("DEBUG_GL:\tglVertex2f not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglTexCoord4f(%f,%f,%f,%f);\n",(double)s,(double)t,(double)r,(double)q);
	if (debug_gl_now) fflush(stdout);
	if (qglTexCoord4f_)
		qglTexCoord4f_(s,t,r,q);
	else
		puts("DEBUG_GL:\tglTexCoord4f not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glTexCoord3f(GLfloat s, GLfloat t, GLfloat r)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglTexCoord3f(%f,%f,%f);\n",(double)s,(double)t,(double)r);
	if (debug_gl_now) fflush(stdout);
	if (qglTexCoord3f_)
		qglTexCoord3f_(s,t,r);
	else
		puts("DEBUG_GL:\tglTexCoord3f not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glTexCoord2f(GLfloat s, GLfloat t)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglTexCoord3f(%f,%f);\n",(double)s,(double)t);
	if (debug_gl_now) fflush(stdout);
	if (qglTexCoord2f_)
		qglTexCoord2f_(s,t);
	else
		puts("DEBUG_GL:\tglTexCoord2f not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glTexCoord1f(GLfloat s)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglTexCoord1f(%f);\n",(double)s);
	if (debug_gl_now) fflush(stdout);
	if (qglTexCoord1f_)
		qglTexCoord1f_(s);
	else
		puts("DEBUG_GL:\tglTexCoord1f not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglColor4f(%f,%f,%f,%f);\n",(double)red,(double)green,(double)blue,(double)alpha);
	if (debug_gl_now) fflush(stdout);
	if (qglColor4f_)
		qglColor4f_(red,green,blue,alpha);
	else
		puts("DEBUG_GL:\tglColor4f not set");
	if (debug_gl_now) fflush(stdout);
}

static unsigned last_texcp_stride=0;
static unsigned last_texcp_total=0;
static void *last_texcp=NULL;

static unsigned last_texop_stride=0;
static unsigned last_texop_total=0;
static void *last_texop=NULL;

static unsigned last_texnp_stride=0;
static unsigned last_texnp_total=0;
static void *last_texnp=NULL;

static unsigned last_texvp_stride=0;
static unsigned last_texvp_total=0;
static void *last_texvp=NULL;

void static flush_elements(int max)
{
	int i;
	int sz_c=last_texcp_stride*(max+1);
	int sz_o=last_texop_stride*(max+1);
	int sz_n=last_texnp_stride*(max+1);
	int sz_v=last_texvp_stride*(max+1);
	GLubyte *ptr_c=(GLubyte *)last_texcp;
	GLubyte *ptr_o=(GLubyte *)last_texop;
	GLubyte *ptr_n=(GLubyte *)last_texnp;
	GLubyte *ptr_v=(GLubyte *)last_texvp;
//	if (debug_gl_now) printf("DEBUG_GL:\t{\n");
	if (ptr_c && sz_c)
	{
	 if (debug_gl_now) printf("DEBUG_GL:\t\tGLubyte ptr_c[%i]={",sz_c);
	 for(i=0;(i<sz_c)&&(debug_gl_now);i++)
	 {
	   if (!(i&15)) printf("\nDEBUG_GL:\t\t\t");
	   printf(" 0x%.2X,",ptr_c[i]); 
	 }
	 if (debug_gl_now) printf("\nDEBUG_GL:\t\t\t};\n");
	}
	if (ptr_o && sz_o)
	{
	 if (debug_gl_now) printf("DEBUG_GL:\t\tGLubyte ptr_o[%i]={",sz_o);
	 for(i=0;(i<sz_o)&&(debug_gl_now);i++)
	 {
	   if (!(i&15)) printf("\nDEBUG_GL:\t\t\t");
	   printf(" 0x%.2X,",ptr_o[i]); 
	 }
	 if (debug_gl_now) printf("\nDEBUG_GL:\t\t\t};\n");
	}
	if (ptr_n && sz_n)
	{
	 if (debug_gl_now) printf("DEBUG_GL:\t\tGLubyte ptr_n[%i]={",sz_n);
	 for(i=0;(i<sz_n)&&(debug_gl_now);i++)
	 {
	   if (!(i&15)) printf("\nDEBUG_GL:\t\t\t");
	   printf(" 0x%.2X,",ptr_n[i]); 
	 }
	 if (debug_gl_now) printf("\nDEBUG_GL:\t\t\t};\n");
	}
	if (ptr_v && sz_v)
	{
	 if (debug_gl_now) printf("DEBUG_GL:\t\tGLubyte ptr_v[%i]={",sz_v);
	 for(i=0;(i<sz_v)&&(debug_gl_now);i++)
	 {
	   if (!(i&15)) printf("\nDEBUG_GL:\t\t\t");
	   printf(" 0x%.2X,",ptr_v[i]); 
	 }
	 if (debug_gl_now) printf("\nDEBUG_GL:\t\t\t};\n");
	}
	if (ptr_c && sz_c)
	if (debug_gl_now) printf("DEBUG_GL:\t\tmemcpy(texcp,(void *)&ptr_c[0],%i);\n",sz_c);
	if (ptr_o && sz_o)
	if (debug_gl_now) printf("DEBUG_GL:\t\tmemcpy(texop,(void *)&ptr_o[0],%i);\n",sz_o);
	if (ptr_n && sz_n)
	if (debug_gl_now) printf("DEBUG_GL:\t\tmemcpy(texnp,(void *)&ptr_n[0],%i);\n",sz_n);
	if (ptr_v && sz_v)
	if (debug_gl_now) printf("DEBUG_GL:\t\tmemcpy(texvp,(void *)&ptr_v[0],%i);\n",sz_v);
//	if (debug_gl_now) printf("DEBUG_GL:\t}\n");
//	if (debug_gl_now) fflush(stdout);
}


void static debug_glArrayElement(GLint i)
{
	if (debug_gl_now) printf("DEBUG_GL:\t{\n");
	flush_elements(i);
	if (debug_gl_now) printf("DEBUG_GL:\t\tglArrayElement(%i);\n",i);
	if (debug_gl_now) printf("DEBUG_GL:\t}\n");
	if (debug_gl_now) fflush(stdout);
	if (qglArrayElement_)
		qglArrayElement_(i);
	else
		puts("DEBUG_GL:\tglArrayElement not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr)
{
	if (stride)
		last_texcp_stride=stride;
	else
	{
		switch(type)
		{
		 case GL_UNSIGNED_SHORT:
		 case GL_SHORT: last_texcp_stride=size*sizeof(GLushort); break;
		 case GL_UNSIGNED_BYTE:
		 case GL_BYTE: last_texcp_stride=size*sizeof(GLubyte); break;
		 case GL_FLOAT: last_texcp_stride=size*sizeof(GLfloat); break;
		 case GL_DOUBLE: last_texcp_stride=size*sizeof(GLfloat); break;
		 default: last_texcp_stride=size*sizeof(GLuint);
		}
	}
	if (ptr)
	{
	 if (debug_gl_now) printf("DEBUG_GL:\tglTexCoordPointer(%i,%s,%i,texcp);\n",size,constgl(type),stride);
	}
	else
	 if (debug_gl_now) printf("DEBUG_GL:\tglTexCoordPointer(%i,%s,%i,NULL);\n",size,constgl(type),stride);
	last_texcp=(void *)ptr;
	if (debug_gl_now) fflush(stdout);
	if (qglTexCoordPointer_)
		qglTexCoordPointer_(size,type,stride,ptr);
	else
		puts("DEBUG_GL:\tglTexCoordPointer not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr)
{
	if (stride)
		last_texop_stride=stride;
	else
	{
		switch(type)
		{
		 case GL_UNSIGNED_SHORT:
		 case GL_SHORT: last_texop_stride=size*sizeof(GLushort); break;
		 case GL_UNSIGNED_BYTE:
		 case GL_BYTE: last_texop_stride=size*sizeof(GLubyte); break;
		 case GL_FLOAT: last_texop_stride=size*sizeof(GLfloat); break;
		 case GL_DOUBLE: last_texop_stride=size*sizeof(GLfloat); break;
		 default: last_texop_stride=size*sizeof(GLuint);
		}
	}
	if (ptr)
	{
	 if (debug_gl_now) printf("DEBUG_GL:\tglColorPointer(%i,%s,%i,texop);\n",size,constgl(type),stride);
	} else
	 if (debug_gl_now) printf("DEBUG_GL:\tglColorPointer(%i,%s,%i,NULL);\n",size,constgl(type),stride);
	last_texop=(void *)ptr;
	if (debug_gl_now) fflush(stdout);
	if (qglColorPointer_)
		qglColorPointer_(size,type,stride,ptr);
	else
		puts("DEBUG_GL:\tglColorPointer not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glNormalPointer(GLenum type, GLsizei stride, const GLvoid *ptr)
{
#ifndef DEBUG_GL_NO_TODO
	if (stride)
		last_texnp_stride=stride;
	else
	{
		switch(type)
		{
		 case GL_UNSIGNED_SHORT:
		 case GL_SHORT: last_texnp_stride=3*sizeof(GLushort); break;
		 case GL_UNSIGNED_BYTE:
		 case GL_BYTE: last_texnp_stride=3*sizeof(GLubyte); break;
		 case GL_FLOAT: last_texnp_stride=3*sizeof(GLfloat); break;
		 case GL_DOUBLE: last_texnp_stride=3*sizeof(GLfloat); break;
		 default: last_texnp_stride=3*sizeof(GLuint);
		}
	}
	if (ptr)
	{
	 if (debug_gl_now) printf("DEBUG_GL:\tglNormalPointer(%s,%i,texnp);\n",constgl(type),stride);
	}
	else
	 if (debug_gl_now) printf("DEBUG_GL:\tglNormalPointer(%s,%i,NULL);\n",constgl(type),stride);
	last_texnp=(void *)ptr;
	if (debug_gl_now) fflush(stdout);
	if (qglNormalPointer_)
		qglNormalPointer_(type,stride,ptr);
	else
		puts("DEBUG_GL:\tglNormalPointer not set");
	if (debug_gl_now) fflush(stdout);
#endif
}

void static debug_glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr)
{
	if (stride)
		last_texvp_stride=stride;
	else
	{
		switch(type)
		{
		 case GL_UNSIGNED_SHORT:
		 case GL_SHORT: last_texvp_stride=size*sizeof(GLushort); break;
		 case GL_UNSIGNED_BYTE:
		 case GL_BYTE: last_texvp_stride=size*sizeof(GLubyte); break;
		 case GL_FLOAT: last_texvp_stride=size*sizeof(GLfloat); break;
		 case GL_DOUBLE: last_texvp_stride=size*sizeof(GLfloat); break;
		 default: last_texvp_stride=size*sizeof(GLuint);
		}
	}
	if (ptr)
	{
	 if (debug_gl_now) printf("DEBUG_GL:\tglVertexPointer(%i,%s,%i,texvp);\n",size,constgl(type),stride);
	}
	else
	 if (debug_gl_now) printf("DEBUG_GL:\tglVertexPointer(%i,%s,%i,NULL);\n",size,constgl(type),stride);
	last_texvp=(void *)ptr;
	if (debug_gl_now) fflush(stdout);
	if (qglVertexPointer_)
		qglVertexPointer_(size,type,stride,ptr);
	else
		puts("DEBUG_GL:\tglVertexPointer not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
#ifndef DEBUG_GL_NO_TODO
	if (debug_gl_now) printf("DEBUG_GL:\tglColorMask(%i,%i,%i,%i);\n",red,green,blue,alpha);
	if (debug_gl_now) fflush(stdout);
	if (qglColorMask_)
		qglColorMask_(red,green,blue,alpha);
	else
		puts("DEBUG_GL:\tglColorMask not set");
	if (debug_gl_now) fflush(stdout);
#endif
}

void static debug_glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices)
{
	int i,max=0;

	if (indices && count)
	{
	if (debug_gl_now) printf("DEBUG_GL:\t{\n");
	switch(type)
	{
		case GL_UNSIGNED_BYTE:
		case GL_BYTE:
			{
			const GLubyte *index_b=(const GLubyte *)indices;
			if (debug_gl_now) printf("DEBUG_GL:\t\tGLubyte indices[%i]={",count);
			for(i=0;i<count;i++)
			{
				int e=index_b[i];
				if (debug_gl_now) printf(" 0x%.2X,",e);
				if (e>max) max=e;
			}
			if (debug_gl_now) printf(" };\n");
			}
			break;
		case GL_UNSIGNED_SHORT:
		case GL_SHORT:
			{
			const GLushort *index_s=(const GLushort *)indices;
			if (debug_gl_now) printf("DEBUG_GL:\t\tGLushort indices[%i]={",count);
			for(i=0;i<count;i++)
			{
				int e=index_s[i];
				if (debug_gl_now) printf(" 0x%.4X,",e);
				if (e>max) max=e;
			}
			if (debug_gl_now) printf(" };\n");
			}
			break;
		case GL_FLOAT:
			{
			const GLfloat *index_f=(const GLfloat *)indices;
			if (debug_gl_now) printf("DEBUG_GL:\t\tGLfloat indices[%i]={",count);
			for(i=0;i<count;i++)
			{
				int e=(int)index_f[i];
		 		if (debug_gl_now) printf(" %f,",(double)index_f[i]); 
				if (e>max) max=e;
			}
			if (debug_gl_now) printf(" };\n");
			}
			break;
		case GL_DOUBLE:
			{
			const GLdouble *index_d=(const GLdouble *)indices;
			if (debug_gl_now) printf("DEBUG_GL:\t\tGLdouble indices[%i]={",count);
			for(i=0;i<count;i++)
			{
				int e=(int)index_d[i];
				if (debug_gl_now) printf(" %f,",index_d[i]); 
				if (e>max) max=e;
			}
			if (debug_gl_now) printf(" };\n");
			}
			break;
//		case GL_INT:
		default:
			{
			const GLuint *index_i=(const GLuint *)indices;
			if (debug_gl_now) printf("DEBUG_GL:\t\tGLuint indices[%i]={",count);
			for(i=0;i<count;i++)
			{
				int e=index_i[i];
				if (debug_gl_now) printf(" 0x%X,",e);
				if (e>max) max=e;
			}
			if (debug_gl_now) printf(" };\n");
			}
	}
	if (max)
		flush_elements(max);
	if (debug_gl_now) printf("DEBUG_GL:\t\tglDrawElements(%s,%i,%s,&indices);\n",constgl(mode),count,constgl(type));
	}
	else
	if (debug_gl_now) printf("DEBUG_GL:\t\tglDrawElements(%s,%i,%s,NULL);\n",constgl(mode),count,constgl(type));
	if (debug_gl_now) printf("DEBUG_GL:\t}\n");
	if (debug_gl_now) fflush(stdout);
	if (qglDrawElements_)
		qglDrawElements_(mode,count,type,indices);
	else
		puts("DEBUG_GL:\tglDrawElements not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glDepthRange(GLclampd near_val, GLclampd far_val)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglDepthRange(%f,%f);\n",near_val,far_val);
	if (debug_gl_now) fflush(stdout);
	if (qglDepthRange_)
		qglDepthRange_(near_val,far_val);
	else
		puts("DEBUG_GL:\tglDepthRange not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glDepthMask(GLboolean flag)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglDepthMask(%i);\n",flag);
	if (debug_gl_now) fflush(stdout);
	if (qglDepthMask_)
		qglDepthMask_(flag);
	else
		puts("DEBUG_GL:\tglDepthMask not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glDepthFunc(GLenum func)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglDepthFunc(%s);\n",constgl(func));
	if (debug_gl_now) fflush(stdout);
	if (qglDepthFunc_)
		qglDepthFunc_(func);
	else
		puts("DEBUG_GL:\tglDepthFunc not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glClearDepth(GLclampd depth)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglClearDepth(%f);\n",depth);
	if (debug_gl_now) fflush(stdout);
	if (qglClearDepth_)
		qglClearDepth_(depth);
	else
		puts("DEBUG_GL:\tglClearDepth not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glFlush(void)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglFlush();\n");
	if (debug_gl_now) fflush(stdout);
	if (qglFlush_)
		qglFlush_();
	else
		puts("DEBUG_GL:\tglFlush not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glFinish(void)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglFinish();\n");
	if (debug_gl_now) fflush(stdout);
	if (qglFinish_)
		qglFinish_();
	else
		puts("DEBUG_GL:\tglFinish not set");
	if (debug_gl_now) fflush(stdout);
	printnum();
}

static const GLubyte* debug_glGetString(GLenum name)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglGetString(%s);\n",constgl(name));
	if (debug_gl_now) fflush(stdout);
	if (qglGetString_)
		return qglGetString_(name);
	else
		puts("DEBUG_GL:\tglGetString not set");
	if (debug_gl_now) fflush(stdout);
}

GLenum static debug_glGetError(void)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglGetError();\n");
	if (debug_gl_now) fflush(stdout);
	if (qglGetError_)
		return qglGetError_();
	else
		puts("DEBUG_GL:\tglGetError not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glGetIntegerv(GLenum pname, GLint *params)
{
#ifdef DEBUG_GL_NO_TODO
	if (pname != GL_TEXTURE_BINDING_1D && pname != GL_TEXTURE_BINDING_2D && pname != GL_MAX_TEXTURE_SIZE && pname != GL_PROJECTION_MATRIX)
		return; 
#endif

	if (debug_gl_now) printf("DEBUG_GL:\t{\n");
	if (debug_gl_now) printf("DEBUG_GL:\t\tGLint params[16];\n");
	if (debug_gl_now) printf("DEBUG_GL:\t\tglGetIntegerv(%s,(GLint *)&params);\n",constgl(pname));
	if (debug_gl_now) printf("DEBUG_GL:\t}\n");
	if (debug_gl_now) fflush(stdout);
	if (qglGetIntegerv_)
		qglGetIntegerv_(pname,params);
	else
		puts("DEBUG_GL:\tglGetIntegerv not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glGetFloatv(GLenum pname, GLfloat *params)
{
#ifdef DEBUG_GL_NO_TODO
	if (pname != GL_TEXTURE_BINDING_1D && pname != GL_TEXTURE_BINDING_2D && pname != GL_MAX_TEXTURE_SIZE && pname != GL_PROJECTION_MATRIX)
		return; 
#endif

	if (debug_gl_now) printf("DEBUG_GL:\t{\n");
	if (debug_gl_now) printf("DEBUG_GL:\t\tGLfloat params[16];\n");
	if (debug_gl_now) printf("DEBUG_GL:\t\tglGetFloatv(%s,(GLfloat *)&params);\n",constgl(pname));
	if (debug_gl_now) printf("DEBUG_GL:\t}\n");
	if (debug_gl_now) fflush(stdout);
	if (qglGetFloatv_)
		qglGetFloatv_(pname,params);
	else
		puts("DEBUG_GL:\tglGetFloatv not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glGetDoublev(GLenum pname, GLdouble *params)
{
#ifdef DEBUG_GL_NO_TODO
	if (pname != GL_TEXTURE_BINDING_1D && pname != GL_TEXTURE_BINDING_2D && pname != GL_MAX_TEXTURE_SIZE && pname != GL_PROJECTION_MATRIX)
		return; 
#endif

	if (debug_gl_now) printf("DEBUG_GL:\t{\n");
	if (debug_gl_now) printf("DEBUG_GL:\t\tGLdouble params[16];\n");
	if (debug_gl_now) printf("DEBUG_GL:\t\tglGetDoublev(%s,(GLdouble *)&params);\n",constgl(pname));
	if (debug_gl_now) printf("DEBUG_GL:\t}\n");
	if (debug_gl_now) fflush(stdout);
	if (qglGetDoublev_)
		qglGetDoublev_(pname,params);
	else
		puts("DEBUG_GL:\tglGetDoublev not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glGetBooleanv(GLenum pname, GLboolean *params)
{
#ifdef DEBUG_GL_NO_TODO
	if (pname != GL_TEXTURE_BINDING_1D && pname != GL_TEXTURE_BINDING_2D && pname != GL_MAX_TEXTURE_SIZE && pname != GL_PROJECTION_MATRIX)
		return; 
#endif

	if (debug_gl_now) printf("DEBUG_GL:\t{\n");
	if (debug_gl_now) printf("DEBUG_GL:\t\tGLboolean params[16];\n");
	if (debug_gl_now) printf("DEBUG_GL:\t\tglGetBooleanv(%s,(GLboolean *)&params);\n",constgl(pname));
	if (debug_gl_now) printf("DEBUG_GL:\t}\n");
	if (debug_gl_now) fflush(stdout);
	if (qglGetBooleanv_)
		qglGetBooleanv_(pname,params);
	else
		puts("DEBUG_GL:\tglGetBooleanv not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glDisableClientState(GLenum cap)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglDisableClientState(%s);\n",constgl(cap));
	if (debug_gl_now) fflush(stdout);
	if (qglDisableClientState_)
		qglDisableClientState_(cap);
	else
		puts("DEBUG_GL:\tglDisableClientState not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glEnableClientState(GLenum cap)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglEnableClientState(%s);\n",constgl(cap));
	if (debug_gl_now) fflush(stdout);
	if (qglEnableClientState_)
		qglEnableClientState_(cap);
	else
		puts("DEBUG_GL:\tglEnableClientState not set");
	if (debug_gl_now) fflush(stdout);
}


GLboolean static debug_glIsEnabled(GLenum cap)
{
#ifdef DEBUG_GL_NO_TODO
	if (cap != GL_TEXTURE_1D && cap != GL_TEXTURE_2D && cap != GL_BLEND && cap != GL_CULL_FACE && cap != GL_SCISSOR_TEST && cap != GL_DEPTH_TEST)
		return GL_FALSE;
#endif
	if (debug_gl_now) printf("DEBUG_GL:\tglIsEnabled(%s);\n",constgl(cap));
	if (debug_gl_now) fflush(stdout);
	if (qglIsEnabled_)
		return qglIsEnabled_(cap);
	else
		puts("DEBUG_GL:\tglIsEnabled not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glDisable(GLenum cap)
{
#ifdef DEBUG_GL_NO_TODO
	if (cap != GL_TEXTURE_1D && cap != GL_TEXTURE_2D && cap != GL_BLEND && cap != GL_CULL_FACE && cap != GL_SCISSOR_TEST && cap !=GL_DEPTH_TEST)
		return;
#endif
	if (debug_gl_now) printf("DEBUG_GL:\tglDisable(%s);\n",constgl(cap));
	if (debug_gl_now) fflush(stdout);
	if (qglDisable_)
		qglDisable_(cap);
	else
		puts("DEBUG_GL:\tglDisable not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glEnable(GLenum cap)
{
#ifdef DEBUG_GL_NO_TODO
	if (cap != GL_TEXTURE_1D && cap != GL_TEXTURE_2D && cap != GL_BLEND && cap != GL_CULL_FACE && cap != GL_SCISSOR_TEST && cap!= GL_ALPHA_TEST && cap!= GL_DEPTH_TEST)
		return;
#endif
	if (debug_gl_now) printf("DEBUG_GL:\tglEnable(%s);\n",constgl(cap));
	if (debug_gl_now) fflush(stdout);
	if (qglEnable_)
		qglEnable_(cap);
	else
		puts("DEBUG_GL:\tglEnable not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glDrawBuffer(GLenum mode)
{
#ifndef DEBUG_GL_NO_TODO
	if (debug_gl_now) printf("DEBUG_GL:\tglDrawBuffer(%s);\n",constgl(mode));
	if (debug_gl_now) fflush(stdout);
	if (qglDrawBuffer_)
		qglDrawBuffer_(mode);
	else
		puts("DEBUG_GL:\tglDrawBuffer not set");
	if (debug_gl_now) fflush(stdout);
#endif
}

void static debug_glCullFace(GLenum mode)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglCullFace(%s);\n",constgl(mode));
	if (debug_gl_now) fflush(stdout);
	if (qglCullFace_)
		qglCullFace_(mode);
	else
		puts("DEBUG_GL:\tglCullFace not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glBlendFunc(GLenum sfactor, GLenum dfactor)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglBlendFunc(%s,%s);\n",constgl(sfactor),constgl(dfactor));
	if (debug_gl_now) fflush(stdout);
	if (qglBlendFunc_)
		qglBlendFunc_(sfactor,dfactor);
	else
		puts("DEBUG_GL:\tglBlendFunc not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glAlphaFunc(GLenum func, GLclampf ref)
{
#ifndef DEBUG_GL_NO_TODO
	if (debug_gl_now) printf("DEBUG_GL:\tglAlphaFunc(%s,%f);\n",constgl(func),(double)ref);
	if (debug_gl_now) fflush(stdout);
	if (qglAlphaFunc_)
		qglAlphaFunc_(func,ref);
	else
		puts("DEBUG_GL:\tglAlphaFunc not set");
	if (debug_gl_now) fflush(stdout);
#endif
}

void static debug_glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglClearColor(%f,%f,%f,%f);\n",(double)red,(double)green,(double)blue,(double)alpha);
	if (debug_gl_now) fflush(stdout);
	if (qglClearColor_)
		qglClearColor_(red,green,blue,alpha);
	else
		puts("DEBUG_GL:\tglClearColor not set");
	if (debug_gl_now) fflush(stdout);
}

void static debug_glClear(GLbitfield mask)
{
	if (debug_gl_now) printf("DEBUG_GL:\tglClear(0x%X);\n",mask);
	if (debug_gl_now) fflush(stdout);
	if (qglClear_)
		qglClear_(mask);
	else
		puts("DEBUG_GL:\tglClear not set");
	if (debug_gl_now) fflush(stdout);
}

void debug_SDL_GL_SwapBuffers(void)
{
	if (debug_gl_now) puts("DEBUG_GL:\tSDL_GL_SwapBuffers();");
	if (debug_gl_now) fflush(stdout);
	if (debug_gl_now) fflush(stdout);
	SDL_GL_SwapBuffers();
	printnum();
}

void debug_gl_start(void)
{
	int i;
	for(i=0;i<MAX_TEXS;i++)
		texs[i]=0;
	qglPolygonMode=(void (GLAPIENTRY *)(GLenum, GLenum))&debug_glPolygonMode;
	qglPolygonStipple=(void (GLAPIENTRY *)(const GLubyte*))&debug_glPolygonStipple;
	qglPolygonOffset=(void (GLAPIENTRY *)(GLfloat, GLfloat))&debug_glPolygonOffset;
	qglScissor=(void (GLAPIENTRY *)(GLint, GLint, GLsizei, GLsizei))&debug_glScissor;
	qglCopyTexSubImage2D=(void (GLAPIENTRY *)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei))&debug_glCopyTexSubImage2D;
	qglCopyTexSubImage1D=(void (GLAPIENTRY *)(GLenum, GLint, GLint, GLint, GLint, GLsizei))&debug_glCopyTexSubImage1D;
	qglCopyTexImage2D=(void (GLAPIENTRY *)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint))&debug_glCopyTexImage2D;
	qglCopyTexImage1D=(void (GLAPIENTRY *)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint))&debug_glCopyTexImage1D;
	qglTexImage2D=(void (GLAPIENTRY *)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid*))&debug_glTexImage2D;
	qglTexImage1D=(void (GLAPIENTRY *)(GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid*))&debug_glTexImage1D;
	qglBindTexture=(void (GLAPIENTRY *)(GLenum, GLuint))&debug_glBindTexture;
	qglDeleteTextures=(void (GLAPIENTRY *)(GLsizei, const GLuint*))&debug_glDeleteTextures;
	qglGenTextures=(void (GLAPIENTRY *)(GLsizei, GLuint*))&debug_glGenTextures;
	qglPixelStorei=(void (GLAPIENTRY *)(GLenum, GLint))&debug_glPixelStorei;
	qglTexParameteri=(void (GLAPIENTRY *)(GLenum, GLenum, GLint))&debug_glTexParameteri;
	qglTexSubImage2D=(void (GLAPIENTRY *)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*))&debug_glTexSubImage2D;
	qglTexSubImage1D=(void (GLAPIENTRY *)(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid*))&debug_glTexSubImage1D;
	qglTexEnvi=(void (GLAPIENTRY *)(GLenum, GLenum, GLint))&debug_glTexEnvi;
	qglClearStencil=(void (GLAPIENTRY *)(GLint))&debug_glClearStencil;
	qglStencilOpSeparate=(void (GLAPIENTRY *)(GLenum, GLenum, GLenum, GLenum))&debug_glStencilOpSeparate;
	qglStencilOp=(void (GLAPIENTRY *)(GLenum, GLenum, GLenum))&debug_glStencilOp;
	qglStencilMask=(void (GLAPIENTRY *)(GLuint))&debug_glStencilMask;
	qglStencilFuncSeparate=(void (GLAPIENTRY *)(GLenum, GLenum, GLint, GLuint))&debug_glStencilFuncSeparate;
	qglStencilFunc=(void (GLAPIENTRY *)(GLenum, GLint, GLuint))&debug_glStencilFunc;
	qglReadPixels=(void (GLAPIENTRY *)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid*))&debug_glReadPixels;
	qglTranslatef=(void (GLAPIENTRY *)(GLfloat, GLfloat, GLfloat))&debug_glTranslatef;
	qglScalef=(void (GLAPIENTRY *)(GLfloat, GLfloat, GLfloat))&debug_glScalef;
	qglRotatef=(void (GLAPIENTRY *)(GLfloat, GLfloat, GLfloat, GLfloat))&debug_glRotatef;
	qglMultMatrixf=(void (GLAPIENTRY *)(const GLfloat*))&debug_glMultMatrixf;
	qglLoadMatrixf=(void (GLAPIENTRY *)(const GLfloat*))&debug_glLoadMatrixf;
	qglLoadMatrixd=(void (GLAPIENTRY *)(const GLdouble*))&debug_glLoadMatrixd;
	qglLoadIdentity=(void (GLAPIENTRY *)())&debug_glLoadIdentity;
	qglPopMatrix=(void (GLAPIENTRY *)())&debug_glPopMatrix;
	qglPushMatrix=(void (GLAPIENTRY *)())&debug_glPushMatrix;
	qglViewport=(void (GLAPIENTRY *)(GLint, GLint, GLsizei, GLsizei))&debug_glViewport;
	qglFrustum=(void (GLAPIENTRY *)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble))&debug_glFrustum;
	qglOrtho=(void (GLAPIENTRY *)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble))&debug_glOrtho;
	qglMatrixMode=(void (GLAPIENTRY *)(GLenum))&debug_glMatrixMode;
	qglPointSize=(void (GLAPIENTRY *)(GLfloat))&debug_glPointSize;
	qglLineWidth=(void (GLAPIENTRY *)(GLfloat))&debug_glLineWidth;
	qglEnd=(void (GLAPIENTRY *)())&debug_glEnd;
	qglBegin=(void (GLAPIENTRY *)(GLenum))&debug_glBegin;
	qglVertex3f=(void (GLAPIENTRY *)(GLfloat, GLfloat, GLfloat))&debug_glVertex3f;
	qglVertex2f=(void (GLAPIENTRY *)(GLfloat, GLfloat))&debug_glVertex2f;
	qglTexCoord4f=(void (GLAPIENTRY *)(GLfloat, GLfloat, GLfloat, GLfloat))&debug_glTexCoord4f;
	qglTexCoord3f=(void (GLAPIENTRY *)(GLfloat, GLfloat, GLfloat))&debug_glTexCoord3f;
	qglTexCoord2f=(void (GLAPIENTRY *)(GLfloat, GLfloat))&debug_glTexCoord2f;
	qglTexCoord1f=(void (GLAPIENTRY *)(GLfloat))&debug_glTexCoord1f;
	qglColor4f=(void (GLAPIENTRY *)(GLfloat, GLfloat, GLfloat, GLfloat))&debug_glColor4f;
	qglArrayElement=(void (GLAPIENTRY *)(GLint))&debug_glArrayElement;
	qglTexCoordPointer=(void (GLAPIENTRY *)(GLint, GLenum, GLsizei, const GLvoid*))&debug_glTexCoordPointer;
	qglColorPointer=(void (GLAPIENTRY *)(GLint, GLenum, GLsizei, const GLvoid*))&debug_glColorPointer;
	qglNormalPointer=(void (GLAPIENTRY *)(GLenum, GLsizei, const GLvoid*))&debug_glNormalPointer;
	qglVertexPointer=(void (GLAPIENTRY *)(GLint, GLenum, GLsizei, const GLvoid*))&debug_glVertexPointer;
	qglColorMask=(void (GLAPIENTRY *)(GLboolean, GLboolean, GLboolean, GLboolean))&debug_glColorMask;
	qglDrawElements=(void (GLAPIENTRY *)(GLenum, GLsizei, GLenum, const GLvoid*))&debug_glDrawElements;
	qglDepthRange=(void (GLAPIENTRY *)(GLclampd, GLclampd))&debug_glDepthRange;
	qglDepthMask=(void (GLAPIENTRY *)(GLboolean))&debug_glDepthMask;
	qglDepthFunc=(void (GLAPIENTRY *)(GLenum))&debug_glDepthFunc;
	qglClearDepth=(void (GLAPIENTRY *)(GLclampd))&debug_glClearDepth;
	qglFlush=(void (GLAPIENTRY *)())&debug_glFlush;
	qglFinish=(void (GLAPIENTRY *)())&debug_glFinish;
	qglGetString=(const GLubyte*(GLAPIENTRY *)(GLenum))&debug_glGetString;
	qglGetError=(GLenum (GLAPIENTRY *)())&debug_glGetError;
	qglGetIntegerv=(void (GLAPIENTRY *)(GLenum, GLint*))&debug_glGetIntegerv;
	qglGetFloatv=(void (GLAPIENTRY *)(GLenum, GLfloat*))&debug_glGetFloatv;
	qglGetDoublev=(void (GLAPIENTRY *)(GLenum, GLdouble*))&debug_glGetDoublev;
	qglGetBooleanv=(void (GLAPIENTRY *)(GLenum, GLboolean*))&debug_glGetBooleanv;
	qglDisableClientState=(void (GLAPIENTRY *)(GLenum))&debug_glDisableClientState;
	qglEnableClientState=(void (GLAPIENTRY *)(GLenum))&debug_glEnableClientState;
	qglIsEnabled=(GLboolean (GLAPIENTRY *)(GLenum))&debug_glIsEnabled;
	qglDisable=(void (GLAPIENTRY *)(GLenum))&debug_glDisable;
	qglEnable=(void (GLAPIENTRY *)(GLenum))&debug_glEnable;
	qglDrawBuffer=(void (GLAPIENTRY *)(GLenum))&debug_glDrawBuffer;
	qglCullFace=(void (GLAPIENTRY *)(GLenum))&debug_glCullFace;
	qglBlendFunc=(void (GLAPIENTRY *)(GLenum, GLenum))&debug_glBlendFunc;
	qglAlphaFunc=(void (GLAPIENTRY *)(GLenum, GLclampf))&debug_glAlphaFunc;
	qglClearColor=(void (GLAPIENTRY *)(GLclampf, GLclampf, GLclampf, GLclampf))&debug_glClearColor;
	qglClear=(void (GLAPIENTRY *)(GLbitfield))&debug_glClear;
	printnum();
}

#endif

