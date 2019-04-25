#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);
    // FFTのサンプル数を指定して初期化
    fft.setup(pow(2.0, 12.0));
    // GUI
    gui.setup();
    gui.add(saturation.setup("Saturation", 127, 0, 255));
}

//--------------------------------------------------------------
void ofApp::update(){
    fft.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    // float型の配列にFFT結果を格納
    vector<float> buffer;
    buffer = fft.getBins();
    
    // グラフに描画
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetLineWidth(ofGetWidth() / float(buffer.size()));
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    for (int j = 0; j < 2; j++) {
        for (int i=0; i < buffer.size(); i++) {
            // 色を指定
            float hue = ofMap(i, 0, buffer.size(), 0, 160);
            float br = ofMap(buffer[i], 0, 1, 0, 255);
            ofColor col;
            col.setHsb(hue, saturation, br);
            ofSetColor(col);
            // 右
            float rx = ofMap(i, 0, buffer.size(), ofGetWidth() / 2.0, ofGetWidth());
            ofLine(rx, -ofGetWidth()/2.0, rx, ofGetWidth()/2.0);
            float lx = ofMap(i, 0 , buffer.size(), 0, ofGetWidth() / 2.0);
            ofLine(lx, -ofGetWidth()/2.0, lx, ofGetWidth()/2.0);
        }
        ofRotateZ(90);
    }
    ofPopMatrix();
    ofEndShape();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
