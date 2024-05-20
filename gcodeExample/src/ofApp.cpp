#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// Set background colour to black
	ofSetBackgroundColor(0);

	// Read gcode and convert to mesh
	gcodeFilename = "cylinder6cm.gcode";
	myGcodeReader.readPathsFromGcode(gcodeFilename);

	// Create ofMesh from the gcode path.
	// Setting the nozzleWidth and layerHeight to zero tries to infer 
	// their values from comments in the gcode
	float nozzleWidth = 0;
	float layerThickness = 0;
	int tubeResolution = 8;
	int endCapResolution = 3;
	myGcodeReader.cleanupPaths();
	myGcodeReader.convertPathsToMesh(nozzleWidth, layerThickness, tubeResolution, endCapResolution);
	std::cout << "numVertices: " << myGcodeReader.getMesh().getNumVertices() << "\n";
	std::cout << "numTriangles: " << myGcodeReader.getMesh().getNumIndices() / 3 << "\n";
	//myGcodeReader.getMesh().save("cylinder6cm.ply");

	// Setup EasyCam
	myCamera.setAutoDistance(false);
	myCamera.setPosition(vec3(0.0, 20.0, 100.0));
	myCamera.setTarget(vec3(0.0, 0.0, 0.0));
	myCamera.setNearClip(10.0f);
	myCamera.setFarClip(400.0f);

	// Setup material to use on the particle mesh
	myMeshMaterial.setDiffuseColor(ofFloatColor(0.2, 0.5, 0.7));
	myMeshMaterial.setSpecularColor(ofFloatColor(0.7, 0.7, 0.7));
	myMeshMaterial.setAmbientColor(ofFloatColor(0.1, 0.1, 0.2));
	myMeshMaterial.setShininess(50.0);

	// Setup lights
	myLight1.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
	myLight1.setSpecularColor(myLight1.getDiffuseColor());
	myLight1.setPosition(vec3(120.0, 50.0, 120.0));

	// Setup material
	myLight2.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
	myLight2.setSpecularColor(myLight2.getDiffuseColor());
	myLight2.setPosition(vec3(-120.0, 50.0, -120.0));
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	// Start drawing objects in 3D space
	ofEnableDepthTest();
	myCamera.begin();

	// Switch on the lights
	ofEnableLighting();
	myLight1.enable();
	myLight2.enable();

	// Draw the mesh
	myMeshMaterial.begin();
	ofRotateX(-90); // Tranform from gcode 3D space with z up to oF 3D space with y up
	ofTranslate(-myGcodeReader.getMidPos());
	myGcodeReader.draw();
	myMeshMaterial.end();

	// Switch off lighting
	ofDisableLighting();

	// Finish drawing objects in 3D space
	myCamera.end();
	ofDisableDepthTest();
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
