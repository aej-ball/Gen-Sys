#pragma once

#include "ofMain.h"
#include "ofxKinect.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofxKinect kinect;
    
    ofxCvColorImage colorImg;
    ofxCvColorImage backgroundCol;
    ofxCvColorImage contoured;
    
    ofxCvGrayscaleImage grayImg;
    ofxCvGrayscaleImage grayImgPic;
    ofxCvGrayscaleImage backgroundGray;
    ofxCvGrayscaleImage grayDiff;
    
    ofxCvContourFinder contourFinder;
    
    ofPolyline line;
    
    vector<ofVec3f> blobpoints;
    
    int threshold;
    bool bLearnBackground;
    
    unsigned long actualTime, shotTime;
    unsigned int shotTimeDelta;
    
//    class Scheduler: public ofThread {
//
//    public:
//        Scheduler() {
//            timer.setPeriodicEvent(5000000000);
//            startThread();
//        }
//
//    private:
//        ofTimer timer;
//        void threadedFunction() {
//            while(isThreadRunning()) {
//                timer.waitNext();
//                grayImgPic = grayImg;
//            }
//        }
//    };
		
};
