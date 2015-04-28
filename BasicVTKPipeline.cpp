#include <QApplication>

#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL);
VTK_MODULE_INIT(vtkInteractionStyle);

#include <vtkSmartPointer.h>
#include <vtkConeSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkImageViewer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleImage.h>
#include <vtkRenderer.h>
#include <vtkJPEGReader.h>
// #include <QVTKWidget.h>
#include <QVTKWidget2.h>
#include <vtkGenericOpenGLRenderWindow.h>

#include <vtkProperty.h>
#include <vtkLight.h>
#include <vtkLightKit.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // QVTKWidget widget;
    QVTKWidget2 widget;
    widget.resize(1024,1024);

    // Setup sphere
    vtkSmartPointer<vtkConeSource> coneSource =
        vtkSmartPointer<vtkConeSource>::New();
    coneSource->Update();

    coneSource->SetResolution(500);

    vtkSmartPointer<vtkPolyDataMapper> coneMapper =
        vtkSmartPointer<vtkPolyDataMapper>::New();
    coneMapper->SetInputConnection(coneSource->GetOutputPort());

    vtkSmartPointer<vtkActor> coneActor =
        vtkSmartPointer<vtkActor>::New();
    coneActor->SetMapper(coneMapper);

    // Setup light
    // vtkSmartPointer<vtkLight> light = vtkSmartPointer<vtkLight>::New();
    // light->SetLightTypeToSceneLight();
    // //light->SetPosition(lightPosition[0], lightPosition[1], lightPosition[2]);
    // //light->SetPositional(true); // required for vtkLightActor below
    // light->SetConeAngle(10);
    // //light->SetFocalPoint(lightFocalPoint[0], lightFocalPoint[1], lightFocalPoint[2]);
    // light->SetDiffuseColor(1,0,0);
    // light->SetAmbientColor(0,1,0);
    // light->SetSpecularColor(0,0,1);


    // Setup window
    vtkSmartPointer<vtkRenderWindow> renderWindow =
        vtkSmartPointer<vtkRenderWindow>::New();

    // Setup renderer
    vtkSmartPointer<vtkRenderer> renderer =
        vtkSmartPointer<vtkRenderer>::New();
    renderWindow->AddRenderer(renderer);

    renderer->AddActor(coneActor);
    renderer->ResetCamera();

    //renderer->AddLight(light);
    vtkSmartPointer<vtkLightKit> light_kit = vtkSmartPointer<vtkLightKit>::New();
    light_kit->AddLightsToRenderer(renderer);

    widget.GetRenderWindow()->AddRenderer(renderer);

    widget.GetRenderWindow()->SetPointSmoothing(1);
    widget.GetRenderWindow()->SetLineSmoothing(1);
    widget.GetRenderWindow()->SetPolygonSmoothing(1);
    renderer->SetGradientBackground(true);
    renderer->SetBackground(0.90, 0.90, 0.90);


    //coneActor->GetProperty()->SetOpacity(0.9);
    coneActor->VisibilityOn();
    //coneActor->SetVisibility(1);
    widget.show();

    return a.exec();
}
