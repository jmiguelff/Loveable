#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// We load an image from our "data" folder into the ofImage:
	myImage.loadImage("Loveable_img3.jpg");
	myImage.setImageType(OF_IMAGE_GRAYSCALE);

	// Set the myCvImage from the pixels of this ofImage.
	// We fetch the ofImage's dimensions.  
	float imgWidth = myImage.getWidth();
	float imgHeight = myImage.getHeight();
	unsigned char *myImagePixels = myImage.getPixels();
	myCvImage.setFromPixels(myImagePixels, imgWidth, imgHeight);
	contourFinder.findContours(myCvImage, 1, (320 * 240) / 4, 4, false, true);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(255);

	// Draw the blobs found, highlighted with
	// rectangles.
	ofSetHexColor(0xffffff);
	myCvImage.draw(0, 240, 320, 240);
	ofDrawRectangle(320, 0, 320, 240);
	contourFinder.draw(320, 0, 320, 240);
	ofColor c(255, 255, 255);
	for (int i = 0; i < contourFinder.nBlobs; i++) {
		ofRectangle r = contourFinder.blobs.at(i).boundingRect;
		r.x += 320; r.y += 240;
		c.setHsb(i * 64, 255, 255);
		ofSetColor(c);
		ofDrawRectangle(r);
	}

	// Take it easy
	Sleep(100);
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
