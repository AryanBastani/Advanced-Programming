#ifndef __WIRE_HPP__
#define __WIRE_HPP__
#include<iostream>
#include<string>

#include"Exeptions.hpp"

const std::string HAS_NOT_INPUT = ""; 
const int Z_VALUE = -1;
const int ZERO_VALUE = 0;
const int ONE_VALUE = 1;

struct Wire{
        std::string inputId = HAS_NOT_INPUT; 
        int value = Z_VALUE;

        Wire* clone(){
                Wire* newWire = new Wire();
                newWire->inputId = inputId;
                newWire->value = value;

                return newWire;
        }
};
#endif