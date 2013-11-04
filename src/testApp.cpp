#include "testApp.h"
#include "ofAppRunner.h"
#include "World.h"
#include "ofGraphics.h"
#include "EntityManager.h"
#include "Entity.h"
#include "TransformComponent.h"

//--------------------------------------------------------------
void testApp::setup() {

    // particles = new ParticleSystem(500);

    em = new EntityManager();
    
    for (int i = 0; i < 100; i++) {
        
        Entity e = em->createEntity();
        
        em->addComponent(e->id, new TransformComponent(rand() % 1024, rand() % 768));
        
    }
    
    
    ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void testApp::update() {
    
    
    double dt = ofGetLastFrameTime();
    
    /*
    Particle * p = particles->getParticle(1024/2,768/2, ofRandomf() * 300, ofRandomf() * 300);
    
    particles->update(dt);
    */
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    // particles->draw();
    
    EntityComponents * translation_components = em->getEntityComponents<TransformComponent>();
    
    typedef EntityComponents::iterator it_type;
    
    
    ofPushStyle();
    ofSetColor(255, 255, 255);
    ofFill();
    
    for (it_type iterator = translation_components->begin();  iterator != translation_components->end(); iterator++) {
        
        int id = iterator->first;
        TransformComponent * transform = (TransformComponent *) iterator->second;
        
        ofCircle(transform->x, transform->y, 3);
    
    }
    
    ofPopStyle();

    
    ofSetColor(255, 255, 255);
    ofDrawBitmapString(ofToString((int) ofGetFrameRate()) + " fps", 32, 52);
    //ofDrawBitmapString(ofToString(particles->used_particles.size()) + " used particles", 32, 64);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
