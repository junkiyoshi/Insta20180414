#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofSetColor(239, 39, 39);
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	int radius = 250;
	for (int deg = 90; deg <= 270; deg += 3) {

		ofPoint point = ofPoint(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
		float noise_value = ofNoise(deg * 0.05, ofGetFrameNum() * 0.005);
		float x_param = 0;

		if (noise_value > 0.75) {
	
			x_param = ofMap(noise_value, 0.75, 1.0, 0, 200);
		}
		else if(noise_value < 0.35) {

			x_param = ofMap(noise_value, 0.35, 0.0, 0, -200);
		}

		ofDrawLine(point.x + x_param, point.y, -point.x + x_param, point.y);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}