#include "../include/common.hpp"
#include "../include/clouddef.hpp"
#include "../include/cloudgen.hpp"

// Entry point of the application
int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  // FIXME: this is just a demo GUI
  CloudDef* cloudDef = CloudDef::create("priv/test1.ini");
  CloudGen cloudGen;
  QGraphicsView widget;
  widget.setScene(cloudGen.renderScene(*cloudDef, &widget));
  delete cloudDef;

  widget.show();
  return app.exec();
}
