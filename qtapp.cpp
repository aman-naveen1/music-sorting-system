#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QFrame>

class SoundRecognitionApp : public QWidget {
public:
    SoundRecognitionApp(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("Sound Recognition System");
        setStyleSheet("background-color: #121212; color: white;");
        resize(600, 400);
        
        QVBoxLayout *layout = new QVBoxLayout(this);
        QLabel *title = new QLabel("\U0001F3B5 Sound Recognition System", this);
        title->setAlignment(Qt::AlignCenter);
        title->setStyleSheet("font-size: 24px; font-weight: bold;");
        
        QPushButton *recordButton = new QPushButton("🎙 Record Sound", this);
        QPushButton *uploadButton = new QPushButton("📂 Upload File", this);
        QPushButton *analyzeButton = new QPushButton("📊 Analyze Sound", this);
        
        recordButton->setStyleSheet("background-color: #1DB954; color: white; padding: 12px; border-radius: 5px;");
        uploadButton->setStyleSheet("background-color: #535353; color: white; padding: 12px; border-radius: 5px;");
        analyzeButton->setStyleSheet("background-color: #FF5733; color: white; padding: 12px; border-radius: 5px;");
        
        QFrame *visualizerFrame = new QFrame(this);
        visualizerFrame->setStyleSheet("background-color: black; border: 1px solid white;");
        visualizerFrame->setFixedSize(500, 150);
        
        layout->addWidget(title);
        layout->addWidget(visualizerFrame, 0, Qt::AlignCenter);
        layout->addWidget(recordButton);
        layout->addWidget(uploadButton);
        layout->addWidget(analyzeButton);
        
        setLayout(layout);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    SoundRecognitionApp window;
    window.show();
    return app.exec();
}
