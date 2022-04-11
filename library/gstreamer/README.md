# GStreamer

- [Installing on Linux](https://gstreamer.freedesktop.org/documentation/installing/on-linux.html?gi-language=c)
- [GStreamer Tutorials](https://gstreamer.freedesktop.org/documentation/tutorials/index.html?gi-language=c)

```
apt-get install libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libgstreamer-plugins-bad1.0-dev gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly gstreamer1.0-libav gstreamer1.0-doc gstreamer1.0-tools gstreamer1.0-x gstreamer1.0-alsa gstreamer1.0-gl gstreamer1.0-gtk3 gstreamer1.0-qt5 gstreamer1.0-pulseaudio
```

```
gcc basic-tutorial-1.c -o basic-tutorial.out `pkg-config --cflags --libs gstreamer-1.0`

gcc basic-tutorial-5.c -o basic-tutorial.out `pkg-config --cflags --libs gstreamer-video-1.0 gtk+-3.0 gstreamer-1.0`
```