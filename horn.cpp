//#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtMultimedia/QSoundEffect>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPushButton button("HONK!");
    button.setGeometry(50,500,200,100);
    QSoundEffect horn;
    horn.setSource(QUrl::fromLocalFile("horn.wav"));
    QObject::connect(&button, &QPushButton::clicked, [&](){
        horn.play();
    });
    button.show();
    return a.exec();
}