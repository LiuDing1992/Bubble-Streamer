#include <iostream>

#include <mainwindow.h>

#include <QApplication>
#include <QSurfaceFormat>
#include <QDebug>

#include <Eigen/Dense>

#include "bubble.h"
#include "fluid_sim.h"

void debugFormatVersion()
{
    QSurfaceFormat form = QSurfaceFormat::defaultFormat();
    QSurfaceFormat::OpenGLContextProfile prof = form.profile();

    const char *profile =
        prof == QSurfaceFormat::CoreProfile ? "Core" :
        prof == QSurfaceFormat::CompatibilityProfile ? "Compatibility" :
        "None";

    printf("Requested format:\n");
    printf("  Version: %d.%d\n", form.majorVersion(), form.minorVersion());
    printf("  Profile: %s\n", profile);
}

int main(int argc, char *argv[])
{
    FluidSim fs(10);

    fs.advance(0.2);

    // std::cout << fs.pressure_ << std::endl;
    for(int j = 0; j < fs.nj_; ++j)
    {
      //std::cout << fs.pressure_[j*fs.nk_] << std::endl;
      std::cout << fs.get_v(0, j, 0) << std::endl;
    }
    QApplication a(argc, argv);

    // Set OpenGL 3.2 and, optionally, 4-sample multisampling
    QSurfaceFormat format;
    format.setVersion(3, 2);
    format.setOption(QSurfaceFormat::DeprecatedFunctions, false);
    format.setProfile(QSurfaceFormat::CoreProfile);
    //format.setSamples(4);  // Uncomment for nice antialiasing. Not always supported.

    /*** AUTOMATIC TESTING: DO NOT MODIFY ***/
    /*** Check whether automatic testing is enabled */
    /***/ if (qgetenv("CIS277_AUTOTESTING") != nullptr) format.setSamples(0);

    QSurfaceFormat::setDefaultFormat(format);
    debugFormatVersion();

    //Eigen::Matrix<float, 2, 3> m1;


    MainWindow w;
    w.show();

    //important test comment

    return a.exec();
}
