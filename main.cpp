#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QFrame>
#include <QMessageBox>
#include <QAudioRecorder>
#include <QMediaCaptureSession>
#include <QAudioInput>
#include <QFileDialog>

class SoundRecognitionApp : public QWidget {
    Q_OBJECT
public:
    SoundRecognitionApp(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("Sound Recognition System");
        setStyleSheet("background-color: #121212; color: white;");
        resize(600, 400);
        
        layout = new QVBoxLayout(this);
        QLabel *title = new QLabel("\U0001F3B5 Sound Recognition System", this);
        title->setAlignment(Qt::AlignCenter);
        title->setStyleSheet("font-size: 24px; font-weight: bold;");
        
        recordButton = new QPushButton("🎙 Record Sound", this);
        uploadButton = new QPushButton("📂 Upload File", this);
        analyzeButton = new QPushButton("📊 Analyze Sound", this);
        
        recordButton->setStyleSheet("background-color: #1DB954; color: white; padding: 12px; border-radius: 5px;");
        uploadButton->setStyleSheet("background-color: #535353; color: white; padding: 12px; border-radius: 5px;");
        analyzeButton->setStyleSheet("background-color: #FF5733; color: white; padding: 12px; border-radius: 5px;");
        
        visualizerFrame = new QFrame(this);
        visualizerFrame->setStyleSheet("background-color: black; border: 1px solid white;");
        visualizerFrame->setFixedSize(500, 150);
        
        layout->addWidget(title);
        layout->addWidget(visualizerFrame, 0, Qt::AlignCenter);
        layout->addWidget(recordButton);
        layout->addWidget(uploadButton);
        layout->addWidget(analyzeButton);
        
        audioRecorder = new QAudioRecorder(this);
        
        connect(recordButton, &QPushButton::clicked, this, &SoundRecognitionApp::recordSound);
        connect(uploadButton, &QPushButton::clicked, this, &SoundRecognitionApp::uploadFile);
        connect(analyzeButton, &QPushButton::clicked, this, &SoundRecognitionApp::analyzeSound);
        
        setLayout(layout);
    }

private slots:
    void recordSound() {
        if (audioRecorder->state() == QMediaRecorder::RecordingState) {
            audioRecorder->stop();
            QMessageBox::information(this, "Recording", "Recording stopped.");
        } else {
            audioRecorder->setOutputLocation(QUrl::fromLocalFile("recorded_audio.wav"));
            audioRecorder->record();
            QMessageBox::information(this, "Recording", "Recording started...");
        }
    }
    void uploadFile() {
        QString fileName = QFileDialog::getOpenFileName(this, "Select Audio File", "", "Audio Files (*.wav *.mp3 *.aac)");
        if (!fileName.isEmpty()) {
            QMessageBox::information(this, "Upload", "File selected: " + fileName);
        }
    }
    void analyzeSound() {
        QMessageBox::information(this, "Analysis", "Analyzing sound...");
    }

private:
    QVBoxLayout *layout;
    QPushButton *recordButton, *uploadButton, *analyzeButton;
    QFrame *visualizerFrame;
    QAudioRecorder *audioRecorder;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    SoundRecognitionApp window;
    window.show();
    return app.exec();
}
