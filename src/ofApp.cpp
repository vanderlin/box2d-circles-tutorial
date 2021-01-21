#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    
    // first init box2d
    box2d.init();
    
    // set the gravity
    box2d.setGravity(0, 0);
    
    // create bounds x,y,w,h
    box2d.createBounds();

    // enable mouse grabbing
    box2d.registerGrabbing();
    
}

//--------------------------------------------------------------
void ofApp::update() {
    
    if (ofGetFrameNum() % 20) {
        
        // make a shared circle
        auto circle = make_shared<ofxBox2dCircle>();
        
        // set the physics of the circle
        circle->setPhysics(1, 0.7, 0.7);
        
        // set the position and size of circle then add to the world
        circle->setup(box2d.getWorld(), ofGetWidth()/2 + ofRandom(-20, 20), ofGetHeight()/2 + ofRandom(-20, 20), ofRandom(2, 20));
        
        // add to the vector
        circles.push_back(circle);
    
        if (circles.size() > 1000) {
            circles.erase(circles.begin());
        }
    }
    
    // update every frame
    box2d.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    ofBackground(249, 220, 196);
    
    for(auto &circle : circles) {
        
        auto radius = circle->getRadius();
        auto pos = circle->getPosition();
        auto angle = circle->getRotation();
        
        ofSetColor(10);
        ofDrawCircle(pos.x, pos.y, radius);
        
        // draw crosses
        /*ofSetColor(10);
        ofPushMatrix();
        ofTranslate(pos);
        ofRotateDeg(angle);
        ofDrawLine(-radius, 0, radius, 0);
        ofDrawLine(0, -radius, 0, radius);
        ofPopMatrix();*/
        
    }
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
