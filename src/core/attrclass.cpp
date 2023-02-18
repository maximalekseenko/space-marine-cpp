#include "attrclass.h"

#include <vector>
#include <stdexcept>
#include <iterator>



attribute::attribute(int __key, int __value, bool isdefault, bool isstatic){
    this->key = __key;
    this->value = __value;
    this->isdefault = isdefault;
    this->isstatic = isstatic;
}


void attribute::Set(int __value){

    // cannot set if static
    if (this->isstatic){
        throw std::runtime_error("cannot set static attribute");
    }

    // set
    this->value = __value;
}

int attribute::Get(){
    return this->value;
}

int attribute::GetKey(){
    return this->key;
}



void attrClass::NewAttr(int __key, int __value){

    // cannot create if already exists
    if (std::find_if(this->attributes.begin(), this->attributes.end(), [__key](attribute _attr){return _attr.GetKey() == __key;}) != this->attributes.end()){
        throw std::runtime_error( "cannot create new attribute that alreaby exists.");
    }

    // create new
    this->attributes.push_back(attribute(__key, __value));
}

void attrClass::SetAttr(int __key, int __value){
    
    // find attribute
    std::__1::vector<attribute>::iterator __attr_iter = std::find_if(this->attributes.begin(), this->attributes.end(), [__key](attribute _attr){return _attr.GetKey() == __key;});

    // not found
    if (__attr_iter == this->attributes.end()){
        throw std::runtime_error( "cannot edit attribute that does not exists.");
    }

    // edit
    __attr_iter.base()->Set(__value);
}

int attrClass::GetAttr(int __key){
    
    // find attribute
    std::__1::vector<attribute>::iterator __attr_iter = std::find_if(this->attributes.begin(), this->attributes.end(), [__key](attribute _attr){return _attr.GetKey() == __key;});

    // not found
    if (__attr_iter == this->attributes.end()){
        throw std::runtime_error( "cannot get attribute that does not exists.");
    }

    // get
    return __attr_iter.base()->Get();
}

void attrClass::RemAttr(int __key){
    
    // find attribute
    std::__1::vector<attribute>::iterator __attr_iter = std::find_if(this->attributes.begin(), this->attributes.end(), [__key](attribute _attr){return _attr.GetKey() == __key;});

    // not found
    if (__attr_iter == this->attributes.end()){
        throw std::runtime_error( "cannot remove attribute that does not exists.");
    }

    // remove
    this->attributes.erase(__attr_iter);
}
