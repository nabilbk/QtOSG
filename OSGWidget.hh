#include <QtOpenGL>

#include <osg/ref_ptr>

#include <osgViewer/CompositeViewer>
#include <osgViewer/GraphicsWindow>

class OSGWidget : public QGLWidget
{
  Q_OBJECT

public:
  OSGWidget( QWidget* parent = 0,
             const QGLWidget* shareWidget = 0,
             Qt::WindowFlags f = 0 );

  virtual ~OSGWidget();

protected:

  virtual void paintGL();
  virtual void resizeGL( int width, int height );

  virtual void keyPressEvent( QKeyEvent* event );
  virtual void keyReleaseEvent( QKeyEvent* event );

  virtual void mouseMoveEvent( QMouseEvent* event );
  virtual void mousePressEvent( QMouseEvent* event );
  virtual void mouseReleaseEvent( QMouseEvent* event );

  virtual bool event( QEvent* event );

private:

  osgGA::EventQueue* getEventQueue() const;

  osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> graphicsWindow_;
  osg::ref_ptr<osgViewer::CompositeViewer> viewer_;
};
