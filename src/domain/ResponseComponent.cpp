#include "ResponseComponent.h"

ResponseComponent::ResponseComponent(const std::string& name) 
    :name(name) , mediator(nullptr){}

void ResponseComponent::setMediator(Mediator* m){
    mediator = m;
}

const std::string& ResponseComponent::getName() const {
    return name;
}