// main.cc
// Created     : 2020. 01. 20.
// Last updated: 2020. 01. 22.

#include "GVisual.h"

#include <QtWidgets>

#include <Qt3DCore>
#include <Qt3DRender>
#include <Qt3DInput>
#include <Qt3DLogic>

#include <iostream>

int main(int argc, char* argv[])
{
  std::cout << "****************************************************************************\n";
  std::cout << "***                              G-Visual                                ***\n";
  std::cout << "***                          Version E-2020.02                           ***\n";
  std::cout << "***                       Compiled on 2020. 01. 22.                      ***\n";
  std::cout << "***                                                                      ***\n";
  std::cout << "***                             Written by                               ***\n";
  std::cout << "***                            Sung-Min Hong                             ***\n";
  std::cout << "****************************************************************************\n";
  
  QApplication app(argc, argv);

  Qt3DRender::QWindow view;
  Qt3DInput::QInputAspect* input = new Qt3DInput::QInputAspect;
  view.registerAspect(input);

  // Root entity
  Qt3DCore::QEntity* rootEntity = new Qt3DCore::QEntity();

  // Camera
  Qt3DCore::QCamera* cameraEntity = view.defaultCamera();

  cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
  cameraEntity->setPosition(QVector3D(10.0f, 10.0f, 0.0f));
  cameraEntity->setUpVector(QVector3D(0, 0, 1));
  cameraEntity->setViewCenter(QVector3D(0, 0, 0));
  input->setCamera(cameraEntity);

  // Material
  Qt3DRender::QMaterial* material = new Qt3DRender::QPhongMaterial(rootEntity);

  // Sphere  
  Qt3DRender::QSphereMesh* sphereMesh = new Qt3DRender::QSphereMesh;
  sphereMesh->setRadius(1.1); // 0.11 nm

  Qt3DCore::QEntity* sphereEntity = new Qt3DCore::QEntity(rootEntity);
  sphereEntity->addComponent(sphereMesh);
  Qt3DCore::QTransform* sphereTransform = new Qt3DCore::QTransform;
  sphereTransform->setTranslation(QVector3D(0.0f, 0.0f, 0.0f));
  sphereEntity->addComponent(sphereTransform);
  sphereEntity->addComponent(material);
  
  Qt3DCore::QEntity* sphereEntity1 = new Qt3DCore::QEntity(rootEntity);
  sphereEntity1->addComponent(sphereMesh);
  Qt3DCore::QTransform* sphereTransform1 = new Qt3DCore::QTransform;
  sphereTransform1->setTranslation(QVector3D(1.3575f, 1.3575f, 1.3575f));
  sphereEntity1->addComponent(sphereTransform1);
  sphereEntity1->addComponent(material);

  view.setRootEntity(rootEntity);
  view.show();

  return app.exec();
}
