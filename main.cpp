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
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

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
        
        recordButton = new QPushButton("\U0001F3A4 Record Sound", this);
        uploadButton = new QPushButton("\U0001F4C2 Upload File", this);
        analyzeButton = new QPushButton("\U0001F4CA Analyze Sound", this);
        
        visualizerFrame = new QFrame(this);
        visualizerFrame->setStyleSheet("background-color: black; border: 1px solid white;");
        visualizerFrame->setFixedSize(500, 150);
        
        layout->addWidget(title);
        layout->addWidget(visualizerFrame, 0, Qt::AlignCenter);
        layout->addWidget(recordButton);
        layout->addWidget(uploadButton);
        layout->addWidget(analyzeButton);
        
        audioRecorder = new QAudioRecorder(this);
        networkManager = new QNetworkAccessManager(this);
        
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
        // Example API request to fetch song details using Shazam API
        QNetworkRequest request(QUrl("https://shazam-api-endpoint.com/detect"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        
        QJsonObject json;
        json["audioFile"] = "recorded_audio.wav";
        QNetworkReply *reply = networkManager->post(request, QJsonDocument(json).toJson());
        connect(reply, &QNetworkReply::finished, this, &SoundRecognitionApp::handleShazamResponse);
    }
    void handleShazamResponse() {
        QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
        if (reply->error() == QNetworkReply::NoError) {
            QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
            QJsonObject obj = doc.object();
            QString songName = obj["track"]["title"].toString();
            QString artist = obj["track"]["subtitle"].toString();
            QString spotifyLink = obj["track"]["spotify"].toString();
            
            QMessageBox::information(this, "Song Found", "Song: " + songName + "\nArtist: " + artist + "\nSpotify: " + spotifyLink);
        } else {
            QMessageBox::warning(this, "Error", "Failed to fetch song details.");
        }
        reply->deleteLater();
    }

private:
    QVBoxLayout *layout;
    QPushButton *recordButton, *uploadButton, *analyzeButton;
    QFrame *visualizerFrame;
    QAudioRecorder *audioRecorder;
    QNetworkAccessManager *networkManager;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    SoundRecognitionApp window;
    window.show();
    return app.exec();
}
