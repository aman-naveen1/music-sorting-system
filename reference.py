"""from PyQt6.QtWidgets import QApplication, QWidget, QVBoxLayout, QPushButton, QLabel
import sys

class SoundRecognitionApp(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Sound Recognition System")
        self.setFixedSize(600, 400)
        
        layout = QVBoxLayout()
        
        title = QLabel("Sound Recognition System")
        layout.addWidget(title)
        
        record_button = QPushButton("Record Sound")
        upload_button = QPushButton("Upload File")
        analyze_button = QPushButton("Analyze Sound")
        
        layout.addWidget(record_button)
        layout.addWidget(upload_button)
        layout.addWidget(analyze_button)
        
        self.setLayout(layout)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = SoundRecognitionApp()
    window.show()
    sys.exit(app.exec())"""
