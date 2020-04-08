#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    kinect.init();
    kinect.open();
    
    ofSetBackgroundColor(255, 255, 255);
    
    colorImg.allocate(kinect.getWidth(), kinect.getHeight());
    grayImg.allocate(kinect.getWidth(), kinect.getHeight());
    backgroundGray.allocate(kinect.getWidth(),kinect.getHeight());
    backgroundCol.allocate(kinect.getWidth(),kinect.getHeight());
    grayDiff.allocate(kinect.getWidth(), kinect.getHeight());
    contoured.allocate(kinect.getWidth(), kinect.getHeight());
    
    bLearnBackground = true;
    threshold = 70;
    
    string ofGetTimestampString("%A %B %Y %R");
    
    //Timer
//    shotTimeDelta = 5000;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    line.clear();
    
    bool bNewFrame = false;
    
    kinect.update();
    bNewFrame = kinect.isFrameNew();
    blobpoints.clear();
    
    if (kinect.isFrameNew());
    
    if (kinect.isFrameNew()){
        colorImg.setFromPixels(kinect.getPixels());
    
        backgroundGray = backgroundCol;
        grayImg = colorImg;
    
        if (bLearnBackground == true){
            backgroundGray = grayImgPic;
            bLearnBackground = false;
        }
    
    grayDiff.absDiff( backgroundGray, grayImgPic);
    grayDiff.threshold(threshold);
    
    contourFinder.findContours(grayDiff, 20, (kinect.getWidth()*kinect.getHeight())/4, 1, false, true);
    }
    
    //Timer function
    
//    actualTime = ofGetElapsedTimeMillis();
//    int d = 0;
//    while (d < 10000) {
//        shotTime = ofGetElapsedTimeMillis();
//
//
//
//        d++;
//
//
//        }
//
//    if (actualTime - shotTime > shotTimeDelta) {
//        grayImgPic = grayImg;
//
//    }
    
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    backgroundCol.draw(0,kinect.getHeight(), kinect.getWidth()/4, kinect.getHeight()/4);
    backgroundGray.draw(0+(kinect.getWidth()/4), kinect.getHeight(), kinect.getWidth()/4, kinect.getHeight()/4);
    
    
    colorImg.draw(0,kinect.getHeight()+((kinect.getHeight()/4)), kinect.getWidth()/4, kinect.getHeight()/4);
    grayImg.draw(0+(kinect.getWidth()/4), kinect.getHeight()+((kinect.getHeight()/4)), kinect.getWidth()/4, kinect.getHeight()/4);
    grayImgPic.draw(0+((kinect.getWidth()/4)*2), kinect.getHeight()+(kinect.getHeight()/4), kinect.getWidth()/4, kinect.getHeight()/4);
    
    grayDiff.draw(0+((kinect.getWidth()/4)*3), kinect.getHeight()+(kinect.getHeight()/4), kinect.getWidth()/4, kinect.getHeight()/4);
    

    
    ofPushMatrix();
    if (contourFinder.nBlobs > 0){
        for (int k = 0; k < contourFinder.nBlobs; k++){
            for (int i = 0; i < contourFinder.blobs[k].pts.size(); i++){
                ofVec3f point(contourFinder.blobs[k].pts[i]);
                blobpoints.push_back(point);
            }
        }
        for (int j = 0; j < blobpoints.size(); j++) {
            line.curveTo(blobpoints[j]);
        }
        line.close();
        ofSetLineWidth(3.0);
        ofSetColor(0, 0, 0);
        line.draw();

    }
    ofPopMatrix();
    
//    ofSetColor(0, 0, 0);
            ofDrawBitmapString(ofGetTimestampString("%A %e %B %Y %R"), 0+10, kinect.getHeight()-10);
    
    
    
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'b':
            backgroundCol.setFromPixels(kinect.getPixels());
            break;
            
        case 'p':
            grayImgPic = grayImg;
//            shotTime = ofGetElapsedTimeMillis();
            
        case 'q':
            threshold++;
            break;
        
        case 'a':
            threshold--;
            break;
            
        default:
            break;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
//    switch (key) {
//        case 'p':
//            shotTime = ofGetElapsedTimeMillis();
//            break;
//
//        default:
//            break;
//    }

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
