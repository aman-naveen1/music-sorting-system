# Sound Recognition System

## Overview

The **Sound Recognition System** is a C++ application built using **Qt**. It provides a simple **minimalist dark mode UI** with options to **record sound, upload a file, and analyze the audio**. The application will also feature a **real-time audio spectrum visualizer**. **THIS IS SUPPOSED TO BE A PERSONAL PROJECT USING SHAZAM AND MUSIXMATCH API'S TO MAKE IT EASIER TO ACCESS LYRICS TO SONGS, I AM CURRENTLY WORKING ON A PYTHON BRIDGE FOR FASTER IMPLEMENTATION OF THE API AND CREATE A PLUGIN TO INPUT A VALID IDENTIFIER. THIS PROJECT USES AN INTENSITY DETECTION SYSTEM(DECIBELS) AND ALSO DETECTS THE TEMPO OF THE SONGS INPUTTED TO CLASSIFY THE SONGS INTO GENRES. ALTHOUGH A WORK IN PROGRESS FOR A COLLEGE PROJECT, HOPEFULLY IT COMES IN HANDY TO MUSIC PRODUCERS, OR JUST THE GENERAL PUBLIC AS A GOOD ALTERNATIVE.THE UI FOR THE APPLICATION WILL BE SUCH THAT YOU CAN RECORD AN AUDIO, OR EVEN UPLOAD AN AUDIO FILE TO DISCERN AND DETECT THE ORIGINAL AUDIO(SOMEWHAT LIKE GOOGLE PIXEL'S NOW PLAYING FEATURE)**

To integrate Shazam API and Musixmatch API, we need:

1.Extract audio fingerprints from the recorded/uploaded audio.

2.Send requests to Shazam API to identify the song.

3.Use the identified song's metadata to fetch lyrics from Musixmatch.

4.Display the song name, cover art, and lyrics in the UI.
(COMING SOON)

## Features

- 🎙 **Record Sound**: Capture audio from the microphone.
- 📂 **Upload File**: Select and analyze an audio file.
- 📊 **Analyze Sound**: Process the audio and classify its intensity & tempo.
- 🎵 **Real-Time Spectrum Visualizer** (Upcoming).
- 🌙 **Minimalist Dark Mode UI**.

## Installation

### Prerequisites

- **Qt 6.x** (or latest Qt version)
- **Qt Creator IDE** (Recommended)
- C++ Compiler (GCC, MSVC, or Clang)

### Steps to Run

1. **Download & Install Qt** from [https://www.qt.io/download](https://www.qt.io/download).
2. Open **Qt Creator** and create a new C++ project.
3. Copy the provided `main.cpp` code into the project.
4. Configure the project using `qmake` or `CMake`.
5. Build and run the project.

## Future Enhancements

- 🎛 **Real-time Audio Spectrum Visualizer** using **Qt & OpenGL**.
- 🎼 **Genre Classification** based on tempo (Pop, Rock, etc.).
- 🔊 **Microphone Streaming Support**.

## Contribution

Feel free to contribute by improving the UI, adding more audio features, or optimizing the analysis functions!

## License

This project is licensed under the **MIT License**.

