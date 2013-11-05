#include "testApp.h"
#include "ofAppRunner.h"
#include "World.h"
#include "EntityManager.h"
#include "SystemManager.h"
#include "ofGraphics.h"

#include "Entity.h"
#include "TransformComponent.h"
#include "MotionComponent.h"
#include "RenderComponent.h"

#include "RenderSystem.h"
#include "MotionSystem.h"

using namespace ecs;

int randomPlusOrMinus() {
    float r = ofRandomf();
    if (r < 0) {
        return -1;
    } else {
        return 1;
    }
}

int randPlusMinus(int x) {
    return rand() % x * randomPlusOrMinus();
}

//--------------------------------------------------------------
void testApp::setup() {

    world = new World();

    EntityManager * em = world->getEntityManager();
    
    world->getSystemManager()->addSystem(new ecs::MotionSystem(world));
    world->getSystemManager()->addSystem(new ecs::RenderSystem(world));

    for (int i = 0; i < 100; i++) {
        
        Entity * e = em->createEntity();
        
        em->addComponent(e->id, new TransformComponent(rand() % 1024, rand() % 768));
        em->addComponent(e->id, new MotionComponent(randPlusMinus(100), randPlusMinus(100)));
        em->addComponent(e->id, new RenderComponent(new CircleRenderer(rand() % 5, rand() % 255, rand() % 255, rand() % 255)));

    }
    
    
    ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void testApp::update() {
    
    
    double dt = ofGetLastFrameTime();
    
    MotionSystem * ms = world->getSystemManager()->getSystem<MotionSystem>();
    
    ms->update(dt);
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    RenderSystem * rs = world->getSystemManager()->getSystem<RenderSystem>();
    rs->draw();
    
    ofSetColor(255, 255, 255);
    ofDrawBitmapString(ofToString((int) ofGetFrameRate()) + " fps", 32, 52);

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
