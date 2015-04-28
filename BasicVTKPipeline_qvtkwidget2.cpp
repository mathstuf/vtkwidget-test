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

    coneSource->SetResolution(1000);

    vtkSmartPointer<vtkPolyDataMapper> coneMapper =
        vtkSmartPointer<vtkPolyDataMapper>::New();
    coneMapper->SetInputConnection(coneSource->GetOutputPort());

    vtkSmartPointer<vtkActor> coneActor =
        vtkSmartPointer<vtkActor>::New();
    coneActor->SetMapper(coneMapper);

    // Setup window
    vtkSmartPointer<vtkRenderWindow> renderWindow =
        vtkSmartPointer<vtkRenderWindow>::New();

    // Setup renderer
    vtkSmartPointer<vtkRenderer> renderer =
        vtkSmartPointer<vtkRenderer>::New();
    renderWindow->AddRenderer(renderer);

    renderer->AddActor(coneActor);
    renderer->ResetCamera();

    widget.GetRenderWindow()->AddRenderer(renderer);
    widget.show();

    return a.exec();
}
