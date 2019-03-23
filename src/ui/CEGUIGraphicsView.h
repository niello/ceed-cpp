#ifndef CEGUIGRAPHICSVIEW_H
#define CEGUIGRAPHICSVIEW_H

#include "src/ui/ResizableGraphicsView.h"

// This is a final class, not suitable for subclassing. This views given scene using
// QOpenGLWidget. It's designed to work with CEGUIGraphicsScene derived classes.

class CEGUIGraphicsView final : public ResizableGraphicsView
{
    Q_OBJECT

public:

    explicit CEGUIGraphicsView(QWidget *parent = nullptr);
    ~CEGUIGraphicsView();

    void injectInput(bool inject);
    void updateSelfAndScene();

    virtual void drawBackground(QPainter* painter, const QRectF& rect) override;

private:

    bool _injectInput = false;

    // if true, we render always (possibly capped to some FPS) - suitable for live preview
    // if false, we render only when update() is called - suitable for visual editing
    bool continuousRendering = true;
    size_t continuousRenderingTargetFPS = 60;
};

#endif // CEGUIGRAPHICSVIEW_H
