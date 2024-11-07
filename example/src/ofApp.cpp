#include "ofApp.h"

#include "boolinq/boolinq.h"

struct Man {
    std::string name;
    int age;
};

using namespace boolinq;

//--------------------------------------------------------------
void ofApp::setup(){
    ofLogToConsole();

	int src[] = {1,2,3,4,5,6,7,8};
	auto dst = from(src).where( [](int a) { return a % 2 == 1; })      // 1,3,5,7
                    .select([](int a) { return a * 2; })           // 2,6,10,14
                    .where( [](int a) { return a > 2 && a < 12; }) // 6,10
                    .toStdVector();

	ofLogNotice("ofApp") << "dst: " << ofToString(dst);
    
    Man src2[] = {
        {"Kevin",14},
        {"Anton",18},
        {"Agata",17},
        {"Terra",20},
        {"Layer",15},
    };

    auto dst2 = from(src2).where( [](const Man & man) { return man.age < 18; })
                        .orderBy([](const Man & man) { return man.age; })
                        .select( [](const Man & man) { return man.name; })
                        .toStdVector();

    ofLogNotice("ofApp") << "dst2: " << ofToString(dst2);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
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
