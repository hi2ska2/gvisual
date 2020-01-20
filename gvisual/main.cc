// main.cc
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

#include <iostream>

int main(int argc, char* argv[])
{
  std::cout << "****************************************************************************\n";
  std::cout << "***                              G-Visual                                ***\n";
  std::cout << "***                          Version E-2020.02                           ***\n";
  std::cout << "***                       Compiled on 2020. 01. 20.                      ***\n";
  std::cout << "***                                                                      ***\n";
  std::cout << "***                             Written by                               ***\n";
  std::cout << "***                            Sung-Min Hong                             ***\n";
  std::cout << "****************************************************************************\n";
  
  QApplication app(argc, argv);

  //GVisual gvisual;
  //gvisual.show();

  Qt3DExtras::Qt3DWindow* view = new Qt3DExtras::Qt3DWindow();
  view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x4d4d4f)));
  QWidget* container = QWidget::createWindowContainer(view);
  QSize screenSize = view->screen()->size();
  container->setMinimumSize(QSize(200,100));
  container->setMaximumSize(screenSize);

  QWidget* widget = new QWidget;
  QHBoxLayout* hLayout = new QHBoxLayout(widget);
  QVBoxLayout* vLayout = new QVBoxLayout();
  vLayout->setAlignment(Qt::AlignTop);
  hLayout->addWidget(container, 1);
  hLayout->addLayout(vLayout);

  widget->setWindowTitle(QStringLiteral("G-Visual"));

  Qt3DInput::QInputAspect* input = new Qt3DInput::QInputAspect;
  view->registerAspect(input);

  Qt3DCore::QEntity* rootEntity = new Qt3DCore::QEntity();

  Qt3DRender::QCamera* cameraEntity = view->camera();

  cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
  cameraEntity->setPosition(QVector3D(0,0,20.0f));
  cameraEntity->setUpVector(QVector3D(0, 1, 0));
  cameraEntity->setViewCenter(QVector3D(0, 0, 0));

  Qt3DCore::QEntity* lightEntity = new Qt3DCore::QEntity(rootEntity);
  Qt3DRender::QPointLight* light = new Qt3DRender::QPointLight(lightEntity);
  light->setColor("white");
  light->setIntensity(1);
  lightEntity->addComponent(light);
  Qt3DCore::QTransform* lightTransform = new Qt3DCore::QTransform(lightEntity);
  lightTransform->setTranslation(cameraEntity->position());
  lightEntity->addComponent(lightTransform);

  Qt3DExtras::QFirstPersonCameraController* camController = new Qt3DExtras::QFirstPersonCameraController(rootEntity);
  camController->setCamera(cameraEntity);
  
  //SceneModifier* modifier = new SceneModifier(rootEntity);

  view->setRootEntity(rootEntity);

  //widget->show();
  //widget->resize(1200, 800);
  
  return app.exec();
}
