#pragma once

#include "shaderprogram.h"
#include "bubble_solver.h"


class BubbleDraw
{
private:
    class d_box : public ShaderProgram::Drawable {
    private:
        BubbleSolver *solver;
        int count;
        QOpenGLBuffer bufIdx;
        QOpenGLBuffer bufPos;

    public:
        explicit d_box(BubbleSolver *s);
        void create();
        void destroy();
        void update();

    public:
        GLenum drawMode() { return GL_LINES; }
        int elemCount() { return count; }
        bool bindIdx() { return bufIdx.bind(); }
        bool bindPos() { return bufPos.bind(); }
        bool bindNor() { return false; }
        bool bindCol() { return false; }
    };

    class d_bubbles : public ShaderProgram::Drawable {
    private:
        BubbleSolver *solver;
        int count;
        QOpenGLBuffer bufIdx;
        QOpenGLBuffer bufPos;

    public:
        explicit d_bubbles(BubbleSolver *s);
        void create();
        void destroy();
        void update();

    public:
        GLenum drawMode() { return GL_POINTS; }
        int elemCount() { return count; }
        bool bindIdx() { return bufIdx.bind(); }
        bool bindPos() { return bufPos.bind(); }
        bool bindNor() { return false; }
        bool bindCol() { return false; }
    };

private:
    BubbleSolver solver;
    d_box box;
    d_bubbles bub;

public:
    BubbleDraw();

    void create();
    void destroy();

    void draw(ShaderProgram &p);
};
