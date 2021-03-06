#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSettings>
#include <QQuickStyle>
#include <QIcon>

#include <QDebug>

// #include "backendmodel.h"
// #include "pluginloader.h"
// #include "pluginmgr.h"
// #include "israfilcore.h"
#include "israfilcoreqt.h"
#include "israfilplayer.h"


int main(int argc, char *argv[])
{
  QGuiApplication::setApplicationName("Israfil");
  QGuiApplication::setOrganizationName("Void.LER0ever");
  QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);
  app.setWindowIcon(QIcon("qrc:/images/israfil.ico"));

  // qmlRegisterType<BackendModel>("israfil", 1, 0, "BackendModel");
  QSettings settings;
  QString style = QQuickStyle::name();
  if (!style.isEmpty())
      settings.setValue("style", style);
  else
      QQuickStyle::setStyle(settings.value("style").toString());

  QQmlApplicationEngine engine;

  qmlRegisterType<IsrafilCoreQt>("IsrafilCore", 1, 0, "IsrafilCoreQt");

  /*
     engine.addImportPath("qrc:///");
     engine.addImportPath("qrc:/Material");
     engine.addImportPath("qrc:/QtQuick");
     engine.addImportPath("qrc:/QtQuick/Controls/Styles/Material");

     MaterialPlugin qmlMaterial;
     qmlMaterial.registerTypes("Material");
   */

  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  IsrafilCoreQt isrc;
  engine.rootContext()->setContextProperty("isrc", &isrc);
  IsrafilPlayer isrp;
  engine.rootContext()->setContextProperty("isrp", &isrp);

  /*
   * player.setFileUrl("http://stream.qqmusic.tc.qq.com/105624143.mp3");
   * player.mediaPlay();
   */
  // QStringList plugins;
  // IsrafilCore *pIC = new IsrafilCore();

  return app.exec();
}
