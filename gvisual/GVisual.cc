// GVisual.cc
// Created     : 2020. 01. 20.
// Last updated: 2020. 01. 20.

#include "GVisual.h"

#include <QtWidgets>

#include <Qt3DCore>
#include <Qt3DRender>
#include <Qt3DInput>
#include <Qt3DLogic>
#include <Qt3DExtras>
#include <Qt3DAnimation>

GVisual::GVisual()
{
  QWidget* widget = new QWidget;
  setCentralWidget(widget);
  
  Qt3DExtras::Qt3DWindow* view = new Qt3DExtras::Qt3DWindow();
  view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x4d4d4f)));
  QWidget* container = QWidget::createWindowContainer(view);

  //view->show();

  QGridLayout* layout = new QGridLayout;
  layout->addWidget(container,0,0);
  widget->setLayout(layout);
  
  setWindowTitle(tr("G-Visual"));
  setMinimumSize(160,160);
  resize(640,480);

  Qt3DCore::QEntity* rootEntity = new Qt3DCore::QEntity();
  Qt3DRender::QCamera* cameraEntity = view->camera();

  view->setRootEntity(rootEntity);
}
