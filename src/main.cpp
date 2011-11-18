#include "../include/common.hpp"

// Entry point of the application
int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  // FIXME: this is just a demo GUI
  QGraphicsView widget;

  widget.show();
  return app.exec();
}
