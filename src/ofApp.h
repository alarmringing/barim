#pragma once
#include "RtAudio/RtAudio.h"
#include "chuck.h"

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxKinectForWindows2.h"
#include "ofxBox2d.h"

#define SAMPLE float
#define MY_FORMAT RTAUDIO_FLOAT32
#define MY_SRATE 44100
#define MY_CHANNELS 2
#define PI 3.14159265358979
#define SND_BUFFER_SIZE 1024

#define GONGPATH "ckfiles/gongPlayer.ck"

class ofApp : public ofBaseApp {

public:
	void setup();
	void sporkNewChuckFile(string fileName);
	void checkHeadGong();
	void updateKinectData();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	ChucK *myChuck;
	string chuckPath;
	SAMPLE *currentAudioBuffer = NULL;
	SAMPLE *chuckOutputBuffer = NULL;
	bool useChuck = true;
	float averageVolume;

	// Kinect setup
	ofxKFW2::Device kinect;
	ofxKinectForWindows2::Data::Body previousBody;
	ofxKinectForWindows2::Data::Body currentBody;

	// Gong specific
	float lastGongTime = 0;
	float gongMinInterval = 0.5;
	float gongTriggerVelocity = -0.7;

	ofxPanel gui;
	ofxLabel fps;

	float dayProgressionSpeed;
};
