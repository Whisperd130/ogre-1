/*
  -----------------------------------------------------------------------------
  This source file is part of OGRE
  (Object-oriented Graphics Rendering Engine)
  For the latest info, see http://www.ogre3d.org/

  Copyright (c) 2000-2014 Torus Knot Software Ltd

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
  -----------------------------------------------------------------------------
*/
#ifndef __GLSLShader_H__
#define __GLSLShader_H__

#include "OgreGL3PlusPrerequisites.h"
#include "OgreGLSLShaderCommon.h"
#include "OgreRenderOperation.h"

namespace Ogre {

    class GLUniformCache;
    class _OgreGL3PlusExport GLSLShader : public GLSLShaderCommon
    {
    public:
        GLSLShader(ResourceManager* creator,
                   const String& name, ResourceHandle handle,
                   const String& group, bool isManual, ManualResourceLoader* loader);
		~GLSLShader();
		
        GLuint getGLShaderHandle() const { return mGLShaderHandle; }
        GLuint getGLProgramHandle();
        void attachToProgramObject(const GLuint programObject);
        void detachFromProgramObject(const GLuint programObject);

        /// Overridden from GpuProgram
        const String& getLanguage(void) const;

        /// Compile source into shader object
        bool compile( bool checkErrors = false);

    protected:
        /// Internal unload implementation, must be implemented by subclasses
        void unloadHighLevelImpl(void);
        /// Populate the passed parameters with name->index map, must be overridden
        void buildConstantDefinitions() const;
        /// Add boiler plate code and preprocessor extras, then
        /// submit shader source to OpenGL.
        void submitSource();

        // /// @copydoc Resource::loadImpl
        // void loadImpl(void) {}

    protected:
        /// GL handle for shader object.
        GLuint mGLShaderHandle;
        /// GL handle for program object the shader is bound to.
        GLuint mGLProgramHandle;
    };
}

#endif // __GLSLShader_H__
